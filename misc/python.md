## 词汇 ##
	Python Enhancement Proposals， PEPs

## zen of python ##
	import this
	
## build-in ##
	type(str), type(1), type(bool), type(len)

## 字符串操作 ##
	len是build-in，用len("ABC")
	lower和upper不是，要 "ABC".lower()
	str(3.14) 得到  "3.14"

## 日期库 ##
	from datetime import datetime
	datetime.now()


## 变长参数 ##
* splat arguments

```Python
def favorite_actors(*actors):
    """Prints out your favorite actorS (plural!)"""
    print "Your favorite actors are:" , actors
favorite_actors("Michael Palin", "John Cleese", "Graham Chapman")
```

## bugs? ##
	-4**2 = -16
	`not` is evaluated first;
	`and` is evaluated next;
	`or` is evaluated last.
    bool(0) = False, bool(1) = True