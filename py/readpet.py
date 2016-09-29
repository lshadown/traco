import iscc
import islpy as isl

scopfile = 'testw.c'

#######################################################################
# BARVINOK + PET
cmd = 'p := parse_file "' + scopfile + '";'
cmd += 'Domain := p[0];'
cmd += 'Write := p[1] + p[2];'
cmd += 'Read := p[3];'
cmd += 'Schedule := map p[4];'
cmd += 'print "Schedule";'
cmd += 'print Schedule;'
cmd += 'Before := Schedule << Schedule;'
cmd += 'RaW := (Write . (Read^-1)) * Before;'
cmd += 'WaW := (Write . (Write^-1)) * Before;'
cmd += 'WaR := (Read . (Write^-1)) * Before;'
cmd += 'print "LD";'
cmd += 'print Domain;'
cmd += 'print "RaW deps";'
cmd += 'print RaW;'
cmd += 'print "WaW deps";'
cmd += 'print WaW;'
cmd += 'print "WaR deps";'
cmd += 'print WaR;'
cmd += 'R := WaR + WaW + RaW;'
cmd += 'print "R";'
cmd += 'R;'
cmd += 'LDR := domain R + range R;'
cmd += 'IND := Domain - LDR;'
cmd += 'print "IND";'
cmd += 'print IND;'
#######################################################################
# RESULT TO ISLPY

output = loop_x = iscc.iscc_communicate(cmd)

output = output.split('\n')

schedule = output[1]
ld = output[3]
rel = output[11]
ind = output[13]


ld = isl.UnionSet(ld)
ind = isl.UnionSet(ind)
schedule = isl.UnionMap(schedule)
rel = isl.UnionMap(rel)

print "LD"
print ld
print "SCHEDULE"
print schedule
print "REL"
print rel
print "IND"
print ind

#######################################################################
# FINISH

# NEXT CLAN AND MATH LINES TO S_NUMBER

