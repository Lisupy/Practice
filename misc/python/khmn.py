#coding=utf-8
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


##如下方程有多少组整数解？ k+h+m+n=30, 其中 0≤k,h,m,n≤10 .

@memoize
def f(k,n):
    if n < 0:return 0
    if k == 0 and n == 0: return 1
    return sum([f(k-i,n-1) for i in range(0,11)])


print f(30,4)

#print C(4,30)-4*C