###
### template of code for Problem 4 of Problem Set 2, Fall 2008
###

bestSoFar = 0     # variable that keeps track of largest number
                  # of McNuggets that cannot be bought in exact quantity
packages = (6,9,20)   # variable that contains package sizes
can_bought = [0]
for n in range(1, 150):   # only search for solutions up to size 150
    ## complete code here to find largest size that cannot be bought
    ## when done, your answer should be bound to bestSoFar
    for i in packages:
        if n - i in can_bought:
            can_bought.append(n)
            break
    else:
        bestSoFar = n 

print bestSoFar 