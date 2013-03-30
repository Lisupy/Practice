#coding=utf-8

n = int(raw_input())
def f(G,M,W,g):
    w = (M - g * G) / W
    return g * w


#print (M-G*x)/W*x
for i in range(n):
    G,W,M = map(int, raw_input().split())
    ans = []
    for M1 in range(M-W,M+W+1):
        mid = M1/(G*2)
        l = [(f(G,M,W,g),g) for g in range(mid-128,mid+128) if f(G,M1,W,g) == f(G,M, W,g)]
        if len(l) == 0:
            continue
        mm = max([x for (x,y) in l])
        l = [(x,y) for (x,y) in l if x == mm]
        print l
        ans += l
    mm = max([x for (x,y) in ans])
    ans = [(x,y) for (x,y) in ans if x == mm]
       
    print ans
   # l = [x for x in l if x[0] == ans]
    print "Case #%d: %d"%((i+1), ans[0][1])