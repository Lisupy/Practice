#-------------------------------------------------------------------------------
# Name:        decorator
# Purpose:
#
# Author:      LHP
#
# Created:     29/11/2012
# Copyright:   (c) LHP 2012
# Licence:     <your licence>
#-------------------------------------------------------------------------------


def makebold(fn):
    def wrapped():
        return "<b>" + fn() + "</b>"
    return wrapped

def makeitalic(fn):
    def wrapped():
        return "<i>" + fn() + "</i>"
    return wrapped

@makebold
@makeitalic
def hello():
    return "hello world"

print hello() ## returns <b><i>hello world</i></b>
