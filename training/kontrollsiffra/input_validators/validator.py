#!/usr/bin/python3
import sys
from sys import stdin
import re
dec_regex = re.compile("^[0-9]( [0-9]){8}$")
line1 = stdin.readline()
if dec_regex.match(line1) == None:
    print("First line does not consist of 9 digits")
    sys.exit(0)
if len(stdin.readline()) != 0:
    print("Garbage input")
    sys.exit(0)
sys.exit(42)

