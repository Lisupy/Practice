#Problem Set 1
#Name: darrenhp

from ps1a import get_primes
from math import *

n = input("?n=")

s = 0
for i in get_primes(n):
        s += log(i)
print s

print sum(map(log, get_primes(n)))
