#coding=utf-8


def gen(f):
  n = 1000
  x = 100
  print >> f, n, n
  for i in range(n):
    print >> f, 'x'*n
  print >> f, x, x
  for i in range(x):
    print >> f, 'x'*x

t = 15
with open('1.in', 'w') as f:
  print >> f, t
  for i in range(t):
    gen(f)


