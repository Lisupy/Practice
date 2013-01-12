#Problem Set 1
#Name: darrenhp

def try_to_buy_McNuggets(n):
    for i in xrange(0,n):
        for j in xrange(0, n):
            for k in xrange(0, n):
                if 6*i + 9*j + 20*k == n:
                    return (i, j, k)


