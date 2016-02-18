import islpy as isl
import relation_util

rel = "{ [i, j, 6] -> [i', j', 6] : i >= 0 and j >= 8 + i and i' <= 9 and j <= j' <= 9 and j' <= 7 + i'; [i, 5, 6] -> [i', j', 6] : i >= 0 and i' <= 9 and 7 + i <= j' <= 9 and j' <= 7 + i'; [i, j, 6] -> [i', 5, 6] : i >= 0 and 8 + i <= j <= 9 and -7 + j <= i' <= 9; [i, j, 6] -> [i', j, 6] : i >= 0 and 0 <= j <= 9 and i < i' <= 9; [i, j, v] -> [i, j, v] }"

rel = isl.Map(rel)


rel = rel.set_dim_name(isl.dim_type.in_, 0, "_i0")
rel = rel.set_dim_name(isl.dim_type.in_, 1, "_i1")
rel = rel.set_dim_name(isl.dim_type.in_, 2, "_i2")

rel = rel.set_dim_name(isl.dim_type.out, 0, "_o0")
rel = rel.set_dim_name(isl.dim_type.out, 1, "_o1")
rel = rel.set_dim_name(isl.dim_type.out, 2, "_o2")

print(rel)

set_test = '[_x0,_x1,_x2]->{[_x0,_x1,_x2]}'
set_test = isl.Set(set_test)

print set_test


print relation_util.islMaptoOmegaStr(rel)

rel_test = set_test.apply(rel)

print relation_util.islSettoOmegaStr(rel_test)