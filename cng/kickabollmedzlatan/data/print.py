#!/usr/bin/python3

import sys
import random
import math

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

x = random.randint(2, 10)
print(x)
print(random.randint(0, 1000))
for i in range(x-1):
    print(random.randint(0, 2000))

