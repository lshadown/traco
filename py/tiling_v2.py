# coding=utf-8
# S0 = RTILE
# I0 = domain(S0)
# for i = 0; ;i + + do <- Infinity loop
#
# if i = 0 then
#  J0 = range(S0)
#  FS0 = I0 − J0 <- Fair sources for s0
#  L0 = S0(FS0)
#  else
#  L0 = S0(Lay0)
#  J0 = J0 − Lay0
# end if
#
# D0 = S0(J0)
# Lay0 = L0 − D0
#
# if Lay0 = nulll then
#  Break <- End of algorithm
# end if
#
# codegen(Lay0) <- Generate loop for i-th Lay
#
# end for
import sys
from termcolor import colored
import islpy as isl
ctx = isl.Context()

import iscc
import imperf_tile

def DynamicRTILE(rtile, TILE_VLD_ext, n):

    I0 = rtile.domain();
    print I0
    for i in range(0,10000):
        if (i==0):
            J0 = rtile.range()
            FS0 = I0.subtract(J0).coalesce()
            L0 = FS0.apply(rtile)
        else:
            L0 = Lay0.apply(rtile)
            J0 = J0.subtract(Lay0)


        D0 = J0.apply(rtile)

        Lay0 = L0.subtract(D0).coalesce()

        if(Lay0.is_empty()):
            break

        Lay = Lay0.insert_dims(isl.dim_type.set, 2*n, 2*n)
        Lay = Lay.intersect(TILE_VLD_ext).coalesce()
        Lay = imperf_tile.SimplifySlice(Lay)


        loop = iscc.isl_ast_codegen(Lay)
        loop = loop.split('\n')
        if 'for' in loop[0]:
            if((('int c1') in loop[0]) or (('int c3') in loop[0]) or (('int c5') in loop[0])):
                loop.insert(0, "#pragma omp parallel for")



        for line in loop:
            if '#pragma' in line:
                print colored(line, 'green')
            else:
                print line

        loop = '\n'.join(loop)


