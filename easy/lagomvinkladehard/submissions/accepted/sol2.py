import math
n = int(input())
res = 0
for i in range(1, n+1):
    for j in range(i, n+1):
        k = round(math.sqrt(i*i + j*j - i*j))
        if k*k == i*i + j*j - i*j and k <= n:
            res += 1

print(res)
