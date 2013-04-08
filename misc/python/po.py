#coding=utf-8
K = 1000000
N = int(raw_input())
G = 0
W = 0
M = 0
 
def f(g):
    w = (M - g * G) / W
    return g * w
 
def search(left, right):
    if right - left < K:
        best = 0
        shield = -1
        for i in range(left, right):
            if f(i) > best:
                best = f(i)
                shield = i
        return shield
    
    left_third = (2 * left + right) / 3;
    right_third = (left + 2 * right) / 3;
 
    if f(left_third) <= f(right_third):
        return search(left_third, right)
    return search(left, right_third)
    
for c in range(N):
    tokens = raw_input().split()
    G = int(tokens[0])
    W = int(tokens[1])
    M = int(tokens[2])
    print search(0, M / G),f(search(0, M / G))
