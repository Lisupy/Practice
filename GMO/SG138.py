

def SG(i):
	if i < 0:
		return 1
	if SG(i-1) == 0 or SG(i-3) == 0 or SG(i-8) == 0:
		return 1
	return 0

#print SG(1)

for i in range(100):
	print "%03d:%03d"%(i, SG(i))