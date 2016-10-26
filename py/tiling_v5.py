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



ctx = isl.Context()

def tile(plik, block, permute, output_file="", L="0", SIMPLIFY="False", perfect_mode = False, parallel_option = False, rplus_file = ''):

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
