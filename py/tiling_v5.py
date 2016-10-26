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
import vis

import imperf_tile
import test_isl
import relation_util

import Dependence
import clanpy
from termcolor import colored


import vis3dimperf

import fsnew_tiletry


import slicing


from CPython import codegen


try:
    import islpy as isl
except ImportError, e:
    print e
    print "pip install ispy"
    sys.exit()

ctx = isl.Context()

# nowosc isl w pythonie do testow

def GetBounds(lines, st_line):
    for_level = 0
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
                    bounds.insert(0, {'var' : items[1], 'lb' : items[3], 'ub' : items[5], 'step' : step, 'loop' : line})

    return bounds


def MakeTile(st, vars, sym_exvars, symb, B):
    #TODO i--
    TILE = '['+','.join(symb + sym_exvars) +'] -> { [' + ','.join(vars) + ',' + str(st.petit_line) + '] : '

    deeploop =  len(st.original_iterators)

    for i in range(0, len(vars)):
        if(i < deeploop):
            tile_part =  st.bounds[i]['lb'] + ' + ' + B[i] + '*' + sym_exvars[i] + ' <= ' + vars[i] + ' <= '
            tile_part +=  B[i] + '*(1+' + sym_exvars[i] + ') + ' + st.bounds[i]['lb'] + '-1, ' + st.bounds[i]['ub']
            tile_part +=  ' && ' + sym_exvars[i] + ' >= 0 && '

            TILE += tile_part
        else:
            TILE +=  sym_exvars[i] + ' >= 0 && ' + vars[i] + ' = 0 && '

    TILE += ' 1=1 }'

#tile_i_s1 = ' N-1 - b1 * ii >= i >= N-1-b1*(ii+1)+1, 0 && ii >=0 && '
#tile_j_s1 = ' (i+1) + b2*jj <= j <= b2*(jj+1)+i+1-1, N-1 && jj >= 0 &&'
#tile_k_s1 = ' b3*kk + 0 <= k <= b3*(kk+1)+0-1, j-i-1 && kk >= 0  '

#TILE_S1 += tile_i_s1 + tile_j_s1 + tile_k_s1 + '}'

    return TILE



def ReplaceB(tile, BLOCK):
    for i in range(0,10):
        tile = tile.replace('b' + str(i), BLOCK[i])
    return tile



def tile(plik, block, permute, output_file="", L="0", SIMPLIFY="False", perfect_mode = False, parallel_option = False, rplus_file = ''):

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


    SIMPLIFY = False
    DEBUG = True

    LPetit = "tmp/tmp_petit"+L+".t"

    BLOCK = block.split(',')

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
    loop = Dependence.Kernel_Loop(LPetit)

    loop.Load_Deps()
    loop.Load_instrukcje()
    loop.Preprocess()
    loop.Get_Arrays()
    end = time.time()
    elapsed = end - start


    print "Dependence analysis: time taken: ", elapsed, "seconds."

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
        cl.statements[i].bounds = GetBounds(petit_loop, cl.statements[i].petit_line)
        print cl.statements[i].bounds
        i=i+1


    ############################################################

    ### R^+

    isl_rel = loop.isl_rel

    start = time.time()
    if (DEBUG):
        print '!!!!!!!!!!'
    # **************************************************************************
    if(1==0):
        exact_rplus = '-1'
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
        print "!! exact_rplus " + str(exact_rplus)

        isl_relclosure = isl_relclosure.union(isl_ident).coalesce()  # R* = R+ u I

        if (DEBUG):
            print "R*"
            print isl_relclosure


    # **************************************************************************
    B = (["b%d" % i for i in range(0,loop.maxl)])

    for st in cl.statements:
        if (len(st.original_iterators) == loop.maxl):
            vars = st.original_iterators
            break

    sym_exvars = []
    for v in vars:
        sym_exvars.append(v*2)

    if (DEBUG):
        print sym_exvars
        print vars

    isl_symb = isl_rel.get_var_names(isl.dim_type.param)

    BLOCK = block.split(',')

    for i in range(len(BLOCK),10):
        BLOCK.append(BLOCK[len(BLOCK)-1])

    # **************************************************************************

    TILE = []

    for st in cl.statements:
        tile =  MakeTile(st, vars, sym_exvars, isl_symb, B)
        tile = ReplaceB(tile, BLOCK)
        tile = isl.Set(tile)
        TILE.append(tile)
        print tile

    # **************************************************************************



