#coding=utf-8
from random import *

def gen(fo):
  n = randint(1, 10)
  m = randint(1, 100)
  print >>fo, n, m
  x = randint(1, m)
  for i in range(n):
    y = randint(1, m)
    z = randint(1, m)
    print >>fo, x, y, z
  print >> fo, 0, 0

for cnt in range(10):
  with open(str(cnt) + ".in", "w") as fo:
    gen(fo)




