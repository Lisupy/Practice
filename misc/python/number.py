#coding=utf-8

def lcm(a,b):
    return a*b/gcd(a,b)

def gcd(a,b):
    if a%b == 0:     return b
    else:            return gcd(b,a%b)

m = reduce(lcm, range(1,15))


def sol(a,b,k):
    f = [-1 for i in range(m)]
    f[a] = 0
    l.append(a)
    while len(l) != 0:
        t1 = l[0]
        l.pop(0)
        for i in range(1,k):
            t2 = t1%k
            if f[t2] != -1:
                continue
            f[t2] = f[t1]+1
            l.append(t2)
    return f[b] 


def solve(a,b,k):
    return sol(a%m,0,k)+sol(m,b%m,k)+((a-a%m)-(b-b%m))/m*sol(m,0,k)

a,b,k =map(int,raw_input().split())