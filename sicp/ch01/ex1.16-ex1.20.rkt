"====Ex1.16"
(define (square x)
  (* x x))
;=================
(define (brute-force-expt b n)
  (if (= n 0)
      1
      (* b (expt b (- n 1)))))
;=================

(define (fast-expt-recursive b n)
  (cond ((= n 0) 1)
        ((even? n) (square (fast-expt-recursive b (/ n 2))))
        (else (* b (fast-expt-recursive b (- n 1))))))
;===================================
(define (fast-expt-iterative b n)
  (define (fast-expt-iter s a n)
    (cond ((= n 0) s)
          ((odd? n) (fast-expt-iter (* s a) a (- n 1)))
          (else (fast-expt-iter s (square a) (/ n 2)))))
  (fast-expt-iter 1 b n))
(brute-force-expt 2 10)
(fast-expt-iterative 2 10)
(fast-expt-recursive 2 10)

"====Ex1.17"
;Exercise 1.17.  The exponentiation algorithms in this section are based on performing exponentiation by means of repeated multiplication. In a similar way, one can perform integer multiplication by means of repeated addition. The following multiplication procedure (in which it is assumed that our language can only add, not multiply) is analogous to the expt procedure:

;(define (* a b)
;  (if (= b 0)
;      0
;      (+ a (* a (- b 1)))))

;This algorithm takes a number of steps that is linear in b. Now suppose we include, together with addition, operations double, which doubles an integer, and halve, which divides an (even) integer by 2. Using these, design a multiplication procedure analogous to fast-expt that uses a logarithmic number of steps.
(define (*-recursive a b)
  (cond ((= b 0) 0)
        ((odd? b) (+ (*-recursive a (- b 1)) a))
        (else (*-recursive (+ a a) (/ b 2)))))
(*-recursive 10 0)
(*-recursive 10 1)
(*-recursive 1 10)
(*-recursive 0 0)
(*-recursive 1 10)
(*-recursive 10 10)

"====Ex1.18"
;Exercise 1.18.  Using the results of exercises 1.16 and 1.17, devise a procedure that generates an iterative process for multiplying two integers in terms of adding, doubling, and halving and uses a logarithmic number of steps.40

(define (*-iterative a b)
  (define (*-iter b a p)
    (cond ((= b 0) p)
          ((odd? b) (*-iter (- b 1) a (+ p a)))
          (else (*-iter (/ b 2) (+ a a) p))))
  (*-iter b a 0))
(*-iterative 10 0)
(*-iterative 10 1)
(*-iterative 1 10)
(*-iterative 0 0)
(*-iterative 1 10)
(*-iterative 10 10)
;scheme要一次写对很难，特别是迭代式

"====Ex1.19"
;Exercise 1.19.   There is a clever algorithm for computing the Fibonacci numbers in a logarithmic number of steps. Recall the transformation of the state variables a and b in the fib-iter process of section 1.2.2: a  a + b and b  a. Call this transformation T, and observe that applying T over and over again n times, starting with 1 and 0, produces the pair Fib(n + 1) and Fib(n). In other words, the Fibonacci numbers are produced by applying Tn, the nth power of the transformation T, starting with the pair (1,0). Now consider T to be the special case of p = 0 and q = 1 in a family of transformations Tpq, where Tpq transforms the pair (a,b) according to a  bq + aq + ap and b  bp + aq. Show that if we apply such a transformation Tpq twice, the effect is the same as using a single transformation Tp'q' of the same form, and compute p' and q' in terms of p and q. This gives us an explicit way to square these transformations, and thus we can compute Tn using successive squaring, as in the fast-expt procedure. Put this all together to complete the following procedure, which runs in a logarithmic number of steps:41

;(define (fib n)
;  (fib-iter 1 0 0 1 n))
;(define (fib-iter a b p q count)
;  (cond ((= count 0) b)
;        ((even? count)
;         (fib-iter a
;                   b
;                   <??>      ; compute p'
;                   <??>      ; compute q'
;                   (/ count 2)))
;        (else (fib-iter (+ (* b q) (* a q) (* a p))
;                        (+ (* b p) (* a q))
;                        p
;                        q
;                        (- count 1)))))

;===========
(define (fib n)
  (cond ((= n 0) 0)
        ((= n 1) 1)
        (else (+ (fib (- n 1))
                 (fib (- n 2))))))
;===========
(define (fib-iterative n)
  (fib-iter-countdown 1 0 n))

(define (fib-iter-countdown a b count)
  (if (= count 0)
      b
      (fib-iter-countdown (+ a b) a (- count 1))))
;==============
;第一次
;a <- bq+aq+ap
;b <- bp+aq
;第二次
;a <- (bp+aq)q + (bq+aq+ap)q + (bq+aq+ap)p
;   = b(pq+qq+pq) + a(qq+qq+pq+qp+pp)
;   = b(2pq+qq) + a(2qq+2pg+pp)
;        令q'= 2pq+qq
;   = bq' + aq' + a(qq+pp)
;        令p'= qq+pp
;   = bq'+aq'+ap'
;b <- (bp+aq)p + (bq+aq+ap)q
;   = b(pp+qq) + a(pq+qq+pq)
;   = bp' + aq'
(define (fib-new n)
  (fib-iter 1 0 0 1 n))
(define (fib-iter a b p q count)
  (cond ((= count 0) b)
        ((even? count)
         (fib-iter a
                   b
                   (+ (* q q) (* p p));<??>      ; compute p'
                   (+ (* 2 p q) (* q q));<??>      ; compute q'
                   (/ count 2)))
        (else (fib-iter (+ (* b q) (* a q) (* a p))
                        (+ (* b p) (* a q))
                        p
                        q
                        (- count 1)))))
;===============
(fib 10)
(fib-iterative 1000)
(fib-new 10)
(fib-new 1000)

"====Ex1.20"
;Exercise 1.20.  The process that a procedure generates is of course dependent on the rules used by the interpreter. As an example, consider the iterative gcd procedure given above. Suppose we were to interpret this procedure using normal-order evaluation, as discussed in section 1.1.5. (The normal-order-evaluation rule for if is described in exercise 1.5.) Using the substitution method (for normal order), illustrate the process generated in evaluating (gcd 206 40) and indicate the remainder operations that are actually performed. How many remainder operations are actually performed in the normal-order evaluation of (gcd 206 40)? In the applicative-order evaluation?
"http://www.cppblog.com/cuigang/archive/2008/03/27/45554.html"
(define (my-gcd a b count)
  (if (= b 0)
      count
      (my-gcd b (remainder a b) (+ 1 count))))
(my-gcd 206 40 0)
"我是懒人"
"懒惰、傲慢、缺乏耐性是程序员的三大美德"
"Larry Wall:The three chief virtues of a programmer are: Laziness, Impatience and Hubris."