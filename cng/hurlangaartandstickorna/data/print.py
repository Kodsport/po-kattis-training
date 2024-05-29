#!/usr/bin/python3

import sys
import random
import math
rand = random.randint

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

n = rand(1, 100)
print(n)
print(rand(1,100))
print(rand(1,100))
for i in range(n):
    print(rand(1,100))

