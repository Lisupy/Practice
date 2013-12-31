# 参考 #
* [https://zh.wikipedia.org/wiki/Prolog](https://zh.wikipedia.org/wiki/Prolog)
* [https://en.wikipedia.org/wiki/Prolog](https://en.wikipedia.org/wiki/Prolog) 
* [http://www.gprolog.org/](http://www.gprolog.org/)

# Day 1 #

## 一些免费的Prolog教程 ##
* prolog小教程.chm
* [Learn Prolog Now](http://www.learnprolognow.org)
* [Prolog Tutorial](http://www.csupomona.edu/~jrfisher/www/prolog_tutorial/contents.html)

## 一个技术论坛 ##
* [http://stackoverflow.com/questions/tagged/prolog](http://stackoverflow.com/questions/tagged/prolog "")
*  [http://zh.reddit.com/r/prolog/](http://zh.reddit.com/r/prolog/ "")
* [http://prolog.longluntan.net/](http://prolog.longluntan.net/ "")

## 一个你正在使用的Prolog版本的在线参考 ##
* [http://www.gprolog.org/#manual](http://www.gprolog.org/#manual)


# Day 2 #

## 一些斐波那契数列和阶乘的实现
```
fact(1, 1).
fact(N, What) :-
    N > 1, 
    N1 is N - 1,
    fact(N1, What1),
    What is N * What1.
```
```
fib(1, 1).
fib(2, 1).
fib(N, R) :-
    N >= 2,
    N1 is N - 1,
    N2 is N - 2, 
    fib(N1, R1), 
    fib(N2, R2), 
    R is R1 + R2. 
```
* 自己实现了，is表达式很蛋疼

## 看看社区里面，Prolog用于解决什么问题
* 开发Erlang编译器。。
* [http://stackoverflow.com/questions/130097/real-world-prolog-usage](http://stackoverflow.com/questions/130097/real-world-prolog-usage "")
* Some companies that use Prolog:
 * http://www.meridiansystems.com/products/prolog/construction-project-management.asp
 * http://www.intologic.com/
 * http://www.sics.se/isl/sicstuswww/site/customers.html
 * powerset (acquired by microsoft)
*[The Practical Application of Prolog](http://www.drdobbs.com/parallel/the-practical-application-of-prolog/184405220 "")
## 汉诺塔问题
[http://www.csupomona.edu/~jrfisher/www/prolog_tutorial/2_3.html](http://www.csupomona.edu/~jrfisher/www/prolog_tutorial/2_3.html "")
```
move(1,X,Y,_) :-  
    write('Move top disk from '), 
    write(X), 
    write(' to '), 
    write(Y), 
    nl. 
move(N,X,Y,Z) :- 
    N>1, 
    M is N-1, 
    move(M,X,Z,Y), 
    move(1,X,Y,_), 
    move(M,Z,Y,X).  
```
* 都不像是声明式逻辑编程了

## 有哪些处理not表达式的问题？ 为什么在使用Prolog时要小心地对待否定
```
% `not(X)` doesn't mean that X is false (like `¬X` would), it means that X can't
% be proven true. Something else you have to be careful with is putting negated
% predicates in the right order. Negation as failure is implemented using the
% `cut` and `fail` predicates. The short story is negating a predicate can
% cause subsequent predicates to be ignored.
%
% For a better and more in-depth explanation of `cut` and negation as failure, I
% strongly recommend the following links:
%
% * Negation In Prolog - http://pwnetics.wordpress.com/2011/04/10/negation-in-prolog/
% The author uses the wallace and grommit example from this book to show how
% assuming logical negation can lead to subtle errors.
%
% * Negation as failure - http://cs.union.edu/~striegnk/learn-prolog-now/html/node90.html#sec.l10.negation.as.failure
% A highly readable explanation of how negation as failure really works. Here is
% one of the opening paragraphs which really helped make it click for me:
%
% > As a first step, let's introduce another built in predicate fail/0. As its name
% > suggests, fail is a special symbol that will immediately fail when Prolog
% > encounters it as a goal. That may not sound too useful, but remember: when
% > Prolog fails, it tries to backtrack. Thus fail can be viewed as an instruction
% > to force backtracking. And when used in combination with cut, which blocks
% > backtracking, fail enables us to write some interesting programs, and in
% > particular, it lets us define exceptions to general rules.   
%
% If you find you need more background information first, try the page where they
% introduce cut: http://cs.union.edu/~striegnk/learn-prolog-now/html/node88.html#sec.l10.cut
```
`not`是不能证明的意思

# day 3 #
## Prolog 也有输入输出功率。找出可以打印变量的print谓词。
 * 就是`print`

## 找到一种通过print谓词仅输出成功的解决方法的方式。它是如何工作的？
 * 外面套一层Wrapper？




