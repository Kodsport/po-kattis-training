#!/usr/bin/python3
from itertools import combinations

N, T = map(int, input().split())
w = list(map(int, input().split()))

winning = 0
for r in range(N + 1):
    for comb in combinations(w, r):
        if sum(comb) == T:
            winning += 1

probability = 100*winning / (1 << N)
print(f"{probability:.10f}")
