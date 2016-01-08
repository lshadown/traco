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


def fs_new(rel, rel_plus, isl_relclosure, uds, LPetit, dane, plik, SIMPLIFY, rap, acc, loop):



    # R = R - R+ compose R

    rel = rel.subtract(rel_plus.apply_range(rel))

    print '### R = R - R+ compose R'
    print rel

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

    REPR = D.union(IS.subtract(W)).coalesce()

    print "### REPR"
    print REPR

    rel_inv = rel.fixed_power_val(-1)

    print "R^-1"
    print rel_inv


    # R = R compose RINV

    RR = rel.apply_range(rel_inv)

    print "### RR"
    print RR

    UDS_lexmin = D.lexmin()

    print UDS_lexmin
    print D
    R2 = isl.Map.from_domain_and_range(UDS_lexmin, D).coalesce()


    RRstar = RR.transitive_closure()[0].coalesce()
    RR_ident = RR.identity(RR.get_space())
    RRstar = RRstar.union(RR_ident).coalesce()  # R* = R+ u I

    R1 = RRstar.intersect_domain(REPR)

    print R1
    print R2


    RSCHED = R1.union(R2).coalesce()



    #upraszczanie

    Rtmp = RSCHED.polyhedral_hull()
    if (Rtmp.subtract(RSCHED).coalesce().is_empty() and RSCHED.subtract(Rtmp).coalesce().is_empty()):
        print "upraszczanie"
        Rtmp = RSCHED


    print "### RSCHED"
    print RSCHED




    print "### Check "
    Check_set = RSCHED.domain().union(RSCHED.range()).subtract(IS).coalesce()

    if Check_set.is_empty():
        print "OK"
    else:
        print Check_set






