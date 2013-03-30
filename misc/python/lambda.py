#!/usr/bin/python


def add(x):
	return lambda y: x+y

incer = 10

fun = add(incer)
print fun(4)
incer =15 
print fun(4)