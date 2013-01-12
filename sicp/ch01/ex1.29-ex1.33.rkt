
"====Ex1.29"
(define (cube x) (* x x x))
(define (inc n) (+ n 1))
(define (sum-cubes a b)
  (sum cube a inc b))
(define (sum term a next b)
  (if (> a b)
      0
      (+ (term a)
         (sum term (next a) next b))))
(define (integral f a b dx)
  (define (add-dx x) (+ x dx))
  (* (sum f (+ a (/ dx 2.0)) add-dx b)
     dx))
(integral cube 0 1 0.01)
(integral cube 0 1 0.001)
;=====================
(define (Simpson f a b n)
  (define h (/ (- b a)
               n))
  (define (iter k)
    (define y (f (+ a
                    (* k h))))
    (cond ((= k 0) (+ y (iter (inc k))))
           ((= k n) y)
           ((odd? k) (+ (* 4 y) (iter (inc k))))
           (else (+ (* 2 y) (iter (inc k))))))
  (* (/ h 3)
     (iter 0)))
(Simpson cube 0 1. 100) ;这里需要用“1.”，要不然就变成了分数形式，一定是1/4
(Simpson cube 0 1. 1000)



"====Ex1.30"
;Exercise 1.30.  The sum procedure above generates a linear recursion. The procedure can be rewritten so that the sum is performed iteratively. Show how to do this by filling in the missing expressions in the following definition:

;(define (sum term a next b)
;  (define (iter a result)
;    (if <??>
;        <??>
;        (iter <??> <??>)))
;  (iter <??> <??>))
(define (sum-recursive term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) 
              (+ result (term a)))))
  (iter a 0))

(define sum sum-recursive)
;(define sum +) ;这句可以测试sum是不是真的有效了
(integral cube 0 1 0.01)
(integral cube 0 1 0.001)

"====Ex1.31"
(define (product-recursive term a next b)
  (if (> a b)
      1
      (* (term a)
         (product-recursive term (next a) next b))))
(define (product-iterative term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) (* result (term a)))))
  (iter a 1))




(define (factorial f a b dx)
  (define (next x)
    (+ x dx))
  (product f a next b))
(define (pi-term n)
  (if (odd? n) 
      (/ (+ n 1) (+ n 2))
      (/ (+ n 2) (+ n 1))))
(define product product-recursive)
"recursive"
(* 4 (factorial pi-term 1. 10000 1))
(* 4 (factorial pi-term 1. 100000 1))  
;(* 4 (factorial pi-term 1. 1000000 1))  ;这个爆内存了
"iterative"
(define product product-iterative)
(* 4 (factorial pi-term 1. 10000 1))
(* 4 (factorial pi-term 1. 1000000 1))  
; (* 4 (factorial pi-term 1. 10000000 1)) ；这个还是可以跑的，就是比较卡


"====Ex1.32"

"===recursive"
(define (accumulate-recursive combiner null-value term a next b)
  (if (> a b)
      null-value
      (combiner (term a) 
                (accumulate-recursive combiner null-value term (next a) next b))))
(define (sum term a next b) (accumulate-recursive + 0 term a next b)) 
(integral cube 0 1 0.01)
(integral cube 0 1 0.001)

(define (product term a next b) (accumulate-recursive * 1 term a next b))
;(define product 1)
(* 4 (factorial pi-term 1. 10000 1))
(* 4 (factorial pi-term 1. 100000 1))  

"====iterative"
(define (accumulate-iterative combiner null-value term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) 
              (combiner result (term a)))))
  (iter a null-value))

(define (sum term a next b) (accumulate-iterative + 0 term a next b)) 
(integral cube 0 1 0.01)
(integral cube 0 1 0.001)

(define (product term a next b) (accumulate-iterative * 1 term a next b))
;(define product 1)
(* 4 (factorial pi-term 1. 10000 1))
(* 4 (factorial pi-term 1. 100000 1))  

"====Ex.13"

;===prime?
(define (square x)
  (* x x))
(define (smallest-divisor n)
  (find-divisor n 2))
(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divides? test-divisor n) test-divisor)
        (else (find-divisor n (+ test-divisor 1)))))
(define (divides? a b)
  (= (remainder b a) 0))

(define (prime? n)
  (= n (smallest-divisor n)))

;=====
(define (filtered-accumulate filter? combiner null-value term a next b)
  (define (new-term a)
    (if (filter? a)
        (term a)
        null-value))
  (accumulate-iterative combiner null-value new-term a next b))
(define (sum-prime a b)
  (define (sum-prime-term x) x)
  (define (sum-prime-next x) (+ x 1))
  (filtered-accumulate prime? + 0 sum-prime-term a sum-prime-next b))
(sum-prime 1 1000)

(define (product-relatively-prime n)
  (define (inner-term x) x)
  (define (inner-next x) (+ 1 x))
  (define (relatively-prime x) (= (gcd n x) 1))
  (filtered-accumulate relatively-prime * 1 inner-term 1 inner-next n))
(product-relatively-prime 100)
