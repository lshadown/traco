import re

try:
    import islpy as isl
except ImportError, e:
    print e
    print "pip install ispy"
    sys.exit()
    ctx = isl.Context()

line = "i+ii-2*i"

operators = ["i", "ii"]

for w in operators:
    pattern = r"\b" + w + r"\b"
    line = re.sub(pattern, w + "'", line)

print line

r = isl.Map("{[i,j] -> [i',j'] : ( i' = 1+i and j' = 1+j  and 0 <= i <= 2 and 0 <= j <= 2 ) or ( i' = 1+i and 1+j' = j  and 0 <= i <= 2 and 1 <= j <= 3 ) or (i=0) };");


#printer = isl.Printer.to_str(isl.DEFAULT_CONTEXT)
#printer = printer.set_output_format(3)
#printer.print_map(r)
#print(printer.get_str())

b = isl.AstBuild.from_context(isl.Set("{:}"))
m = isl.Map("{S[i]->[i]: 0 <= i <= 10}")
ast = b.ast_from_schedule(m)
print ast
p = isl.Printer.to_str(isl.DEFAULT_CONTEXT)
p = p.set_output_format(isl.format.C)
p.flush() 
p = p.print_ast_node(ast)
print(p.get_str()) 
