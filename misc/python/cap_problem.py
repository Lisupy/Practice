#coding=utf-8
def cal(m):
    return sum([(1.0*m)/(m-i) for i in range(0,m)])


s = 0.0
x = 0.1
for i in range(1,10000):
	s += i*((1-x)**(i-1))*x
print s

for i in range(20):
	print i,cal(i)