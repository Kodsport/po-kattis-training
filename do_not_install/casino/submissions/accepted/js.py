#@EXPECTED_RESULT@: AC
n, k, p = [float(x) for x in raw_input().split()]
print("Spela" if n*p - k < 0 else "Spela inte!")
