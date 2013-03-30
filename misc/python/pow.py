#coding=utf-8


def pow_O_logN(a,n):
    t = pow(a, n/2)
    if n == 1:      return a
    if n == 0:      return 1
    if n % 2 == 0:  return t*t
    if n % 2 == 1:  return t*t*a 

for i in range(0,100):
    for j in range(0,100):
        if pow_O_logN(i,j) != pow(i,j):
            print i,j
print "End."

