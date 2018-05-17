import os, glob
import re
import sys
import time
from termcolor import colored

import numpy
try:
    import islpy as isl
except ImportError, e:
    print e
    print "pip install ispy"
    sys.exit()

import convert_loop
import Dependence
import clanpy
import tiling_v5
import iscc
import sched_parser


def MakesSpaceConstr(st, vars, sym_exvars, symb, B, i):

    tile_part = ' && '
    #    if(st.bounds[i]['step'] == 1 or st.bounds[i]['step'] == '1'):
    tile_part +=  st.bounds[i]['lb'] + ' + ' + B[i] + '*' + sym_exvars[i] + ' <= ' + vars[i] + ' <= '
    tile_part +=  B[i] + '*(1+' + sym_exvars[i] + ') + ' + st.bounds[i]['lb'] + '-1, ' + st.bounds[i]['ub']
    tile_part +=  ' && ' + sym_exvars[i] + ' >= 0 }'
    return tile_part



def tile(plik, block, permute, output_file="", L="0", SIMPLIFY="False", perfect_mode = False, parallel_option = False, rplus_mode = '', cpus=2):

    print ''
    print colored('/\__  _\ /\  == \   /\  __ \   /\  ___\   /\  __ \   ', 'green')
    print colored('\/_/\ \/ \ \  __<   \ \  __ \  \ \ \____  \ \ \/\ \  ', 'green')
    print colored('   \ \_\  \ \_\ \_\  \ \_\ \_\  \ \_____\  \ \_____\ ', 'green')
    print colored('    \/_/   \/_/ /_/   \/_/\/_/   \/_____/   \/_____/ ', 'green')
    print ''
    print '      An Automatic Parallelizer and Optimizer'
    print 'based on the '+colored('TRA','green')+'nsitive '+colored('C', 'green')+'l'+colored('O', 'green')+'sure of dependence graphs'
    print '             traco.sourceforge.net               '
    print ''
    print 'TIME SPACE TILING Module'


    LPetit = "tmp/tmp_petit"+L+".t"

    BLOCK = block.split(',')
    BLOCK2 = BLOCK

    for i in range(len(BLOCK),10):
        BLOCK.append(BLOCK[len(BLOCK)-1])


    linestring = open(plik, 'r').read()
    lines = linestring.split('\n')

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
    loop = Dependence.Kernel_Loop(LPetit,1)

    loop.Load_Deps()
    loop.Load_instrukcje()
    loop.PreprocessPet()
    loop.Get_Arrays()
    end = time.time()
    elapsed = end - start


    print "Dependence analysis: time taken: ", elapsed, "seconds."

    print colored('R', 'green')
    print loop.isl_rel

    isl_symb = loop.Deps[0].Relation.get_var_names(isl.dim_type.param)

    symb_prefix = ''
    if len(isl_symb) > 0:
        symb_prefix = '[' + ','.join(isl_symb) + '] -> '

    cl = clanpy.ClanPy()
    cl.loop_path = plik
    cl.Load()


    arr = map(int, loop.dane)
    arr = sorted(list(set(arr)))
    for i in range(0, len(cl.statements)):
        cl.statements[i].petit_line = arr[i]
        cl.statements[i].bounds = tiling_v5.GetBounds(petit_loop, cl.statements[i].petit_line, BLOCK2, 0)
        print cl.statements[i].scatering



    for i in range(0, len(cl.statements)):
        cl.statements[i].domainpet = isl.Set(symb_prefix + ' { S'+ str(cl.statements[i].petit_line) +'[' + ','.join(cl.statements[i].original_iterators) +'] : ' + cl.statements[i].domain + '}')
        #print cl.statements[i].domainpet

    IS = isl.UnionSet(str( cl.statements[0].domainpet))
    for i in range(1, len( cl.statements)):
        IS = IS.union(cl.statements[i].domainpet)
        IS = IS.coalesce()

    print colored('IS', 'green')
    print IS


    #isl schedule
    text = 'R:= ' + str(loop.isl_rel) + '; IS := ' + str(IS) + '; schedule IS respecting R minimizing R;'

    print colored('ISL output', 'green')

    sched_dump = iscc.iscc_communicate(text)

    print sched_dump

    lines = sched_dump.split('\n')
    sched_maps = sched_parser.parse(lines, cl, symb_prefix)


    print colored('ISL schedules', 'green')

    for m in sched_maps:
        print m

    SCHED = isl.UnionMap(str(sched_maps[0]))
    for i in range(1, len(sched_maps)):
        SCHED = SCHED.union(sched_maps[i])
        SCHED = SCHED.coalesce()

    print colored('SCHED', 'green')
    print SCHED

    #print colored('deltas R', 'green')

    # SPACE

    # wykryj liczbe na razie globalnie


    D = loop.isl_rel.deltas()
    spaces_num = sys.maxint

    for i in range(0, len(cl.statements)):
        depth = len(cl.statements[i].original_iterators)
        nums = 0
        for j in range(0, depth):
            TEST = '{ S' + str(cl.statements[i].petit_line) + '[' + ','.join(cl.statements[i].original_iterators) + '] : ' + cl.statements[i].original_iterators[j] + '< 0 }'
            TEST = isl.Set(TEST)

            TEST = D.intersect(TEST)
            if(TEST.is_empty()):
                nums = nums + 1
            else:
                break  # sa ujemne
        #print nums
        if (nums < spaces_num):
            spaces_num = nums

    print  colored('SPACES NUMBER', 'green')
    print  spaces_num

    # vars

    vars = []
    sym_exvars = []

    for st in cl.statements:
        if (len(st.original_iterators) == loop.maxl):
            vars = st.original_iterators
            break

    for v in vars:
        sym_exvars.append(v * 2)

    ##################################

    SPACES = {}

    for st in cl.statements:
        tmpspaces = []
        for i in range(0, spaces_num):
            space = st.domainpet
            space = space.insert_dims(isl.dim_type.param, 0, 1)
            space = space.set_dim_name(isl.dim_type.param, 0, sym_exvars[i])
            space = str(space)
            space = space.replace('}', MakesSpaceConstr(st, vars, sym_exvars, isl_symb, BLOCK, i))
            space = isl.Set(space)

            tmpspaces.append(space)
            print space

        SPACES["S" + str(st.petit_line)] = tmpspaces

    ##################################

    sched_maps_i = sched_maps  #SCHED_1 SCHED_2
    TIMES = []

    for i in range(0, len(sched_maps_i)):
        sched_maps_i[i] = sched_maps_i[i].fixed_power_val(-1).coalesce()
        TIMES.append(sched_maps_i[i])
        TIMES[i] = TIMES[i].insert_dims(isl.dim_type.param, 0, 1)
        TIMES[i] = TIMES[i].set_dim_name(isl.dim_type.param, 0, 'c')
        TIMES[i] = TIMES[i].insert_dims(isl.dim_type.param, 0, 1)
        TIMES[i] = TIMES[i].set_dim_name(isl.dim_type.param, 0, 'i0')
        tmp = str(TIMES[i])
        tmp = tmp.replace('}', ' && 16c<=i1<=16*(c+1)-1 && i0=i0'' }')
        print tmp
        TIMES[i] = isl.Map(tmp).range()

    print colored("SCHED_1:=SCHED^-1", 'green')

    for s in sched_maps_i:
        print s


    print colored("TIME", 'green')

    for s in TIMES:
        print s

    ######################################### TIMES experimental code