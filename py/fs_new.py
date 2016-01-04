try:
    import islpy as isl
except ImportError, e:
    print e
    print "pip install ispy"
    sys.exit()
    ctx = isl.Context()



import iscc
import sys
import os
import imperf_tile
import tiling_v3
import tiling_schedule
import openacc
import clanpy


def fs_new(rel, rel_plus, uds, LPetit, dane, plik, SIMPLIFY, rap, acc, loop):


    # R = R - R+ compose R

    rel = rel.subtract(rel_plus.apply_range(rel))

    print '### R = R - R+ compose R'
    print rel

    cl = clanpy.ClanPy()
    cl.loop_path = plik
    cl.Load()
    cl.RunCandl()

    print isl.Set(cl.statements[0].domain_map).coalesce()