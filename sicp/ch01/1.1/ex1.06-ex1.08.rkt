"====Ex1.6"
;Exercise 1.6.  Alyssa P. Hacker doesn't see why if needs to be provided as a special form. ``Why can't I just define it as an ordinary procedure in terms of cond?'' she asks. Alyssa's friend Eva Lu Ator claims this can indeed be done, and she defines a new version of if:

(define (new-if predicate then-clause else-clause)
  (cond (predicate then-clause)
        (else else-clause)))

;Eva demonstrates the program for Alyssa:

(new-if (= 2 3) 0 5)
5
(new-if (= 1 1) 0 5)
0

;Delighted, Alyssa uses new-if to rewrite the square-root program:

(define (sqrt-iter guess x)
  (new-if (good-enough? guess x)
          guess
          (sqrt-iter (improve guess x)
                     x)))

;What happens when Alyssa attempts to use this to compute square roots? Explain.
"其实就是在new-if展开的时候死循环了"
"其实还不是很理解"

"http://blog.csdn.net/xuanyun/article/details/1331872 
http://jiuren.ycool.com/post.2518051.html
http://www.crazyhotice.com/2011/10/sicp%E7%AC%AC%E4%B8%80%E7%AB%A0%E5%8F%82%E8%80%83%E7%AD%94%E6%A1%88exercise-1-1-1-20/
原因是cond或if作为特殊的运算符,含有它们的表达式的求值实际上是不遵循应用序的,实际上,含有cond或if的表达式求值时总是要先对条件操作数进行求值直到获得true或false,然后再根据得到的结果决定是否对别的操作数进行求值。在采用if的n!版本中,解释器总是先求值(= n 1),再决定对哪个分支求值。这样由于递归的结束条件在每次调用中都是最先求值,无限递归就不会出现了。而newif对cond包装后,cond的特殊性就被遮盖了,newif被当作了普通表达式,灾难出现。"

"====Ex1.7"
;Exercise 1.7.  The good-enough? test used in computing square roots will not be very effective for finding the square roots of very small numbers. Also, in real computers, arithmetic operations are almost always performed with limited precision. This makes our test inadequate for very large numbers. Explain these statements, with examples showing how the test fails for small and large numbers. An alternative strategy for implementing good-enough? is to watch how guess changes from one iteration to the next and to stop when the change is a very small fraction of the guess. Design a square-root procedure that uses this kind of end test. Does this work better for small and large 
(define (good-enough-new? guess last-guess)
  (< (abs (- guess last-guess)) 0.0001))
(define (average x y)
  (/ (+ x y) 2))
(define (sqrt-improve guess x)
  (average guess (/ x guess)))

(define (sqrt-iter-new guess lastguess x)
  (if (good-enough-new? guess lastguess)
      guess
      (sqrt-iter-new (sqrt-improve guess x) 
                 guess
                 x)))
(define (sqrt-new x)
  (sqrt-iter-new 1.0 x x))
(sqrt-new 2)
(sqrt-new 3)
(sqrt-new 4)
(sqrt-new 81)


"====Ex1.8"
;Exercise 1.8.  Newton's method for cube roots is based on the fact that if y is an approximation to the cube root of x, then a better approximation is given by the value

;Use this formula to implement a cube-root procedure analogous to the square-root procedure. (In section 1.3.4 we will see how to implement Newton's method in general as an abstraction of these square-root and cube-root procedures.)
;(define (good-enough? guess x)
;  (< (abs (- (square guess) x)) 1))
(define (cube-root x)
  (cube-root-iter 1.0 x x))
(define (cube-root-improve-guess y x)
  (/ (+ (/ x (* y 
                y)) 
        (* y 2)) 
     3))
(define cube-root-iter-good-enough? good-enough-new?)
(define (cube-root-iter last-guess guess x)
  (define improve-guess (cube-root-improve-guess guess x))
  (if (cube-root-iter-good-enough? last-guess guess)
      guess
      (cube-root-iter guess improve-guess x)))
(cube-root 3.0)
(cube-root 4.0)
(cube-root 8.0)
(cube-root 81.0)