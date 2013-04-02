## 词汇 ##
	Python Enhancement Proposals， PEPs

## zen of python ##
	import this
	
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

## Dict ##
```Python
del dict_name[key_name]


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

## bugs? ##
	-4**2 = -16
	`not` is evaluated first;
	`and` is evaluated next;
	`or` is evaluated last.
    bool(0) = False, bool(1) = True
	random.randint(a, b)   # a <= N <= b.