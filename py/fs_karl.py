try:
    import islpy as isl
except ImportError, e:
    print e
    print "pip install ispy"
    sys.exit()
    ctx = isl.Context()


def Project(S, sym_exvars):
    for s in sym_exvars:
        isl_symb = S.get_var_names(isl.dim_type.param)
        S = S.project_out(isl._isl.dim_type.param, isl_symb.index(s), 1)

    return S

import sys


r1 = "[n] -> {[i,-1,1] -> [i,1,2] : 1 <= i <= n}"
r2 = "[n] -> {[i,j,2] -> [i',j,2] : 1 <= i < n && 1 <= j <= n && i' = i+ 1}"
r3 = "[n] -> {[i,j,2] -> [i,j',2] : 1 <= i <= n && 1 <= j < n && j'=j+1}"

r1 = isl.Map(r1)
r2 = isl.Map(r2)
r3 = isl.Map(r3)

r = r1.union(r2).union(r3).coalesce()

# r' = {[k, X ] -> [k +1, Y ] : constraints and k >= 0}.
rp = r
rp = rp.insert_dims(isl.dim_type.in_, 0, 1)
rp = rp.insert_dims(isl.dim_type.out, 0, 1)
rp = rp.set_dim_name(isl.dim_type.in_,0, 'ik1')
rp = rp.set_dim_name(isl.dim_type.out,0, 'ok1')

c = isl.Constraint.eq_from_names(rp.get_space(), {'ik1': -1, 'ok1':1, 1 : -1})
rp = rp.add_constraint(c)
rp = rp.coalesce()

c = isl.Constraint.ineq_from_names(rp.get_space(), {'ik1': 1, 1 : 0})
rp = rp.add_constraint(c)
rp = rp.coalesce()

# ---------------------------------------------------
#R0'

r0p = rp
#r0p = r0p.insert_dims(isl.dim_type.param, 0, 1)
#r0p = r0p.set_dim_name(isl.dim_type.param,0, 'k0k')

#c = isl.Constraint.eq_from_names(r0p.get_space(), {'ik1': -1, 'k0k':1})
#r0p = r0p.add_constraint(c)
#r0p = r0p.coalesce()

# ---------------------------------------------------
#R1'

r1p = rp
#r1p = r1p.insert_dims(isl.dim_type.param, 0, 1)
#r1p = r1p.set_dim_name(isl.dim_type.param,0, 'k1k')

#c = isl.Constraint.eq_from_names(r1p.get_space(), {'ik1': -1, 'k1k':1})
#r1p = r1p.add_constraint(c)
#r1p = r1p.coalesce()

# ---------------------------------------------------

uds = r.domain().subtract(r.range()).coalesce()

# ---------------------------------------------------
# [0, X ]

S = uds
S = S.insert_dims(isl.dim_type.set, 0, 1)
S = S.set_dim_name(isl.dim_type.set,0, 'ik1')
c = isl.Constraint.eq_from_names(S.get_space(), {'ik1': 1, 1 : 0})
S = S.add_constraint(c)


# ----------------------------------------------------

D = r.domain().get_space()
G = r.range().get_space()

D = isl.Set(str(D))
G = isl.Set(str(G))

G = G.insert_dims(isl.dim_type.out, 0, 1)
G = G.set_dim_name(isl.dim_type.out,0, 'ik1')

FS = isl.Map.from_domain_and_range(D, G).coalesce()

# -----------------------------------------------------

FS1 = isl.Map.from_domain_and_range(uds, G).coalesce()


# -----------------------------------------------------


r0p_star = r0p.transitive_closure()[0]
isl_ident = isl.Map.identity(r0p.get_space())
r0p_plus = r0p_star.union(isl_ident).coalesce()


RG = S.apply(r0p_plus)

FS1 = isl.Map.from_domain_and_range(uds, G).coalesce()
FS2 = isl.Map.from_domain_and_range(D, RG).coalesce()

FS12 = FS1.intersect(FS2)

FS12 = FS12.insert_dims(isl.dim_type.param, 0, 1)
FS12 = FS12.set_dim_name(isl.dim_type.param,0, 'k0k')



c = isl.Constraint.eq_from_names(FS12.get_space(), {'ik1': -1, 'k0k':1})
FS12 = FS12.add_constraint(c)
FS12 = FS12.coalesce()



# -----------------------------------------------------

r1p_star = r1p.transitive_closure()[0]


RG1 = S.apply(r1p_star)

FS3 = isl.Map.from_domain_and_range(D, RG1).coalesce()

FS3 = FS3.insert_dims(isl.dim_type.param, 0, 1)
FS3 = FS3.set_dim_name(isl.dim_type.param,0, 'k1k')

FS3 = FS3.insert_dims(isl.dim_type.param, 0, 1)
FS3 = FS3.set_dim_name(isl.dim_type.param,0, 'k0k')



c = isl.Constraint.eq_from_names(FS3.get_space(), {'ok1': -1, 'k1k':1})
FS3 = FS3.add_constraint(c)
FS3 = FS3.coalesce()


c = isl.Constraint.ineq_from_names(FS3.get_space(), {'k1k': 1, 'k0k':-1, 1 : -1})

FS3 = FS3.add_constraint(c)
FS3 = FS3.coalesce()



# ----------------------------------------------------

FS = FS12.subtract(FS3).coalesce()

FS = Project(FS, ["k0k"])
FS = Project(FS, ["k1k"])

SK = FS.range()
print SK
