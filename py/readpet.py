import iscc

scopfile = 'testw.c'

#######################################################################
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


output = loop_x = iscc.iscc_communicate(cmd)

output = output.split('\n')

schedule = output[1]
ld = output[3]
rel = output[11]
ind = output[13]

print schedule
print ld
print rel
print ind
