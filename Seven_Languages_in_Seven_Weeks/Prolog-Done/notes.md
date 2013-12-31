Prolog
==============
prolog是Programming in LOGic的缩写

# 开发环境与IDE
 * GNU Prolog
   * gprolog
   * change_directory('...').
   * `?- debug`
   * `a`, `;`
   * 
# 注释
 * 行注释： `% comments `
 * 块注释： `/* comments */`

# 输入输出(IO)
 * `write`
 * `print`
 * `nl` newline
 * 字符串用单引号，双引号是不行的
 * 可定义一个`main :- `, main可换成其它东西    


# 变量（variable）、原子（atom）、整数（integer）、结构（structure）
* 小写字母开头 -> 原子
* 大写字母或下划线开头 -> 变量
* `customer/3`表示customer有3个参数

# 比较运算, 大于等于`>=`, 小于等于 `=<`
```
| ?- 1 =< 2.

yes
| ?- 1 >= 2.

no
| ?- 1 => 2.
uncaught exception: error(syntax_error('user_input:152 (char:3) . or operator expected after expression'),read_term/3)
| ?- 1 <= 2.
uncaught exception:
```
* 蛋疼啊
* 算术运算在prolog里没公理化？ 摘自评论。。

# 事实，规则
```prolog
likes(wallace, cheese).
likes(grommit, cheese).
likes(wendolene, sheep).

friend(X, Y) :- \+(X = Y), likes(X, Z), likes(Y, Z).
```
```prolog
| ?- friend(wallace, wallace).

no
| ?- likes(What, sheep).

What = wendolene

yes
```
* likes 语句是事实
* friends语句是规则
  * `:-` 右边是子目标(subgoal)。子目标之间以逗号分隔，有3个子目标。
  * `\+` 是取反操作
* 填空是指查询命令带变量（大写开头）
  * 如果找到多个，会逐个询问，按`;`继续显示下一个，按`a`显示全部，或者`a`跟着命令后

# 列表与元组
* 变成容器 -> 列表 -> `[1, 2, 3]`
* 定长容器 -> 元组 -> `(1, 2, 3)`

# 合一（unification），也叫联合，类似模式匹配
```prolog
cat(lion).
cat(tiger).

dorothy(X, Y, Z) :- X = lion, Y= tiger, Z = bear.
twin_cats(X, Y) :- cat(X), cat(Y).
```
* `=`表示`合一`：找出那些使规则两侧匹配的值

```prolog
| ?- (A, 2, C) = (1, B, 3).

A = 1
B = 2
C = 3

yes
```
```
| ?- [a, b, c] = [Head|Tail].

Head = a
Tail = [b,c]

yes
| ?- [a] = [Head|Tail].

Head = a
Tail = []

yes
| ?- [] = [Tail].

no

| ?- [a, b, c] = [a | [Head| Tail] ].

Head = b
Tail = [c]

yes
```
 * 配合列表看起来比较坑。语法理解比较怪

```
| ?- [a, b, c, d, e] = [_, _| [Head|_]].

Head = c

yes
``` 
 * `_` 为 通配符

# is
```
| ?- A = 2, B = A + 1.

A = 2
B = 2+1

yes
| ?- A = 2, B is A + 1 .

A = 2
B = 3

yes
| ?- 2 = 1 + 1.

no
| ?- 2 is 1 + 1.

yes
| ?- 1 + 1 = 2.

no
| ?- 1 + 1 is 2.

no
```
 * `is`应该是用于算术运算中且只对右边的有效
   * 等号`=`并不会运算，很dt的性质，写个fib和factorial都蛋疼
 * 可用于列表求和，计算长度等

# 递归与“模式匹配”
```prolog
father(zeb,         john_boy_sr).
father(john_boy_sr, john_boy_jr).

ancestor(X, Y) :-
    father(X, Y).
ancestor(X, Y) :-
    father(X, Z), ancestor(Z, Y).
```
* “句号“表示”或“，有点像”模式匹配“
* ”逗号“表示”与“
```
```
concatenate([], List, List).
concatenate([Head|Tail1], List, [Head|Tail2]) :-
    concatenate(Tail1, List, Tail2).
```
 * 一段漂亮代码

# 几个谓词
 *`fd_domain(List, LowerBound, UpperBound)`
 *`fd_all_different(List)`
 *`length(List, N)`
 *`member(Elem, List)` 

# 原理
 * 看”垂钓听竹轩“的chm或网站