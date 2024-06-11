#!/usr/bin/env python
import sys
from sys import stdin
import re
int_reg = re.compile("^[1-9][0-9]*$")
line1 = stdin.readline()
assert int_reg.match(line1), "First line does not consist of one ints"
x = int(line1)
assert 1 <= x and x <= 1e9, "n out of bounds"
if len(stdin.readline()) != 0:
    print "Garbage input"
    sys.exit(0)
sys.exit(42)

