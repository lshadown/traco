try:
    import islpy as isl
except ImportError, e:
    print e
    print "pip install ispy"
    sys.exit()
    ctx = isl.Context()

import sys
from subprocess import Popen, PIPE, STDOUT


oc_proc = '~/omega+/omega_calc/obj/oc < tmp/oc.txt'

# isl map to omega str
def islMaptoOmegaStr(R):

    p = isl.Printer.to_str(isl.DEFAULT_CONTEXT)
    p = p.set_output_format(isl.format.OMEGA)
    p.flush()

    return p.print_map(R).get_str()

def islSettoOmegaStr(R):

    p = isl.Printer.to_str(isl.DEFAULT_CONTEXT)
    p = p.set_output_format(isl.format.OMEGA)
    p.flush()

    return p.print_set(R).get_str()

def oc_IterateClosure(R):


    isl_symb = R.get_var_names(isl.dim_type.param)
    outFile = open('tmp/oc.txt', 'w')
    for sym in isl_symb:
        outFile.write('symbolic ' + sym + ";")

    outFile.write('R :=')
    outFile.write(islMaptoOmegaStr(R))
    outFile.write(';IterateClosure R;')
    outFile.close()

    cmd = oc_proc
    p= Popen(cmd, shell=True, stdout=PIPE, stdin=PIPE)
    stdout_data = p.communicate(input='')[0]

    stdout_data = stdout_data.split('\n')

    relcl = ''
    now = False
    for i in range(0, len(stdout_data)):
        if 'Iterate' in stdout_data[i]:
            now = True
            continue
        if now:
            relcl += stdout_data[i]

    symprefix = ''
    if len(isl_symb) > 0:
        symprefix = '[' + ','.join(isl_symb) + '] -> '

    w = symprefix + relcl
    w = w.replace('} union {', ';')

    rcl = isl.Map(w)

    return rcl



#r2 = "[n] -> {[i,j,2] -> [i',j,2] : 1 <= i < n && 1 <= j <= n && i' = i+ 1; [1,n,1] -> [2,2,2]}"
#r2 = isl.Map(r2)
#print r2
#print oc_IterateClosure(r2)