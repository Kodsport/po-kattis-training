#!/usr/bin/python3
import re, sys

intreg = "([1-9][0-9]*)"
fullreg = re.compile("^"+intreg+"$")
nlines = 0
while True:
    line = sys.stdin.readline()
    if not line:
        break
    assert fullreg.match(line), "Line does not consist of an int"
    N = int(line)
    assert 1 <= N and N <= 200000, "N out of bounds"
    nlines += 1
assert 1 <= nlines <= 10000
sys.exit(42)
