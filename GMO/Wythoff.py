
def Countdown(x, y):
	for i in range(x):
		yield (i,y)
	for i in range(y):
		yield (x,i)
	for i in range(1,min(x,y)):
		yield (x-i, y-i)
		if x-i-1 >= 0 and y-i >= 0:
			yield (x-i-1, y - i)
		if x-i >= 0 and y-i-1 >=0: 
			yield (x-i, y-i-1)

Wythoff_Dict = {}

def __Wythoff(x,y):
	if x == 0 and y == 0:
		return "Lose"
	if abs(x-y) < 2:
		return "Win "
	for each in Countdown(x,y):
		xa,ya = each
		if Wythoff(xa,ya) == "Lose":
			return "Win "
	return "Lose"


def Wythoff(x,y):
	if (x,y) in Wythoff_Dict:
		return Wythoff_Dict[(x,y)]
	else:
		ret = __Wythoff(x,y)
		#print "____(%d,%d):%s"%(x,y,ret)
		Wythoff_Dict[(x,y)] = ret
		return ret


MAX = 100

for x in range(0,MAX):
	for y in range(x+1,MAX):
		if Wythoff(x,y) == "Lose":
			print y-x,":",x,y