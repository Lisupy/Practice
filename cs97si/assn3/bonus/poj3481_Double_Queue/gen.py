#coding=utf-8

SZ = 1000000
def gen1(fo):
  l , r = 1 , SZ
  while l < r:
    print >> f, 1, l, l  
    print >> f, 1, r, r
    l += 1
    r -= 1

def gen2(fo):
  l , r = 1 , SZ
  while l < r:
    print >> f, 1, l, l  
    l += 1

def gen3(fo):
  l , r = 1 , SZ
  while l < r:
    print >> f, 1, l, SZ - l  
    print >> f, 1, l, SZ + l  
    l += 1

with open("c.in", "w") as f:
  gen1(f)
with open("d.in", "w") as f:
  gen2(f)
with open("e.in", "w") as f:
  gen3(f)

