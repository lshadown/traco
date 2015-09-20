try:
    import islpy as isl
except ImportError, e:
    print e
    print "pip install ispy"
    sys.exit()
    ctx = isl.Context()

import sys
import iscc

r1 = "[n] -> {[i,-1,1] -> [i,1,2] : 1 <= i <= n}"
r2 = "[n] -> {[i,j,2] -> [i',j,2] : 1 <= i < n && 1 <= j <= n && i' = i+ 1 }"
r3 = "[n] -> {[i,j,2] -> [i,j',2] : 1 <= i <= n && 1 <= j < n && j'=j+1 }"



r1 = isl.Map(r1)
r2 = isl.Map(r2)
r3 = isl.Map(r3)

r = r1.union(r2).union(r3).coalesce()

# ---------------------------------------------------
# r' = {[k, X ] -> [k +1, Y ] : constraints and k >= 0}.
rp = r
rp = rp.insert_dims(isl.dim_type.in_, 0, 1)
rp = rp.insert_dims(isl.dim_type.out, 0, 1)
rp = rp.set_dim_name(isl.dim_type.in_,0, 'ik1')
rp = rp.set_dim_name(isl.dim_type.out,0, 'ok1')

#rp = rp.set_dim_name(isl.dim_type.out,1, 'ii')


c = isl.Constraint.eq_from_names(rp.get_space(), {'ik1': -1, 'ok1':1, 1 : -1})

rp = rp.add_constraint(c)
rp = rp.coalesce()

c = isl.Constraint.ineq_from_names(rp.get_space(), {'ik1': 1, 1 : 0})
rp = rp.add_constraint(c)
rp = rp.coalesce()

# ---------------------------------------------------

uds = r.domain().subtract(r.range()).coalesce()
#print uds

# ---------------------------------------------------
# [0, X ]

S = uds
S = S.insert_dims(isl.dim_type.set, 0, 1)
S = S.set_dim_name(isl.dim_type.set,0, 'ik1')
c = isl.Constraint.eq_from_names(S.get_space(), {'ik1': 1, 1 : 0})
S = S.add_constraint(c)

# ----------------------------------------------------

r0p_plus = rp.transitive_closure()[0]
isl_ident = isl.Map.identity(rp.get_space())
r0p_star = r0p_plus.union(isl_ident).coalesce()


RG = S.apply(r0p_plus).coalesce()
RG1 = S.apply(r0p_star).coalesce()

for i in range(0, rp.dim(isl.dim_type.set)-1):
    RG = RG.set_dim_name(isl.dim_type.set, i, 'i' + str(i))
    RG1 = RG1.set_dim_name(isl.dim_type.set, i, 'i' + str(i))

ORGp = iscc.iscc_communicate("S := " + str(RG) + ";S;", 1)
ORGs = iscc.iscc_communicate("S := " + str(RG1) + ";S;", 1)

print ORGs
print ORGp

# SYMB------------------------------------------------------

isl_symb = rp.get_var_names(isl.dim_type.param)

if (len(isl_symb) > 0):
    isl_symb = '[' + ','.join(isl_symb) + '] -> '
else:
    isl_symb = ''
#print isl_symb

# ------------------------------------------------------

data = []
for i in range(0, rp.dim(isl.dim_type.set)):
  data.append('i' +  str(i))

var = '[' + ', '.join(data) + '] : '
print var


# ------------------------------------------------------

ORGs = ORGs.replace(var, '')
ORGp = ORGp.replace(var, '')

ORGs = ORGs.replace('union', 'or')
ORGp = ORGp.replace('union', 'or')

ORGs = ORGs.replace('{', '(')
ORGp = ORGp.replace('{', '(')

ORGs = ORGs.replace('}', ')')
ORGp = ORGp.replace('}', ')')

ORGs = ORGs.replace('\n', '')
ORGp = ORGp.replace('\n', '')

ORGs = '( ' + ORGs + ' )'
ORGp = '( ' + ORGp + ' )'

print ORGs
print ORGp

# ------------------------------------------------------

FS = isl_symb + '{' + var + ORGs

FS = FS + ' and not exists k0k : k0k > i0 and ' + ORGp.replace('i0', 'k0k')

FS = FS + '}'

print FS

sys.exit(0)
'''
codegen [n] -> { [i0, i1, i2, i3] : ((i3 = 2 and i2 <= n and i2 >= 1 + i0 - i1 and i2 >= 1 and i2 <= i0 and i1 <= n ) or ( i0 = 0 and i2 = -1 and i3 = 1 and i1 >= 1 and i1 <= n ))
and not exists a : a > i0 and ( i3 = 2 and i2 <= n and i2 >= 1 + a - i1 and i2 >= 1 and i2 <= a and i1 <= n )};


dodaj symboliczne
dla rg1
wyciagnij zmienne
usun je zastap (
zamien union na or
zamien {} na ()
otocz ()
zloz relacje
dla rg
to samo do otocz()
poprzed and not exists a : a > i0 and
zastap i0 na a
dodaj };
'''


