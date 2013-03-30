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

def rect_cut(n):
	if n == 0:return 1
	return C(2,n)*8+2

print [rect_cut(i) for i in range(11)]
