#!/usr/bin/python3
import re
import sys

int_regex = "(0|[1-9][0-9]*)"
intspace_regex = int_regex + "( " + int_regex+")*"
line_regex = "^" + intspace_regex + "$"

line = sys.stdin.readline()
assert re.match(line_regex, line)
vals=[int(x) for x in line.split()]
assert len(vals)==1
n = vals[0]

assert 3 <= n <= 20

line = sys.stdin.readline()
assert re.match(line_regex, line)
vals=[int(x) for x in line.split()]
assert len(vals)==3
a, b, c = vals

assert 0 <= a and 0 <= b and 0 <= c and a+b+c <= 50

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
