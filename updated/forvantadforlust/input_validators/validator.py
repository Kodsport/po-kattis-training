#!/usr/bin/python3
import sys
from sys import stdin
import re
int_reg = "[1-9][0-9]*"
dec_reg = "(0|"+int_reg+")"+"(."+int_reg+")?"
entire_regex = re.compile("^"+int_reg+" "+int_reg+" "+dec_reg+"$")
line1 = stdin.readline()
assert entire_regex.match(line1), "First line does not consist of two ints, one float" 
tokens = line1.split()
x, y, z = [int(tokens[0]), int(tokens[1]), float(tokens[2])]
assert 1 <= x and x <= 100, "n out of bounds"
assert 1 <= y and y <= 100, "k out of bounds"
assert 0 <= z and z <= 1, "p out of bounds"
if len(stdin.readline()) != 0:
    print("Garbage input")
    sys.exit(0)
sys.exit(42)

