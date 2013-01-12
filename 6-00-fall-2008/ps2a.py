
from ps2 import *
from sets import Set

def exhaustive_search_largest():
    i = 1    
    while i:    
        for j in xrange(i, i+6):
            if try_to_buy_McNuggets(j) == None:
                i = j + 1
                break 
        else:
            return i-1
        
def iter_serach_largester():
    can_buy = Set([0])
    
    last_can_not_buy = -1
    i = 1
    while i:
        for j in [6, 9, 20]:
            if (i - j) in can_buy:
                can_buy.add(i)
                break
        else:
            last_can_not_buy = i
        if i - last_can_not_buy == 6:
            return last_can_not_buy
        i = i + 1 

f = open('ps2.txt', 'w')
print >>f,"Largest number of McNuggets that cannot be bought in exact quantity: <%d>"%exhaustive_search_largest()
print >>f,"Largest number of McNuggets that cannot be bought in exact quantity: <%d>"%iter_serach_largester()

