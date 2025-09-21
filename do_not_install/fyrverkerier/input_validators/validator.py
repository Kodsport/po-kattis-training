#!/usr/bin/python3
import re
import sys

int_regex = "(0|[1-9][0-9]*)"
intspace_regex = int_regex + "( " + int_regex+")*"
line_regex = "^" + intspace_regex + "$"

line = sys.stdin.readline()
assert re.match(line_regex, line)
n, s = [int(x) for x in line.split()]

assert 3 <= n <= 20
assert 1 <= s <= 200

for i in range(n):
    line = sys.stdin.readline()
    assert re.match(line_regex, line)
    s, p = [int(x) for x in line.split()]
    assert 1 <= s <= 200
    assert 1 <= p <= 200

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
