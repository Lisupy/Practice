
from string import *


def subStringMatchExact(target,key):
    ans = ()
    index = 0
    while index != -1:
       index = find(target, key, index)     
       if index != -1:
           ans = ans + (index,)
           index = index + 1  
    return ans


#print subStringMatchExact("aa", "a")