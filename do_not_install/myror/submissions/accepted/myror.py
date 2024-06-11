import sys
antalben=int(sys.stdin.read())

ok=False
for antalmyror in range(43):    # loop from 0 to 42
   if antalmyror * 6  +  (42-antalmyror) * 8 == antalben:
	print antalmyror
        ok=True
        break

if not ok:
    print "FEL"
