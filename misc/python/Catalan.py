#coding=utf-8

#__all__ = ["memoize"]
import cPickle

def memoize(function, limit=None):
    if isinstance(function, int):
        def memoize_wrapper(f):
            return memoize(f, function)

        return memoize_wrapper

    dict = {}
    list = []
    def memoize_wrapper(*args, **kwargs):
        key = cPickle.dumps((args, kwargs))
        try:
            list.append(list.pop(list.index(key)))
        except ValueError:
            dict[key] = function(*args, **kwargs)
            list.append(key)
            if limit is not None and len(list) > limit:
                del dict[list.pop(0)]

        return dict[key]

    memoize_wrapper._memoize_dict = dict
    memoize_wrapper._memoize_list = list
    memoize_wrapper._memoize_limit = limit
    memoize_wrapper._memoize_origfunc = function
    memoize_wrapper.func_name = function.func_name
    return memoize_wrapper

@memoize
def factorial(n):
    return reduce(lambda a,b:a*b, range(1,n+1), 1)
    

@memoize
def C(k,n):
    return factorial(n)/(factorial(k)*factorial(n-k))

@memoize
def Catalan_1(n):
    if n == 0:
        return 1
    s = 0;
    for i in range(0,n):
        s += Catalan_1(i)*Catalan_1(n-i-1)
    return s

@memoize(100)
def Catalan_2(n):
    return C(n,2*n)-C(n-1,2*n)

print [Catalan_1(i) for i in range(100)]
print [Catalan_2(i) for i in range(100)]