import re
import sys
import time
from termcolor import colored

try:
    import islpy as isl
except ImportError, e:
    print e
    print "pip install ispy"
    sys.exit()

import iscc
import convert_loop
import imperf_tile
import relation_util
import Dependence
import clanpy
import tiling_v3
import copyconstr

ctx = isl.Context()


def GetBounds(lines, st_line, BLOCK2, simpl):
    for_level = 0
    lev = len(BLOCK2)

    bounds=[]
    for i in range(st_line-1,0,-1):
        line = lines[i]
        if 'endfor' in line:   # not my loop
            for_level = for_level - 1
        else:
            if 'for' in line:
                if(for_level < 0):  # not my loop
                    for_level = for_level + 1
                else:
                    items = line.split(' ')
                    step = 1
                    if 'by' in line:
                        step = items[7]

                    lev = lev - 1

                    if(not simpl):
                        bounds.insert(0, {'var' : items[1], 'lb' : items[3], 'ub' : items[5], 'step' : step, 'loop' : line})
                    else:
                        if step == '-1':
                            bounds.insert(0, {'var': items[1], 'lb': items[3] + ' + ' +  BLOCK2[lev], 'ub': items[5] + ' - ' +  BLOCK2[lev] , 'step': step, 'loop': line})
                        else:
                            bounds.insert(0, {'var': items[1], 'lb': items[3] + ' - ' + BLOCK2[lev], 'ub': items[5] + ' + ' + BLOCK2[lev], 'step': step, 'loop': line})




    return bounds
############################################################

def MakeTile(st, vars, sym_exvars, symb, B):

    TILE = '['+','.join(symb + sym_exvars) +'] -> { [' + ','.join(vars) + ',' + str(st.petit_line) + '] : '

    deeploop =  len(st.original_iterators)


    for i in range(0, len(vars)):
        if(i < deeploop):
            tile_part = ''
            if(st.bounds[i]['step'] == 1):
                tile_part +=  st.bounds[i]['lb'] + ' + ' + B[i] + '*' + sym_exvars[i] + ' <= ' + vars[i] + ' <= '
                tile_part +=  B[i] + '*(1+' + sym_exvars[i] + ') + ' + st.bounds[i]['lb'] + '-1, ' + st.bounds[i]['ub']
                tile_part +=  ' && ' + sym_exvars[i] + ' >= 0 && '
            if (st.bounds[i]['step'] == '-1'):
                tile_part += st.bounds[i]['lb'] + ' - ' + B[i] + '*' + sym_exvars[i] + ' >= ' + vars[i] + ' >= -'
                tile_part += B[i] + '*(1+' + sym_exvars[i] + ') + ' + st.bounds[i]['lb'] + '+1, ' + st.bounds[i]['ub']
                tile_part += ' && ' + sym_exvars[i] + ' >= 0 && '

            TILE += tile_part
        else:
            TILE +=  sym_exvars[i] + ' = 0 && ' + vars[i] + ' = 0 && '

    TILE += ' 1=1 }'

    print TILE


    return TILE

############################################################

def MakeCustomLex(sym_exvars, sym_exvars_p, direct, size, eq):

    if size == 0:
        return ''

    constr = ' ( '
    part = ''
    comparator = ' > '   # LT

    if(direct == 'GT'):
        comparator = ' < '    # GT

    for i in range(0, size):
        part += '('
        for j in range(0, i):
            part += sym_exvars[j] + ' = ' + sym_exvars_p[j] + ' && '
        part += sym_exvars[i] + comparator + sym_exvars_p[i] + ' ) or '

    if(eq):
        part += ' ('
        for i in range(0, size):
            part += sym_exvars[i] + ' = ' + sym_exvars_p[i] + ' && '
        part = part[:-4] + ') '
    else:
        part = part[:-3]  # delete last or

    constr += part + ') && '
    return constr
############################################################

def fix_scat(arr, l):
    arr = arr[:l]
    arr = arr + ['0']*(l - len(arr))
    return arr

############################################################

def ReplaceB(tile, BLOCK):
    for i in range(0,10):
        tile = tile.replace('b' + str(i), BLOCK[i])
    return tile

def CompareScat(arr1, arr2, deep):
    l = len(arr1)
    if(len(arr2) < l):
        l = len(arr2)
    if (l > deep):
        l = deep
    for i in range(0,l):
        if(arr1[i] != arr2[i]):
            return i
    return l

def DebugPrint(label, arr, sts):
    print colored(label, 'green')
    for i in range(0, len(sts)):
        print colored(str(sts[i].petit_line) + ':\t', 'yellow') + str(arr[i])

############################################################

def tile(plik, block, permute, output_file="", L="0", SIMPLIFY="False", perfect_mode = False, parallel_option = False, rplus_mode = ''):

    print ''
    print colored('/\__  _\ /\  == \   /\  __ \   /\  ___\   /\  __ \   ', 'green')
    print colored('\/_/\ \/ \ \  __<   \ \  __ \  \ \ \____  \ \ \/\ \  ', 'green')
    print colored('   \ \_\  \ \_\ \_\  \ \_\ \_\  \ \_____\  \ \_____\ ', 'green')
    print colored('    \/_/   \/_/ /_/   \/_/\/_/   \/_____/   \/_____/ ', 'green')
    print ''
    print '       An Automatic Parallelizer and Optimizer'
    print ' based on the TRansitive ClOsure of dependence graph'
    print '              traco.sourceforge.net               '
    print ''

    DEBUG = True
    AGGRESSIVE_SIMPLIFY = False # TODO simpl_ub


    LPetit = "tmp/tmp_petit"+L+".t"

    BLOCK = block.split(',')

    for i in range(len(BLOCK),10):
        BLOCK.append(BLOCK[len(BLOCK)-1])

    BLOCK2 = [0,6,6]
    # BLOCK2 = BLOCK


    linestring = open(plik, 'r').read()
    lines = linestring.split('\n')

    if AGGRESSIVE_SIMPLIFY:
        petit_loop = convert_loop.convert_loop(lines, BLOCK2)
        BLOCK2 = map(str, BLOCK2)
    else:
        petit_loop = convert_loop.convert_loop(lines)



    file = open(LPetit, 'w')

    imperf = 0
    endloop = 0
    startloop = 0
    for line in petit_loop:
        #sprawdz przy okazji jaka petla idealnie czy nie
        if 'for' in line and not 'endfor' in line:
            if startloop == 2:
                imperf = 1
            startloop = 1
        else:
            if startloop == 1:
                startloop = 2
        if 'endfor' in line:
            endloop = 1
        if endloop == 1 and 'endfor' not in line and not line.isspace() and line != '':
            imperf = 1

        file.write(line + '\n')

    file.close()


    start = time.time()
    loop = Dependence.Kernel_Loop(LPetit)

    loop.Load_Deps()
    loop.Load_instrukcje()
    loop.Preprocess('0')
    loop.Get_Arrays()
    end = time.time()
    elapsed = end - start


    print "Dependence analysis: time taken: ", elapsed, "seconds."

    print colored('R', 'green')
    print loop.isl_rel

    cl = clanpy.ClanPy()
    cl.loop_path = plik
    cl.Load()

    ##################################
    # move to clanpy
    # combine clan with Dependence
    arr = map(int, loop.dane)
    arr = sorted(list(set(arr)))
    i=0
    for i in range(0, len(cl.statements)):
        cl.statements[i].petit_line = arr[i]
        cl.statements[i].bounds = GetBounds(petit_loop, cl.statements[i].petit_line, BLOCK2, AGGRESSIVE_SIMPLIFY)
        i=i+1


    ############################################################

    ### R^+

    isl_rel = loop.isl_rel

    start = time.time()

    # **************************************************************************

    exact_rplus = '-1'
    islrp = True

    if(rplus_mode == 'iterate'):
        islrp = False

    isl_relclosure = isl_rel

    if islrp:
        isl_relclosure = isl_rel.transitive_closure()
        exact_rplus = isl_relclosure[1]
        isl_relclosure = isl_relclosure[0]
    else:
        isl_relclosure = relation_util.oc_IterateClosure(isl_rel)
        exact_rplus = True

    isl_relplus = isl_relclosure
    end = time.time()
    elapsed = end - start
    print "Transitive closure: time taken: ", elapsed, "seconds."

    isl_ident = isl_rel.identity(isl_rel.get_space())

    if (DEBUG and 1==0):
        print 'R+'
        print isl_relclosure

    #isl_relclosure = rpp
    if (DEBUG):
        color = 'red'
        if(exact_rplus):
            color = 'yellow'
        print colored("!! exact_rplus " + str(exact_rplus), color)

    isl_relclosure = isl_relclosure.union(isl_ident).coalesce()  # R* = R+ u I

    if (DEBUG):
        print colored("R*", 'green')
        print isl_relclosure


    # **************************************************************************
    start = time.time()

    B = (["b%d" % i for i in range(0,loop.maxl)])

    for st in cl.statements:
        if (len(st.original_iterators) == loop.maxl):
            vars = st.original_iterators
            break

    # TODO to make abstract variubles bounds with variables must be also corrected

    sym_exvars = []
    sym_exvars_p = []
    for v in vars:
        sym_exvars.append(v*2)
        sym_exvars_p.append(v * 2 + 'p')

    if (DEBUG and 1==0):
        print sym_exvars
        print vars

    isl_symb = isl_rel.get_var_names(isl.dim_type.param)

    BLOCK = block.split(',')

    for i in range(len(BLOCK),10):
        BLOCK.append(BLOCK[len(BLOCK)-1])

    # **************************************************************************

    TILE = []       #isl
    TILE_STR = []   #string

    for st in cl.statements:
        tile =  MakeTile(st, vars, sym_exvars, isl_symb, B)
        tile = ReplaceB(tile, BLOCK)
        TILE_STR.append(tile)
        tile = isl.Set(tile)
        TILE.append(tile)

    if (DEBUG):
        DebugPrint('TILE', TILE, cl.statements)

    # **************************************************************************

    TILE_LT = []
    TILE_GT = []


    for i in range(0, len(cl.statements)):
        TILE_LT_I = ''
        TILE_GT_I = ''
        for j in range(0, len(cl.statements)):

            l = CompareScat(cl.statements[i].scatering, cl.statements[j].scatering, len(vars))

            tile_j = TILE_STR[j]

            PARTS = tile_j.split(':')
            for k in range(0, len(sym_exvars)):
                PARTS[1] = PARTS[1].replace(sym_exvars[k], sym_exvars_p[k])

            PARTS[1] = PARTS[1].replace('}', ')}')


            lex_s_lt = MakeCustomLex(sym_exvars, sym_exvars_p, 'LT', l, cl.statements[i].petit_line > cl.statements[j].petit_line)
            lex_s_gt = MakeCustomLex(sym_exvars, sym_exvars_p, 'GT', l, cl.statements[i].petit_line < cl.statements[j].petit_line)


            join_LT = ':  exists  ' + ','.join(sym_exvars_p) + ' : ( ' + lex_s_lt
            join_GT = ':  exists  ' + ','.join(sym_exvars_p) + ' : ( ' + lex_s_gt

            TILE_LT_IJ = PARTS[0] + join_LT + PARTS[1]
            TILE_GT_IJ = PARTS[0] + join_GT + PARTS[1]


            TILE_LT_IJ = isl.Set(TILE_LT_IJ)
            TILE_GT_IJ = isl.Set(TILE_GT_IJ)

            if(j==0):
                TILE_LT_I = TILE_LT_IJ
                TILE_GT_I = TILE_GT_IJ
            else:
                TILE_LT_I = TILE_LT_I.union(TILE_LT_IJ).coalesce()
                TILE_GT_I = TILE_GT_I.union(TILE_GT_IJ).coalesce()



        TILE_LT.append(TILE_LT_I)
        TILE_GT.append(TILE_GT_I)

    if(DEBUG):
        DebugPrint('TILE_LT', TILE_LT, cl.statements)
        DebugPrint('TILE_GT', TILE_GT, cl.statements)


# **************************************************************************

    TILE_ITR = []

    for i in range(0, len(cl.statements)):
        TILE_ITRI = TILE[i].subtract(TILE_GT[i].apply(isl_relclosure)).coalesce()
        TILE_ITR.append(TILE_ITRI)

    if(DEBUG):
        DebugPrint('TILE_ITR', TILE_ITR, cl.statements)

# **************************************************************************

    TVLD_LT = []

    for i in range(0, len(cl.statements)):
        TVLD_LTI = (TILE_LT[i].intersect(TILE_ITR[i].apply(isl_relclosure))).subtract(TILE_GT[i].apply(isl_relclosure)).coalesce()
        TVLD_LT.append(TVLD_LTI)

    if(DEBUG):
        DebugPrint('TVLD_LT', TVLD_LT, cl.statements)

# **************************************************************************

    TILE_VLD = []

    for i in range(0, len(cl.statements)):
        TILE_VLDI = TVLD_LT[i].union(TILE_ITR[i]).coalesce()
        if(SIMPLIFY):
            TILE_VLDI = imperf_tile.SimplifySlice(TILE_VLDI)
        TILE_VLD.append(TILE_VLDI)

    if (DEBUG):
        DebugPrint('TILE_VLD', TILE_VLD, cl.statements)

# **************************************************************************

    TILE_VLD_EXT = []

    Rapply = tiling_v3.GetRapply(vars, sym_exvars, ','.join(isl_symb + sym_exvars) + ',')

    for i in range(0, len(cl.statements)):
        TILE_VLD_EXTI = tiling_v3.Project(TILE_VLD[i].apply(Rapply).coalesce(), sym_exvars)

#####################################################################################################################
        if AGGRESSIVE_SIMPLIFY:

            cor_set = ''
            if (len(isl_symb) > 0):
                cor_set = '[' + ','.join(isl_symb) + '] -> '
            else:
                cor_set = ''

            cor_set = cor_set + '{[' + ','.join(sym_exvars) + ',' + ','.join(vars) + ',' + 'v] : '

            for k in range(0,i+1):
                for j in range(0, len(cl.statements[k].bounds)):
                    compar = ' <= '
                    add1 = ' - '
                    add2 = ' + '
                    if cl.statements[k].bounds[j]['step'] == '-1':
                        add1 = ' + '
                        add2 = ' - '
                        compar = ' >= '
                    cor_set = cor_set + vars[j] + compar + cl.statements[k].bounds[j]['ub'] + add1 + BLOCK2[j] + " && "
                    cor_set = cor_set + cl.statements[k].bounds[j]['lb'] + add2 + BLOCK2[j] +  compar +  vars[j] +  " && "

                cor_set = cor_set + "("
                cor_set = cor_set + " v = " + str(cl.statements[i].petit_line) + " "
                cor_set = cor_set + ")}"

                print cor_set

                cor_set = isl.Set(cor_set)

                print '**************************'

                TILE_VLD_EXTI = TILE_VLD_EXTI.intersect(cor_set)
#####################################################################################################################



        TILE_VLD_EXT.append(TILE_VLD_EXTI)


    if (DEBUG):
        DebugPrint('TILE_VLD_EXT', TILE_VLD_EXT, cl.statements)

# **************************************************************************

# TIME TO SCATTER - TO HONOUR ORDER OF STATEMENTS IN IMPERFECTLY NESTED LOOPS

    RMaps = []

    for i in range(0, len(cl.statements)):
        RMap = '{'
        for j in range(0, i+1):
            RMap =  RMap +  '[' + ','.join(sym_exvars + vars) + ',' + str(cl.statements[j].petit_line) + '] -> ['

            scati = fix_scat(cl.statements[i].scatering, loop.maxl)
            scatj = fix_scat(cl.statements[j].scatering, loop.maxl)

            #TODO jesli -1 wszedzie to do Rsched
            vvars = vars[:]  # minus adding
            for k in range(0, len(cl.statements[j].bounds)):
                if cl.statements[j].bounds[k]['step'] == '-1':
                    vvars[k] = '-' + vvars[k]

            combo = [x for t in zip(scati + scatj, sym_exvars + vvars) for x in t]  # obled

            RMap = RMap + ','.join(combo) + ',' + str(cl.statements[j].petit_line) + ']; '
            # normalize  j

        RMap = RMap[:-2] + '}'
        Rmap = isl.Map(RMap)
        RMaps.append(Rmap)

    if (DEBUG):
        DebugPrint('RMaps', RMaps, cl.statements)


    # **************************************************************************

    for i in range(0, len(cl.statements)):
        TILE_VLD_EXT[i] = TILE_VLD_EXT[i].apply(RMaps[i]).coalesce()

    if (DEBUG):
        DebugPrint('TILE_VLD_EXT after Map', TILE_VLD_EXT, cl.statements)


    TILE_VLD_EXT_union = TILE_VLD_EXT[0]

    for i in range(1, len(cl.statements)):
        TILE_VLD_EXT_union = TILE_VLD_EXT_union.union(TILE_VLD_EXT[i]).coalesce()

    if (DEBUG):
        print colored('TILE_VLD_EXT to CodeGen', 'green')
        print TILE_VLD_EXT_union

# **************************************************************************

    # Optional Schedule

    s = ','.join(["i%d" % i for i in range(1, loop.maxl*4+2)])
    in_ = s.split(',')

    symb = ''
    if(len(isl_symb) > 0):
        symb += '['+ ','.join(isl_symb) + ']' + '->'

    RSched = symb + '{[' + s + '] -> ['

    RValid = RSched



    #s = s.replace('i2', 'i2+i4')
    #s = s.replace('i8', '-i8')

    # ToDo i8 na -i8

    RSched += s + '] : '

    RSched = RSched + copyconstr.GetConstrSet(in_, TILE_VLD_EXT_union) + "}"


    print 'RSCHEDULE'
    print RSched

    Rsched = isl.Map(RSched)

    # **************************************************************************

    print 'VALIDATION CHECKING '
    s_in = ','.join(["i%d" % i for i in range(1, loop.maxl * 4 + 2)])
    sout = ','.join(["i%d'" % i for i in range(1, loop.maxl * 4 + 2)])
    out_ = sout.split(',')

    i1 = in_[2*loop.maxl+1:4*loop.maxl+1:2] + [in_[loop.maxl * 4 ]]
    i2 = out_[2 * loop.maxl + 1:4 * loop.maxl + 1:2] + [in_[loop.maxl * 4]]

    RValid += sout + '] : '

    DomR = isl_rel.domain()

    RValid += copyconstr.GetConstrSet(i1, DomR) + ' && ' + copyconstr.GetConstr(i1, i2, isl_rel)
    print '..',


    s_in_ex = ','.join(["ex%d" % i for i in range(1, loop.maxl * 4 + 2)])
    s_out_ex = ','.join(["ex%d'" % i for i in range(1, loop.maxl * 4 + 2)])
    ex_sin = s_in_ex.split(',')
    ex_sout = s_out_ex.split(',')

    RValid += ' && exists ' + s_in_ex + ',' + s_out_ex +  ' : ('

    RValid += ' ( ' + tiling_v3.CreateLex(ex_sin, ex_sout) + ' ) && '

    RValid += ' ( ' + copyconstr.GetConstr(in_, ex_sin, Rsched) + ' ) && '
    RValid += ' ( ' + copyconstr.GetConstr(out_, ex_sout, Rsched) + ' ) '

    RValid += ' ) }'
    print '..',
    print RValid
    RValid = isl.Map(RValid).coalesce()
    print '..'

    if(RValid.is_empty()):
        print colored('*** VALIDATION OK ***', 'green')
    else:
        print colored('*** VALIDADION FAILED ***', 'red')
        sys.exit(0)


    #for st in cl.statements:
    #    print st.domain_map

    # czy wszystkie z domain sa w TVLD_EXT

    # I nalezy do TVLD_EXT and exists i,j,v i  nalezy do domain_map i   i,j,v != I


    #sys.exit(0)

    # dodatkowo  ii <> ii' && i1 = i2 && ii,i1 ,    ii',i2 nalezy do VLDEXTY exists

# **************************************************************************
    #### DISCOVER PARALLELISM -- empty

    # ii, jj -> ii, jj' : not  jj = jj'
    print colored('Parallelism searching', 'green')

    s = ','.join(["i%d" % i for i in range(1, loop.maxl*4+2)])
    in_ = s.split(',')
    sprim = ','.join(["i%d'" % i for i in range(1, loop.maxl*4+2)])
    out_ = sprim.split(',')

    Rel_base = '{[' + s + '] -> [' + sprim + '] :   '

#i1 = domain R 12 = R(i1)   ii,i1 nalezy do VLD_EXT i'i',i2 nalezy do VLDEXT i ogr. ponizej np  ii2 <> ii2' ii1 = ii1'

    for i in range(0,loop.maxl*4,2):
        print i,
        Rel = Rel_base
        tmp = ''
        for j in range(0,i):
            tmp += in_[j] + ' = ' + out_[j] + ' && '

        if(i > 0):
            tmp += ' not ( ' +  in_[j+1] + ' = ' + out_[j+1] + '  && ' + in_[j+2] + ' = ' + out_[j+2] + ' )  '

        Rel += tmp + ' }'
        print Rel
        Rel = isl.Map(Rel)
        # print Rel
        Rel = Rsched.intersect(Rel)
        if(Rel.is_empty()):
            print 'found!'
            break
        else:
            print 'no!'




    sys.exit(0)

    end = time.time()
    elapsed = end - start
    print "Algorithm: time taken: ", elapsed, "seconds."

# **************************************************************************

    vars = map(str, vars)

    start = time.time()
    ast = 1
    if (ast == 1):
        loop_x = iscc.isl_ast_codegen_map(Rsched)
    else:
        loop_x = iscc.iscc_communicate("L :=" + str(Rsched) + "; codegen L;")

    lines = loop_x.split('\n')

    loop_str = []

    for line in lines:
        if line.endswith(');'):
            tab = imperf_tile.get_tab(line)
            line = line.replace(' ', '')
            line = line[:-2]
            line = line[1:]

            arr = line.split(',')

            petit_st = arr[4*loop.maxl]

            s = ''

            for i in range(0,len(cl.statements)):
                if(cl.statements[i].petit_line == int(petit_st)):   # st.petit_line
                    s = cl.statements[i].body


            for i in range(0, len(vars)):        # todo oryginal iterators for loops with mixed indexes
                subt = arr[2 * loop.maxl + 2 * i + 1]
                if (('+' in subt) or ('-' in subt)):
                    subt = '(' + subt + ')'
                s = re.sub(r'\b'+vars[i]+r'\b', subt, s)



            loop_str.append(tab + s)

        else:
            line = line.replace('for (int', 'for(')
            loop_str.append(line)

    loop_str = '\n'.join(loop_str)
    end = time.time()
    elapsed = end - start
    print "Code Generation: time taken: ", elapsed, "seconds.\n\n"

    print loop_str