enumerate()�Ŀ�ѡ����start
```python
>>> list(enumerate(range(5), 3))
[(3, 0), (4, 1), (5, 2), (6, 3), (7, 4)]
```

`type(var)` `type(func)`
 
`is`

`exec(str)`

`locals()`

��dis��ʾ�ֽ���
[�����ĵ�](http://docs.python.org/2/library/dis.html "")
```python
>>> import dis
>>> dis.dis(f1)
>>> dis.dis(f2.func_code)
```

`global`
����global�ؼ����ںδ����������������������嶼����Ч�ġ������������ֺ������д��ڡ�global x����䣬���Ͱѱ���x����ȫ�ֱ�������

��global�ؼ���һ�������۶Ա����ĸ�ֵ�����ںδ�������������ᱻ�������������

# inspect
* frame����`import inspect`
* ͨ��`inspect.stack()`���Ի��һ����ջ�б�

# �հ�
```python
def f(x):
    y = 1
    def h(z):
        return x+y+z
    return h
```