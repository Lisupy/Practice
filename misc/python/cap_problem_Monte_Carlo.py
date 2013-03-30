#coding=utf-8
import random

def tryone(m):
	times = 0
	sel = 0
	used = [False for i in range(m)]
	while sel < m:
		times = times + 1
		trysel =  random.randint(0, m-1)
		if not used[trysel]:
			used[trysel] = True
			sel = sel+1
	return times

s = 0
for i in range(1000):
	t = tryone(19)
	s += t
	print t
print "**: ", s/1000