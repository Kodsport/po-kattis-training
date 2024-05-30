#!/usr/bin/python3
import re
import sys

int_regex = "(0|[1-9][0-9]*)"
intspace_regex = int_regex
line_regex = "^" + intspace_regex + "$"

line = sys.stdin.readline()
assert re.match(line_regex, line)
n = int(line)

assert 1 <= n <= 1000000000

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
