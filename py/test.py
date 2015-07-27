import re

line = "i+ii-2*i"

operators = ["i", "ii"]

for w in operators:
    pattern = r"\b" + w + r"\b"
    line = re.sub(pattern, w + "'", line)

print line