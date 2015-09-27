import convert_loop
import convert_loop
import functions
import gen
import subprocess
import re
import sys
import glob, os
import shutil
import loop_tools
import priv_engine
import time
import os.path
import iscc
import tiling_schedule
import correct
import math
import scc
from pygraph.algorithms.accessibility import mutual_accessibility
from pygraph.algorithms.cycles import find_cycle
from multiprocessing import Pool

import imperf_tile
import test_isl

import Dependence


from CPython import codegen


try:
    import islpy as isl
except ImportError, e:
    print e
    print "pip install ispy"
    sys.exit()


# nowosc isl w pythonie do testow

ctx = isl.Context()


schedule_mode = 0
maxl = 0   # ile gniazd jest w petli...

# TILE1 -> TILE_ITR
# TILE2 -> TVLD_LT
# TILE' -> TILE_VLD
# TILE'' -> TILE_VLD_EXT


DEBUG = False
_debug_ = True

INNY = True

# add block to upper bounds to simplify tiled code
simpl_ub = False



def duplicates(lst, item):
    return [i for i, x in enumerate(lst) if x == item]

def CreateLex(array1, array2):
    n = len(array1)
    lex = "("

    for i in range(0,n):
        if(lex != "("):
            lex = lex + " || ("
        for j in range(0,i):
            lex = lex + array1[j] + " = " + array2[j] + " && "
        lex = lex + array1[i] + " > " + array2[i]
        if(i>0):
            lex = lex + ")"
        
    return lex + ")"   
        
        
def Constr_Dowolny(vars, sym_exvars, stuff, BLOCK, i,iloczyn, j):  
    
    return stuff[j]['lb'] + " <= " + vars[i] + " <= " +  stuff[j]['ub'] + " && " + iloczyn  + " <= " +  stuff[j]['ub'] + " && "

def Constr_Przed(vars, sym_exvars, stuff, BLOCK, i, iloczyn,j):  
    return stuff[j]['lb'] + " <= " + vars[i] + " <= " +  iloczyn + "-1 && " + iloczyn + " <= " +  stuff[j]['ub'] + " && "
      

def Constr_Wbloku(vars, sym_exvars, stuff, BLOCK, i, iloczyn, j):
    return iloczyn + ","+ stuff[j]['lb'] +" <= " + vars[i] + " <= " +  stuff[j]['ub'] + "," + iloczyn + "+" + BLOCK[i] + "-1 && "



def Constr_Za(vars, sym_exvars, stuff, BLOCK, i, iloczyn, j):  
    return iloczyn + "+" + BLOCK[i] +" <= " + vars[i] + " <= " +  stuff[j]['ub'] + " && "
 
        
# zaleznosci w relacjach
def Constraint(vars, sym_exvars, stuff, BLOCK, dane,par_vars,par_tiling):
    s = ""
    for i in range(0,dane["nest"]): # len(vars)
#        s = s + sym_exvars[i] + '<= ' + vars[i] + '<= ' + sym_exvars[i] + '+' + str(BLOCK[i]) + '- 1, ' + stuff[i]['ub'] + ' && ';
##       s = s + sym_exvars[i] + '*' + str(BLOCK[i]) +  ',' + stuff[i]['lb']  + '<= ' + vars[i] + '<= ((' + sym_exvars[i] + '+1)*' + str(BLOCK[i]) + '- 1), ' + stuff[i]['ub'] + ' && ';
        l = dane['path'][i]

#par vars zle
#
        s = s + Constr_Wbloku(vars, sym_exvars, stuff, BLOCK, i, par_vars[l], dane['path'][i])
        # i przedostatni element
        #
             
    for i in range(dane["nest"], len(vars)):
        s = s + vars[i] + " = -1 && "
    
  ##########################################
  ##########################################
    
    if(dane["max_loop"] == dane["nest"]):
        for i in range(dane["max_loop"], len(sym_exvars)):
            s = s + sym_exvars[i] + " = 0 && "
    else:
        for i in range(dane["nest"], len(sym_exvars)):

            #s = s + "" + sym_exvars[i] + " = 1 "

           # poprawka
            if(par_tiling):
                s = s + par_vars[l] + " <= " + stuff[i]['ub'] + "-"+ stuff[i]['lb']   +" && "
                s = s + par_vars[l] + " > " + stuff[i]['ub'] + "-"+ stuff[i]['lb'] +"-"+ BLOCK[i]   +"  && "
            else:
                # tu jest maly blad: jak pod granica jest zmienna z innej petli to trzeba ja wyeleminowac jej granicami albo jakos tak bo moze sie w iteracjach zmienic jej zakres
                s = s + BLOCK[i] + "*" + sym_exvars[i] + " <= " + stuff[i]['ub'] + "-"+ stuff[i]['lb']   +" && "
                s = s + BLOCK[i] + "*" + sym_exvars[i] + " > " + stuff[i]['ub'] + "-"+ stuff[i]['lb'] +"-"+ BLOCK[i]   +"  && "
              
            # tu powinno byc ub - lb / b
            #s = s + sym_exvars[i] + " = "+stuff[i]['ub']+"&& "
    return s


def MakeBij(_SYM, vars, sym_exvars, par_vars, stuff, BLOCK, dane, par_tiling):
    Bij = "_Bij := [";
    Bij = Bij + _SYM        
    Bij = Bij[:-1] + "] -> {["
    
    for s in vars:
        Bij = Bij + s + ","
        
    Bij = Bij + 'v' + '] : '
    Bij = Bij + Constraint(vars, sym_exvars, stuff, BLOCK,dane, par_vars, par_tiling)
    
    for s in sym_exvars:
        Bij = Bij + s + ">=0 && "
    
    #eksperymentalnie gorna granica zawsze wieksza od dolnej   
    for i in range(0,len(dane['path'])):  #
        l = dane['path'][i]
        Bij = Bij + stuff[l]['lb'] + ' <= ' + stuff[l]['ub'] + ' && '
        
    Bij = Bij + "("
    
    for i in range(0,len(dane['st'])):
        Bij = Bij + " v = "+ str(dane['st'][i])
        if(i < len(dane['st'])-1):
            Bij = Bij + " || "
        
    Bij = Bij + ")};"
    return Bij


def MakeBLTandBGT_v2(_SYM, vars, sym_exvars, par_vars, varsprim, exvars, stuff, BLOCK, dane, dane2, par_tiling):
    global maxl
    BLT = "_BLT := [" + _SYM
    #  tu trzeba dodac zmienne iib, jjb dla spar. tilingu
    BLT = BLT[:-1] + "] -> {["
    for s in vars:
        BLT = BLT + s + ","
    BLT = BLT + 'v' + '] : (( '
    BGT = BLT.replace('_BLT :=', '_BGT :=')
    n = dane["nest"]
    m = dane2["nest"]

    min_nest = 0
    for i in range(0,min(m,n)):
        if dane["path"][i] != dane2["path"][i]:
            break
        else:
            min_nest = i+1

    #print dane["path"]
    #print dane2["path"]
    #print "===================================" + str(min_nest)
    if(dane["nest_id"] == dane2["nest_id"]):  # ta sama petla licz stara metoda
        for i in range(n-1,n):    # od 0 ????????????????????????????????????????????????????????
            for j in range(0,i):
                l = dane['path'][j]
                tmp = Constr_Wbloku(vars, sym_exvars, stuff, BLOCK, j, par_vars[l], dane['path'][j])
                BLT = BLT + tmp
                BGT = BGT + tmp
            l = dane['path'][i]
            BLT = BLT + Constr_Przed(vars, sym_exvars, stuff, BLOCK, i, par_vars[l], dane['path'][i])
            BGT = BGT + Constr_Za(vars, sym_exvars, stuff, BLOCK, i, par_vars[l], dane['path'][i]) 
            for j in range(i+1,n):
                l = dane['path'][j]
                tmp = Constr_Dowolny(vars, sym_exvars, stuff, BLOCK, j, par_vars[l], dane['path'][j])
                BLT = BLT + tmp
                BGT = BGT + tmp
            BLT = BLT + " true )"
            BGT = BGT + " true )"
            if(i<n-1):
                BLT = BLT + " or ("
                BGT = BGT + " or ("
    else:
        for i in range(min_nest-1,min_nest):   # od 0 ????????????????????????????????????????????????????????
            l = dane['path'][i]
            tmp = Constr_Wbloku(vars, sym_exvars, stuff, BLOCK, i, par_vars[l], dane['path'][i])
            tmp = tmp[:-3] + " or "
            if(dane2["nest_id"] > dane["nest_id"]):
                BLT = BLT + tmp
                    
            if(dane2["nest_id"] < dane["nest_id"]):
                BGT = BGT + tmp

            BLT = BLT + Constr_Przed(vars, sym_exvars, stuff, BLOCK, i, par_vars[l], dane['path'][i])
            BGT = BGT + Constr_Za(vars, sym_exvars, stuff, BLOCK, i, par_vars[l], dane['path'][i])
            
            BLT = BLT + " true )"
            BGT = BGT + " true )"
            if(i<min_nest-1):
                BLT = BLT + " or ("
                BGT = BGT + " or ("



    varcon = ") && ("
    for i in range(0, dane["nest"]):
        l = dane['path'][i]
        varcon = varcon + sym_exvars[i] + ">=0 && "
        if(par_tiling):
            varcon = varcon + par_vars[l] + "<=" + stuff[l]['ub'] +" && "
        else:
            varcon = varcon + BLOCK[i] + "*" + sym_exvars[i] + "<=" + stuff[l]['ub'] +" && "
        
            
    
    for i in range(0,len(dane['st'])):
        varcon = varcon + " v = "+ str(dane['st'][i])
        if(i < len(dane['st'])-1):
            varcon = varcon + " || "
    varcon = varcon + ") "
    
    #dodaj  j = -1 lub granice i granice na jj    lub -0 lub ub
    for i in range(min(m,n),maxl):   
        if n < i+1:
            varcon = varcon + " && " + vars[i] + " = -1 " 
        else:
            if m < i+1:  # granice
                l = dane['path'][i]
                varcon = varcon + "&& " + Constr_Dowolny(vars, sym_exvars, stuff, BLOCK, i, par_vars[l], dane['path'][i]) + sym_exvars[i] + " >= 0 && " 
                varcon = varcon + Constr_Wbloku(vars, sym_exvars, stuff, BLOCK, i, par_vars[l], dane['path'][i])
                varcon = varcon[:-3]   


    if(min_nest > 0):
        BLT = BLT + varcon + "};"
        BGT = BGT + varcon + "};"
    else:
        if(dane['st'][0] > dane2['st'][0]):
            BLT = BLT + ""+ varcon + " && false};"
            BGT = BGT + "" + varcon + "};"
        else:
            BLT = BLT + varcon + "};"
            BGT = BGT + varcon + " && false};"


    BLGT = []

    BLGT.append(BLT)
    BLGT.append(BGT) 
    

    return BLGT 


def postprocess_loop(lines):
    #dodaj s1 do petli
    loop = ""
    for i in range(0,len(lines)):
        tmp = lines[i]
        pattern = re.compile("^\s*\(")
        if pattern.match(tmp):
            z = pattern.findall(tmp)[0]
            tmp = tmp.replace(z, z + "s1")
            tmp = tmp.replace("(s1", "s1(")
            tmp = tmp.replace(", ", ",")
        loop = loop + tmp
# if(i < len(lines)-1):
        loop = loop + "\n"
    return loop


def Project(S, sym_exvars):
    for s in sym_exvars:
        isl_symb = S.get_var_names(isl.dim_type.param)
        S = S.project_out(isl._isl.dim_type.param, isl_symb.index(s), 1)
        
    return S
        
  

def GetRapply(vars, sym_exvars, _SYM):
    R = "R := ["
    R = R + _SYM
        
    R = R[:-1] + "] -> {["
    for s in vars:
        R = R + s + ","
    R = R + "v] -> ["
    for s in sym_exvars:
        R = R + s + ","
    for s in vars:
        R = R + s + ","
    R = R + "v] : "     
    R = R + " true };\n"
    
    isl_Rapply = isl.Map(R.replace('R := ',''))
    return isl_Rapply


def GetRapply2(vars, sym_exvars, _SYM, instrukcje, i):
    R = "{["
    for s in sym_exvars:
        R = R + s + ","
    for s in vars:
        R = R + s + ","
    R = R + "v] -> ["
    for s in sym_exvars:
        R = R + s + "," + s + "p,"
    for s in vars:
        R = R + s + "," + s + "v,"
    R = R + "v] : " 
    

    z = ""

    pos = codegen.calculate_position2(i, instrukcje, len(sym_exvars)) 
    #pos = instrukcje[i]['path']
    
   
    
    #for l in range(len(instrukcje[i]['path']), len(sym_exvars)):
    #    pos.append(-1)
        
    print pos

    j = 0
    for s in sym_exvars:
        z = z + s + "p = " + str(pos[j]) + " and "
        j = j + 1
        
    z = z + "("

    for l in range(0, i+1):
        pos = codegen.calculate_position(l, instrukcje, len(sym_exvars)) 
        for st in instrukcje[l]['st']:
            z = z + " (v = " + str(st) + " and "
            j = 0
            for s in vars:
                z = z + s + "v = " + str(pos[j]) + " and "
                j = j + 1
            z = z[:-4] + ") or "
            
        
    R = R + z[:-3] + ")}"
    isl_Rapply = isl.Map(R)
    return isl_Rapply

def ExtendMap(R, sym_exvars, Extend = False):
    R = R.insert_dims(isl.dim_type.in_, 0, len(sym_exvars))
    for i in range(0, len(sym_exvars)):
        R = R.set_dim_name(isl.dim_type.in_, i, sym_exvars[i])
    R = R.insert_dims(isl.dim_type.out, 0, len(sym_exvars))
    for i in range(0, len(sym_exvars)):
        R = R.set_dim_name(isl.dim_type.out, i, sym_exvars[i])

    if(Extend):
        for i in range(0, 2*len(sym_exvars)):
            R = R.insert_dims(isl.dim_type.in_, 2*i+1, 1)
            R = R.insert_dims(isl.dim_type.out, 2*i+1, 1)

    return R

def MultiNest(instrukcje):
    for nest in instrukcje:
        l = len(nest['path'])
        for nest2 in instrukcje:
            l2 = len(nest2['path'])
            if(l == l2):
                for i in range(0, l-1):
                    if nest2['path'][i] != nest['path'][i]:
                        return True
    return False
###############################################################


def tile(plik, block, permute, output_file="", L="0", SIMPLIFY="False", perfect_mode = False, parallel_option = False, rplus_file = ''):

    schedule_mode = parallel_option

    #print "********** another version **************"
    LPetit = "tmp/tmp_petit"+L+".t"
    LDeps = "tmp/deps"+L+".txt"


    if perfect_mode:
        print 'Perfectly nested loop mode: enabled'


    simpl_ub = SIMPLIFY

    BLOCK = block.split(',')
    par_tiling = False
    
    for i in range(len(BLOCK),10):
        BLOCK.append(BLOCK[len(BLOCK)-1])
        
    if(not BLOCK[0].isdigit()):
        par_tiling = True
     
    linestring = open(plik, 'r').read()
    lines = linestring.split('\n')

    if simpl_ub:
        petit_loop = convert_loop.convert_loop(lines, BLOCK)
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



    cmd = gen.path_petit + " " + LPetit + " > " + LDeps
    process = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)
    process.wait() 

    
    lines = linestring.split('\n')
    stuff = []

    for_level = 0
    for line in lines:
        if 'endfor' in line:
            for_level = for_level - 1
        else:
            if 'for' in line:
                if simpl_ub:
                    stuff.append(functions.Loop(line, BLOCK[for_level]))
                else:
                    stuff.append(functions.Loop(line))
                for_level = for_level + 1







    #if(schedule_mode == 0):
    #    flag = 1
    #else:
    flag = 1

    # Proba prywatyzacji zmiennych w instrukcjach w gniazdach
    priv_stuff = priv_engine.PrivEng(LDeps)
    if(imperf == 1):
        priv_box = 1

        dane = []
        sts = imperf_tile.Get_ST(LPetit, dane)
        dane = dane + sts
        combo = loop_tools.ReadStatementNests(LPetit, dane)
        instrukcje = combo[0]


        for pp in priv_stuff[3]:
            for i in instrukcje:
                a = set(i['st'])
                b = set(pp[1])
                if (a & b) and (b - a): # nie wszystkie instrukcje skalara sa w gniezdzie
                    priv_box = 0

    # ==========


    # jesli zmienne prywatne sa w obrebie jednego S1 to mozna 
        
    start = time.time()
    if((imperf == 1 and priv_box == 0)):
        dane = gen.RelPrint(LPetit, flag)
    else:
        if(len(priv_stuff[1]) > 0 and (priv_stuff[2] == 1 or False)):
            dane = gen.RelPrint_WithPriv(LPetit, priv_stuff[1])
        else:
            dane = gen.RelPrint(LPetit, flag)

    output = process.stdout.read()

    end = time.time()
    elapsed = end - start
    print "Dependence analysis: time taken: ", elapsed, "seconds."

    print dane

    dane = dane.split("#")
    

    
    rel = dane[0]
    rel2 = rel



    dane.remove(rel)  
    dane = list(set(dane))

    if(DEBUG):
        print rel



    # Create LD
    Dependence.Create_LD_petit(L, petit_loop)

    # -------------------------------------------------------
    # script for barvinok
    # gdy nie ma zaleznosci
    # problemy do rozwiazania
    # zmienne symboliczne nie wiadomo skad wziasc
    # numery instrukcji
    nodeps=0
    if(rel == ''):


        nodeps=1
        LD_inp = "tmp/LD_petit_loop_" + L + ".t"
        dane2 = gen.RelPrint(LD_inp,1)
        dane2 = dane2.split("#")
        rel2 = dane2[0]
        try:
            isl_rel2 = isl.Map(str(rel2))
            isl_symb = isl_rel2.get_var_names(isl.dim_type.param)
            symb = isl_symb
        except:
            print "Internal error."
            sys.exit()   
        rel = "[" +",".join(symb) + "] -> {["   
        for i in range(0,len(stuff)):
            rel = rel + "i" + str(i) + ","
        rel = rel + "v] -> ["
        for i in range(0,len(stuff)):
            rel = rel + "i" + str(i) + "',"
        rel = rel + "v'] : false }"
    
    #loop_tools.MakeLDPetit("tmp/tmp_petit.t", "tmp/tmp_ld_petit.t")


    
    #dane2.remove(rel2)
    #dane2 = list(set(dane2))
    #for i in range(0, len(dane2)):
    #    dane2[i] = str(int(dane2[i]) - 1)

    for s in dane:
        if "UNKNOWN" in s:
            dane.remove(s)
   

    
    # dodaj dane bez relacji
    sts = imperf_tile.Get_ST(LPetit, dane)
    dane = dane + sts

    combo = loop_tools.ReadStatementNests(LPetit, dane)
    instrukcje = combo[0]
  
    nest_loop = combo[1]




    if len(instrukcje)==0:
        print 'blad - brak instrukcji'
        sys.exit()
        # wczytaj wszystkie
    



    # eksperymentalnie kasowanie innych poziomow
    stuff_reduced = stuff[:] #osobna kopia

    do_kas = []
    for i in range(1, max(nest_loop)+1):
        dups = duplicates(nest_loop, i)
        for s in dups:
            if s != min(dups):
                do_kas.append(s)

    for item in do_kas:
        stuff_reduced[item] = '!'

    for i in range(0,stuff_reduced.count('!')):
        stuff_reduced.remove('!') # remove
    # -------------------------------
    
    global maxl
    maxl = 0
    for item in instrukcje:
        if item['max_loop'] > maxl:
            maxl = item['max_loop']


    start = time.time()

    tmp_st = []
    if(perfect_mode):
        firstst = str(instrukcje[0]['st'][0])
        print rel
        rel = re.sub(r"v = \d+", "v = " + firstst, rel)
        rel = re.sub(r"v' = \d+", "v' = " + firstst, rel)
        print rel
        tmp_st = instrukcje[0]['st']
        instrukcje[0]['st'] = [instrukcje[0]['st'][0]]
        print instrukcje[0]['st']
        # wywal reszte zapisz gdzies tablice
        # exit(1)


    isl_rel = isl.Map(str(rel))






    z = isl_rel.dim(isl.dim_type.out)
    zz = maxl - z  + 1
    if(zz >0):
        print "Error. Dimensions of dependencies are not equal to an amount of loop nests"
        print "Relations will be extended."
        isl_rel = isl_rel.insert_dims(isl.dim_type.in_, z-1, zz)
        isl_rel = isl_rel.insert_dims(isl.dim_type.out, z-1, zz)

    # jesli ktorys z blokow ma 1 wywal te zaleznosci

    # w slicgu mozna tak jesli zewn petla tylko zapisuje zmienne prywatne
    if(BLOCK[0] == '1' and schedule_mode == 0):
        z = isl_rel.dim(isl.dim_type.out)
        rtmp = "{["
        for i in range(0, z):
            rtmp = rtmp + "i" + str(i) + ","
        rtmp = rtmp[:-1] + "] -> ["
        for i in range(0, z):
            rtmp = rtmp + "o" + str(i) + ","
        rtmp = rtmp[:-1] + "] : i0 = o0 };"
        rtmp = isl.Map(rtmp)

        isl_rel = isl_rel.intersect(rtmp).coalesce()

    
    # lata na petle ktore nie ma w relacjach
    #if maxl > isl_rel:

    start = time.time()

    # **************************************************************************
    exact_rplus = '-1'
    isl_relclosure = isl_rel
    if(rplus_file != ''):
        with open (rplus_file, "r") as myfile:
            data=myfile.read().replace('\n', '')
            isl_relclosure = isl.Map(str(data))
    else:
        isl_relclosure = isl_rel.transitive_closure()
        exact_rplus = isl_relclosure[1]
        isl_relclosure = isl_relclosure[0]

    isl_relplus = isl_relclosure
    end = time.time()
    elapsed = end - start
    print "Transitive closure: time taken: ", elapsed, "seconds."  

    isl_ident = isl_rel.identity(isl_rel.get_space())
    isl_relclosure = isl_relclosure.union(isl_ident).coalesce()  # R* = R+ u I

    if(_debug_):
        print "R*"
        print isl_relclosure
        print exact_rplus
    # **************************************************************************
       
    isl_symb = isl_rel.get_var_names(isl.dim_type.param)
    symb = isl_symb

    end = time.time()
    print end - start
    

    
    vars = []  # i
    exvars = []  # ii'
    sym_exvars = []  # ii
    varsprim = []  # i'
    par_vars = [] # iib
    p_vars = [] #iib bez plusa lb
    p_symb = []
    im_par_vars = []


    # moze warto do iloczynu dodac lb a do floor N - lb
    # do testowania +'+'+s['lb']
    i = 0
    for s in stuff_reduced:
        vars.append(s['var']);
        sym_exvars.append(s['var']*2);
        exvars.append(s['var']*2+"'");
        varsprim.append(s['var']+"'");
        if par_tiling:
            par_vars.append(s['var']*2+'b'+'+'+s['lb'])
            p_vars.append(s['var']*2+'b')
        else:
            par_vars.append(s['var']*2 + "*" + BLOCK[i]+'+'+s['lb'])
        i = i+1
        

    # codegen.calculate_position(1, instrukcje, len(sym_exvars))



    for s in stuff:
        i = vars.index(s['var'])
        if par_tiling:
            im_par_vars.append(s['var']*2+'b'+'+'+s['lb'])
        else:
            im_par_vars.append(s['var']*2 + "*" + BLOCK[i]+'+'+s['lb'])


    _SYM = ""
            
    for s in sym_exvars:
        _SYM = _SYM + s + ","
        
        
    for i in range(len(vars),10):
        BLOCK.pop()
        
    if(par_tiling):
        for s in p_vars:
            _SYM = _SYM + s + ","
            p_symb.append(s)
        for s in set(BLOCK):   #remove duplicates
            _SYM = _SYM + s + ","
            p_symb.append(s)        
                

    for s in symb:
        _SYM = _SYM + s + ","



        
    # wektory same 0 - mozesz dac parallel
    # prywatyzuj calosc, tam gdzie zapis seq, same 0 to parallel bloki (tylko odczyt)
    par_tiled = 0
    delta = isl_rel.deltas()
    chkc = isl.Set("{[0," + ",".join(vars) + "]}")
    delta = delta.subtract(chkc)
    if(delta.is_empty()):
        par_tiled = 1
        print "Parallel tiling detected."



    
            
    ########################################################################
    

    

    Rapply = GetRapply(vars, sym_exvars, _SYM)
    
    isl_TILE = []
    isl_TILE_LT = []
    isl_TILE_GT = []
    isl_TILE1 = []
    isl_TILE2 = []
    isl_TILEprim = []
    isl_TILEbis = []

    

    permutate_list = []
    permutate_maps = []
    FFF_lines = []
    FFF_idx = []
    FFF_headers = []
    FFF_headers_idx = []



    for i in range(0, len(instrukcje)):
        Bij = MakeBij(_SYM, vars, sym_exvars, im_par_vars, stuff, BLOCK, instrukcje[i], par_tiling)
        isl_TILE.append(isl.Set(str(Bij).replace("_Bij := ", "")))

        # oblicz II_SET
        if(False):
            if(len(symb) > 0):
                ii_set = '[' + ','.join(symb)  + '] -> '
            else:
                ii_set = ''
            ii_set = ii_set + '{[' +  ','.join(sym_exvars) + '] : '

            for l in range(0, len(sym_exvars)):
                ii_set = ii_set + sym_exvars[l] + ' >= 0 and '
                ii_set = ii_set + BLOCK[l] + '*' + sym_exvars[l] + ' + ' + stuff[l]['lb']  + ' <= ' + stuff[l]['ub'] + ' and '
            ii_set = ii_set + ' 1=1}'
            print ii_set
            ii_set = isl.Set(ii_set)
            print 'II_SET ' + str(ii_set)
            print 'CARD II_SET ' + test_isl.StringToCard(str(ii_set))
        # ------------------------------





        bltc=0  # czy juz liczono blt
        bgtc=0  #   -- || --     bgt

        
        for j in range(0, len(instrukcje)):
            BLGT = MakeBLTandBGT_v2(_SYM, vars, sym_exvars, im_par_vars, varsprim, exvars, stuff, BLOCK, instrukcje[j], instrukcje[i], par_tiling)   # porownaj zagniezdzenia instrukcji
            isltmp = isl.Set(str(BLGT[0]).replace("_BLT := ", ""))
            if(bltc==0):
                isl_TILE_LT.append(isltmp)
                bltc=1
            else:
                isl_TILE_LT[i] = isl_TILE_LT[i].union(isltmp).coalesce()

            isltmp = isl.Set(str(BLGT[1]).replace("_BGT := ", ""))           
            if(bgtc==0):
                isl_TILE_GT.append(isltmp)
                bgtc=1
            else:
                isl_TILE_GT[i] = isl_TILE_GT[i].union(isltmp).coalesce()
        
        if(DEBUG):
            print "s" + str(i)
            print "LT"
            print isl_TILE_LT[i]
            print "GT"
            print isl_TILE_GT[i]





        X = isl_TILE_GT[i].apply(isl_relclosure).coalesce()


        isl_BCUR = isl_TILE[i].subtract(X).coalesce()



        isl_TILE1.append(isl_BCUR)

        isl_BPREV = isl_BCUR.apply(isl_relclosure).intersect(isl_TILE_LT[i]).coalesce()
        isl_BPREV = isl_BPREV.subtract(X).coalesce()    # changed according to ACM TOPLAS reviewer

        #print isl_BPREV
        #print '---'

        isl_TILE2.append(isl_BPREV)

        isl_TILEprim.append(isl_TILE1[i].union(isl_TILE2[i]).coalesce())

        # print isl_TILEprim[0]

        ############################################################################
        if(par_tiling):
            idx_bylo = []

            S = "["
            S1 = ",".join(sym_exvars) + "] -> {[" + ",".join(vars) + ",v] :"
            for j in range(0,len(instrukcje[i]['path'])):

                idx = str(instrukcje[i]['path'][j])
                liniabb = " = floord(" + stuff[instrukcje[i]['path'][j]]['ub'] + "-" + stuff[instrukcje[i]['path'][j]]['lb'] + " ," + BLOCK[j] + ");"

                if 1==1 or liniabb not in FFF_headers:  # always true,
                    FFF_headers.append(liniabb)
                    FFF_headers_idx.append(idx)
                    linia = "int fff" + idx + liniabb
                    linia = linia.replace("floord( ", "floord(")
                    FFF_lines.append(linia)
                else:
                    idx = FFF_headers_idx[FFF_headers.index(liniabb)]

                if str({'id' : idx, 'j' : j}) not in FFF_idx:
                    FFF_idx.append({'id' : idx, 'j' : j})

                if idx not in idx_bylo:
                    S = S + "fff" + idx + ","
                    idx_bylo.append(idx)
                S1 = S1 + " " + sym_exvars[j] + "<= fff" + idx + " and "

            S = S + S1 + " true }"

            print S
            S = isl.Set(S)

            isl_TILEprim[i] = isl_TILEprim[i].intersect(S).coalesce()
        #########################################################################


        if(permute):
            RP = imperf_tile.PermuteBlock(LDeps, isl_TILEprim[i], instrukcje[i], symb, len(sym_exvars), permutate_list)
            if(isinstance(RP, isl.Map)):
                print "Permutation experimental enabled:"
                permutate_maps.append(RP)
                isl_TILEprim[i] = isl_TILEprim[i].apply(RP)
                #print isl_TILEprim[i]

        isl_TILEbis.append(Project(isl_TILEprim[i].apply(Rapply).coalesce(), sym_exvars).coalesce())

        if(_debug_):
            print "TILE"
            print isl_TILE[i]
            print "TILE_LT"
            print isl_TILE_LT[i]
            print "TILE_GT"
            print isl_TILE_GT[i]
            print "TILE_ITR (TILE1)"
            print isl_TILE1[i]
            print "TVLD_LT (TILE2)"
            print isl_TILE2[i]
            print "TILE_VLD (TILE')"
            print isl_TILEprim[i]
            print "card"
            print test_isl.StringToCard(str(isl_TILEprim[i]))
            print "TILE_VLD_ext (TILE'')"
            print isl_TILEbis[i]








            # correct upper bounds for simpl_ub

        if simpl_ub:

            cor_set = ''
            if(len(symb) > 0):
                cor_set = '[' + ','.join(symb)  + '] -> '
            else:
                cor_set = ''


            cor_set = cor_set + '{[' +  ','.join(sym_exvars) + ','  +  ','.join(vars) + ',' + 'v] : '

            for j in range(0, len(instrukcje[i]['path'])):
                cor_set = cor_set +  vars[j]  + " <= " + stuff_reduced[instrukcje[i]['path'][j]]['ub'] + " - " + BLOCK[j] + " && "

            cor_set = cor_set + "("
            for v in instrukcje[i]['st']:
                cor_set = cor_set + " v = " + str(v) + " or"
            cor_set = cor_set[:-2] + ")}"

            cor_set = isl.Set(cor_set)

            #print cor_set
            #sys.exit(0)

            isl_TILEbis[i] =  isl_TILEbis[i].intersect(cor_set).coalesce()



        #if(SIMPLIFY):
         #   isl_TILEbis[i] = imperf_tile.SimplifySlice(isl_TILEbis[i])


        #print "TILE''" + "dla s" + str(i) + "\n" +  str(isl_TILEbis[i])
    #eksepeymentalnie dodaj pozycje do tilebis jesli wiele gniazd na roznych poziomach
    
    Extend = False
    if(imperf == 1):
        Extend = True
        #Extend = MultiNest(instrukcje)
    #Extend = True

    #print imperf
    #sys.exit(0);

    _rap =  GetRapply2(vars, sym_exvars, _SYM, instrukcje, 0)
    
    if(Extend):
        z = isl_TILEbis[0].apply(_rap)
    else:
        z = isl_TILEbis[0]
    
    for j in range(1, len(isl_TILEbis)):
        _rap =  GetRapply2(vars, sym_exvars, _SYM, instrukcje, j)
        if(Extend):
            z = z.union(isl_TILEbis[j].apply(_rap))
        else:
            z = z.union(isl_TILEbis[j])
    
    z = z.coalesce()
    z = z.remove_redundancies()
    z = z.detect_equalities()

    #calculate II_SET
    ii_SET = z.remove_dims(isl.dim_type.set, int(isl_TILEbis[i].dim(isl.dim_type.set)/2), int(isl_TILEbis[i].dim(isl.dim_type.set)/2)).coalesce()

    if(_debug_):
        print "II_SET"
        print ii_SET


    step = 0
    if Extend:
        step = 1

    nazwa = ""
    nazwapar = ""

    filePaths = glob.glob(plik)
    if(output_file != ""):
        nazwa = output_file
        nazwapar = output_file
    else:
        for filePath in filePaths:
            base = os.path.basename(filePath)
            nazwa = os.path.splitext(base)[0] + "_tiling" + os.path.splitext(base)[1]
            nazwapar = os.path.splitext(base)[0] + "_partiling" + os.path.splitext(base)[1]

    if(perfect_mode):
        print z
        chang = str(tmp_st[0]) + "]"
        print chang

        for i in range(1, len(tmp_st)):
            zz = str(z).replace(chang, str(tmp_st[i]) + "]")
            zz = isl.Set(zz)
            z = z.union(zz).coalesce()

        instrukcje[0]['st'] = tmp_st # correct statements



    if(not schedule_mode or par_tiled):
        print "Cloog start..."
        start = time.time()

        barv = 1
        if(barv == 1):
            loop_x = iscc.iscc_communicate("L :=" + str(z) + "; codegen L;")
        else:  #cloog

            loop_x = codegen.tile_gen_short(vars, sym_exvars, symb,z,instrukcje, Extend)
        #loop_x = iscc.oc_communicate(z)
        #loop_x = codegen.tile_gen(vars, sym_exvars, symb, isl_TILEbis, instrukcje, "", [], stuff)

        end = time.time()
        elapsed = end - start
        print "Code generation: time taken: ", elapsed, "seconds."

        #print loop_x

        ########################################################################

        loop_x = postprocess_loop(loop_x.split('\n'))
        loop = loop_x



        lines = loop.split('\n')

        loop = imperf_tile.RestoreStatements(lines, LPetit, dane,  maxl, step, permutate_list)

        if par_tiled:
            loop = "#pragma omp parallel for\n" + loop

        for i in range(0, 5):
            if(loop[-1] == '\n'):
                loop = loop[:-1]
        loop = loop + "\n"

        new_gen = True

        if(not new_gen):
            gen.ParsePrint2("tmp/tmp_petit.t", len(sym_exvars))





        if(new_gen):
            text_file = open(nazwa, "w")
            text_file.write(loop)
            text_file.close()

            if par_tiling:
                lines = FFF_lines + correct.Korekta(nazwa)
                for i in range(0,len(lines)):
                    if "for" in lines[i] and "fff" in lines[i]:
                        reg = re.compile("\=.*")
                        linia = reg.sub("", lines[i])
                        reg = re.compile(".*\(")
                        cc = reg.sub("", linia)
                        cc = cc.replace(" ", "")
                        for FF_item in FFF_idx:
                            if "fff" + FF_item['id'] in lines[i]:
                                lines[i] = lines[i] + "\n" + correct.whites(lines[i]) + "  register int " + sym_exvars[FF_item['j']] + "b = " + BLOCK[FF_item['j']] + "*" + cc + ";"
                                break
                    lines[i] = lines[i] + "\n"
                text_file = open(nazwa, "w")
                text_file.writelines(lines)
                text_file.close()
                if schedule_mode:
                    text_file = open(nazwapar, "w")
                    text_file.writelines(lines)
                    text_file.close()

            if(output_file != ""):
                return ""
            if(not schedule_mode):
                rtile = tiling_schedule.get_RTILE(z, sym_exvars, isl_rel, Extend)
                print "RTILE:"
                print rtile

    

# =====================================================================================================================
# PARALLEL PARALLEL PARALLEL PARALLEL PARALLEL PARALLEL PARALLEL PARALLEL PARALLEL PARALLEL PARALLEL PARALLEL PARALLEL

    Dodatek = [LPetit, dane,  maxl, step, nazwapar, permutate_list, permutate_maps]

    par_tiled = 0

    if(schedule_mode and  par_tiled != 1):
        if(False):
            tiling_schedule.tile_par(isl_TILEprim, isl_TILEbis, sym_exvars, symb, isl_rel, isl_relplus, isl_relclosure)
        else:
            tiling_schedule.tile_par3(z, sym_exvars, isl_rel, isl_relplus, isl_relclosure, Extend, _rap, Dodatek,SIMPLIFY, ii_SET)



# przelec po blokach znajdz relacje jak nie ma to parallel