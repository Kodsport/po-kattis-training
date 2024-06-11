import sys
import re


int_reg = "(0|[1-9][0-9]*)"

line = sys.stdin.readline()

assert re.match("^" + int_reg + "$", line)

ops = int(line)

for i in range(ops):
    line = sys.stdin.readline()
    if line[0] == '1':
        assert re.match("^1$", line)
    elif line[0] == '2':
        assert re.match("^2$", line)
    else:
        assert re.match("^0 "+int_reg+"$", line)

line = sys.stdin.readline()
assert len(line) == 0

sys.exit(42)
