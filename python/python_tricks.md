enumerate()的可选参数start
```python
>>> list(enumerate(range(5), 3))
[(3, 0), (4, 1), (5, 2), (6, 3), (7, 4)]
```

`type(var)` `type(func)`
 
`is`

`exec(str)`

`locals()`

用dis显示字节码
[帮助文档](http://docs.python.org/2/library/dis.html "")
```python
>>> import dis
>>> dis.dis(f1)
>>> dis.dis(f2.func_code)
```

`global`
无论global关键字在何处，它的声明对整个函数体都是有效的。当编译器发现函数体中存在“global x”语句，它就把变量x当作全局变量处理。

和global关键字一样，无论对变量的赋值出现在何处，这个变量都会被当作局域变量。

# inspect
* frame对象`import inspect`
* 通过`inspect.stack()`可以获得一个堆栈列表

# 闭包
```python
def f(x):
    y = 1
    def h(z):
        return x+y+z
    return h
```