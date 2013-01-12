from ps3a import *
from ps3b import *
from ps3c import *


def subStringMatchExactlyOneSub(target, key):
    allAnswers = ()
    for miss in xrange(0, len(key)):
        key1 = key[0: miss]
        key2 = key[miss+1:]
        match1 = subStringMatchExact(target, key1)
        match2 = subStringMatchExact(target, key2)
        allAnswers = allAnswers + constrainedMatchPair(match1, match2, miss)
    return allAnswers

print subStringMatchExactlyOneSub("aaa", "a")
print subStringMatchExactlyOneSub("aba", "ac")
print subStringMatchExactlyOneSub("abade", "ac")
