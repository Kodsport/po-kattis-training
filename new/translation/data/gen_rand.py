#!/usr/bin/python3

import sys
import random
from random import randint
import math
import string

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default


def generate_unique_strings(num_strings):
    unique_strings = set()
    while len(unique_strings) < num_strings:
        length = random.randint(1, 15)
        random_string = ''.join(random.choices(string.ascii_lowercase, k=length))
        unique_strings.add(random_string)
    return list(unique_strings)

swedish = generate_unique_strings(50000)
english = generate_unique_strings(50000)


random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg("n"))
m = int(1e4)

print(n)
keys = random.sample(swedish, m)
sentence = []
for i in range(n):
    sentence.append(random.choice(keys))
print(*sentence)
print(m)
for key in keys:
    print(key, random.choice(english))
