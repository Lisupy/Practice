#Problem Set 1
#Nmae: darrenhp
from math import *
def get_primes(num):
        if num < 0:
                print "FUCK"
                AttributeError("num must not less than 0")
        if num == 0:
                return []
        primes = [2]
        n = 3
        while len(primes) < num:
                flag = True
                for i in primes:
                        if n % i == 0:
                                flag = False
                                break   
                if flag:
                       primes += [n]
                n = n + 2
        return primes
        
print get_primes(1000)


