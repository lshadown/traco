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
import iscc
import imperf_tile
import re

def fs_new(rel, rel_plus, isl_relclosure, uds, LPetit, dane, plik, SIMPLIFY, rap, acc, loop, exact):

    #floyd
    #rel_ = isl.Map(str('{[i,j,k,v]->[i,jj,kk,v]}'))
    #rel = rel.intersect(rel_).coalesce()

    # R = R - R+ compose R

    if(exact):
        print 'R+ exact!'
    else:
        print 'R+ approximated. Exit!'
        sys.exit(0);

    print '## R'


    print rel

    rel = rel.subtract(rel_plus.apply_range(rel))

    print '### R = R - R+ compose R'
    print rel

    UDS = rel.domain().subtract(rel.range()).coalesce()
    UDD = rel.range().subtract(rel.domain()).coalesce()
    DOM_RAN = rel.range().union(rel.domain()).coalesce()

    cl = clanpy.ClanPy()
    cl.loop_path = plik
    cl.Load()
    cl.RunCandl()

    IS =  isl.Set(cl.statements[0].domain_map).coalesce()

    set_size = IS.dim(isl.dim_type.set)
    IS = IS.insert_dims(isl.dim_type.set, set_size, 1)
    IS = IS.set_dim_name(isl.dim_type.set, set_size, "v")

    c= isl.Constraint.eq_from_names(IS.get_space(), {"v": -1, 1:int(dane[0])})
    IS = IS.add_constraint(c).coalesce()

    IND = IS.subtract(DOM_RAN).coalesce()

    n = rel.dim(isl.dim_type.in_)

    inp = []
    outp = []
    for i in range(0,n):
        inp.append("i" + str(i))
        outp.append("o" + str(i))


    # Rlex
    rlex = "{[" + ",".join(inp) + "] -> [" + ",".join(outp) + "] : " + tiling_v3.CreateLex(outp, inp) + "}"
    rlex = isl.Map(rlex)

    rip = rel_plus.fixed_power_val(-1)

    re_rel = isl.Map.from_domain_and_range(IS, IS)

    #print re

    print "### RE"

    re_rel = re_rel.intersect(rlex.subtract(rel_plus).subtract(rip)).coalesce()

    print re_rel

    W = re_rel.domain().union(re_rel.range()).coalesce()
    D = re_rel.domain().subtract(re_rel.range()).coalesce()


    print D



    REPR = D.union(DOM_RAN.subtract(W)).coalesce()

    print "### REPR"
    print REPR


    rel_inv = rel.fixed_power_val(-1)

    print "R^-1"
    print rel_inv


    # R = R compose RINV

    RR = rel.apply_range(rel_inv)


    # ------ Jesli RCHECK ----------

    if(1==0):
        RRR1 = rel.fixed_power_val(2)
        RRR2 = rel_inv.fixed_power_val(2)

        RRR = RRR1.union(RRR2).coalesce()
        RR = RR.union(RRR).coalesce()

    # ------------------------------

    RR = RR.intersect(rlex).coalesce()

    print "### RR"
    print RR

    IND_lexmin = IND.lexmin()


    R2 = isl.Map.from_domain_and_range(IND_lexmin, IND).coalesce()


    RRstar = RR.transitive_closure()
    if not RRstar[1]:
        print 'RR* not exact'
    #    sys.exit(0)

    RRstar = RR.transitive_closure()[0].coalesce()


    RR_ident = RR.identity(RR.get_space())
    RRstar = RRstar.union(RR_ident).coalesce()  # R* = R+ u I


    print "### Rstar"
    print RRstar


    # tu blad


    R1 = RRstar.intersect_domain(REPR.coalesce())

    print 'RSCHED obliczanie :'
    print R1
    print "IND0->IND"
    print R2
    #print R3
    print "i razem"




    RSCHED = R1.union(R2).coalesce()

    print RSCHED



    #upraszczanie
    if(SIMPLIFY and 1==0):
        Rtmp = RSCHED.polyhedral_hull()
        if (Rtmp.subtract(RSCHED).coalesce().is_empty() and RSCHED.subtract(Rtmp).coalesce().is_empty()):
            print "upraszczanie"
            RSCHED = Rtmp

    #RSCHED = imperf_tile.SimplifyMap(RSCHED)





    print "### RSCHED"
    print RSCHED




    print "### Check "
    Check_set = RSCHED.domain().union(RSCHED.range()).coalesce()
    Check_set = IS.subtract(Check_set).coalesce()

    if Check_set.is_empty():
        print "OK"
    else:
        print "ERROR ! " + str(Check_set)
        sys.exit(0)


    # generowanie kodu

    D = RSCHED.domain()

    #if(SIMPLIFY):
    D =  imperf_tile.SimplifySlice(D)

    print "# DOMAIN RSCHED"
    print D



    looprepr = iscc.isl_ast_codegen(D)

    for i in range(0,20):
        looprepr = re.sub('\\b'+'c' + str(i) +'\\b', 't' + str(i), looprepr)

    print looprepr
    looprepr  = looprepr.split('\n')






    st_reg = re.compile('\s*\(.*\);')
    vecs = []
    taby = []
    for line in looprepr:
        if(st_reg.match(line)):
            vecs.append(isl.Set(iscc.s1_to_vec2(line, len(vecs))))
            taby.append(iscc.correct.whites(line))


    slices = []
    for vec in vecs:
        slice = vec
        if(not RSCHED.is_empty()):
            slice_ = slice.apply(RSCHED)
            slice = slice.union(slice_).coalesce()
            slice = slice_


        if(SIMPLIFY):
            slice = imperf_tile.SimplifySlice(slice)


        #slice = slice.apply(rap)


        slices.append(slice.coalesce())

    print slices

    new_loop = []
    i=0
    for line in looprepr:
        if(st_reg.match(line)):
            petla = iscc.isl_ast_codegen(slices[i]).split('\n')
            for s in petla:
                new_loop.append(taby[i] + s)
            i = i + 1
        else:
            new_loop.append(line)


    nloop = ""
    for line in new_loop:
        if line != '':
            nloop = nloop + line + "\n"
    nloop = nloop[:-1]
    nloop = nloop.split('\n')

    nloop = tiling_v3.postprocess_loop(nloop)
    print nloop





