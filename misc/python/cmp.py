#! /usr/bin/env python
#coding=utf-8


def cmp1(x1,y1,x2,y2):
    if x1 < x2: return 1
    if x1 > x2: return -1
    if y1 < y2: return 1
    if y1 > y2: return -1
    return 0

def cmp2(x1,y1,x2,y2):
    return (x1,y1)<=(x2,y2)

