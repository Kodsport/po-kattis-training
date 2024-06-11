#@EXPECTED_RESULT@: AC
seq = [int(x) for x in raw_input().split()]
ans = [seq[x-1] * (3 if x%2 == 1 else 7) for x in range(1, 10)]
print(reduce(lambda x, y: (x+y)%10, ans))
