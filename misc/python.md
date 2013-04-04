## 词汇 ##
	Python Enhancement Proposals， PEPs
	List Comprehensions
## zen of python ##
	import this

## File and IO ##
```python
with open("file", "mode") as variable:
    # Read or write to the file


if my_file.closed == False:
	my_file.close()
```
	
## build-in ##
```python
print type(str), type(1), type(bool), type(len)
print type(1) == int
print type("") == str
print dir(), dir(__doc__), dir(__builtins__)

>>> zip(['a','b','c'],[1,2,3],['a','b','c'])
[('a', 1, 'a'), ('b', 2, 'b'), ('c', 3, 'c')]

```

## 字符串操作 ##
	len是build-in，用len("ABC")
	lower和upper不是，要 "ABC".lower()
	str(3.14) 得到  "3.14"

## Math Lib ##
	import math
	math.pi

## 日期库 ##
```python
	from datetime import datetime
	datetime.now()
```

## 二进制表示 ##

```python
print 0b1,    #1
print 0b10,   #2
print 0b11,   #3
print 0b100,  #4
print 0b101,  #5
print 0b110,  #6
print 0b111   #7
print 0b1 + 0b11
print 0b11*0b11
print oct(100) #'0144'
print bin(100) #'0b1100100'
print hex(100) #'0x64'
print int(0b11001001) # 201
```

## 变长参数 ##
* splat arguments

```python
"""actors is a tuple"""
def favorite_actors(*actors):
    """Prints out your favorite actorS (plural!)"""
    print "Your favorite actors are:" , actors
favorite_actors("Michael Palin", "John Cleese", "Graham Chapman")
```

## str ##
```python
",".join(['1','2','3'])  # "1,2,3"
", ".join(['1','2','3']) # "1, 2, 3"
```

## List ##

```python
animals = ["aardvark", "badger", "duck", "emu", "fennec fox"]

duck_index = animals.index("duck")  
animals.insert(duck_index, "cobra")
animals.pop(1)
animals.append("cobra")
animals.remove("cobra")
animals.sort()

for index, item in enumerate(animals):
    print index, item
```

* List Slice [start:end:stride]

```python
>>> range(1,11)[::-1]
[10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
```

## Dict ##
```Python
del dict_name[key_name]

>>> {'A':1, 'B':2, 'C':3}.items()
[('A', 1), ('C', 3), ('B', 2)]

>>> {'A':1, 'A':2, 'C':3}
{'A': 2, 'C': 3}
>>> {'A':1, 'A':2, 'C':3}.keys()
['A', 'C']

>>> {'A':1, 'A':1, 'C':1}.values()
[1, 1]
```

## while/break, for/break ##
	Something completely different about Python is the while/else construction. while/else is similar to if/else, but there is a difference: the else block will execute anytime the loop condition is evaluated to False. This means that it will execute if the loop is never entered or if the loop exits normally. If the loop exits as the result of a break, the else will not be executed.

```python
for i in range(10):
	if i == 10:
		break
else:
	print i
```

## OO, Class ##

* super 和调用父类的同名方法

* __repr__
```python
class Point3D(object):
	def __init__(self, x, y, z):
		self.x,self.y,self.z = x,y,z
	def __repr__(self):
		return str((self.x,self.y,self.z))
```

	When dealing with classes, you can have variables that are available everywhere (global variables), variables that are only available to members of a certain class (member variables), and variables that are only available to particular instances of a class (instance variables).


```python
class Animal(object):
	def __init__(self):
		pass

class NewClass(object):
    # Class magic here

class DerivedClass(Base):
   def some_method(self):
       super(DerivedClass, self).meth()
```


## bugs? ##
	-4**2 = -16
	`not` is evaluated first;
	`and` is evaluated next;
	`or` is evaluated last.
    bool(0) = False, bool(1) = True
	random.randint(a, b)   # a <= N <= b.