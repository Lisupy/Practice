
from string import *

def countSubStringMatch(target,key):
    count = 0
    index = 0
    while index != -1:
        index = find(target, key, index)     
        if index != -1:
            count = count + 1
            index = index + 1
    return count

def countSubStringMatchRecursive (target, key): 
    index = find(target, key)
    if index == -1:
        return 0
    else:
        return 1 + countSubStringMatchRecursive(target[index + 1:], key)
    
#print countSubStringMatchRecursive("aabab", "ab")