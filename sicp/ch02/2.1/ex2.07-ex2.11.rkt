(define (add-interval x y)
  (make-interval (+ (lower-bound x) (lower-bound y))
                 (+ (upper-bound x) (upper-bound y))))
(define (mul-interval x y)
  (let ((p1 (* (lower-bound x) (lower-bound y)))
        (p2 (* (lower-bound x) (upper-bound y)))
        (p3 (* (upper-bound x) (lower-bound y)))
        (p4 (* (upper-bound x) (lower-bound y))))
    (make-interval (min p1 p2 p3 p4)
                   (max p1 p2 p3 p4))))
(define (div-interval x y)
  (mul-interval x
                (make-interval (/ 1 (upper-bound y))
                               (/ 1 (lower-bound y)))))
"====Ex2.07"
(define (make-interval a b) (cons a b))
(define (upper-bound c) (cdr c))
(define (lower-bound c) (car c))
"====Ex2.08"
(define (sub-interval c1 c2)
  (make-interval (- (lower-bound c1) (upper-bound c2))
                 (- (upper-bound c1) (lower-bound c2))))
(define c1 (make-interval -1 10))
(define c2 (make-interval 3 5))
(define cadd (add-interval c1 c2))
(define cmul (mul-interval c1 c2))
(define csub (sub-interval c1 c2))
(define cdiv (div-interval c1 c2))
(upper-bound csub)
(lower-bound csub)

"====Ex2.09"
(define (width-interval c)
  (/ (+ (upper-bound c) 
        (lower-bound c))
     2.0))
(width-interval c1)
(width-interval c2)
"+"
(+ (width-interval c1) (width-interval c2))
(width-interval cadd)
"*"
(* (width-interval c1) (width-interval c2))
(width-interval cmul)
"-"
(- (width-interval c1) (width-interval c2))
(width-interval csub)
"/"
(/ (width-interval c1) (width-interval c2))
(width-interval cdiv)

"====Ex2.10"
(define (new-div-interval x y)
  (if (or (= (upper-bound y) 0)
           (= (lower-bound y) 0)
           (and (> (upper-bound y) 0)
                (< (lower-bound y) 0)))
      (begin (display "Error") (newline))
      (mul-interval x
                    (make-interval (/ 1.0 (upper-bound y))
                                   (/ 1.0 (lower-bound y))))))
(new-div-interval c2 c1)
"====Ex2.11"
(define (new-mul-interval x y)
  (cond ((<= (upper-bound x) 0)
         (cond ((<= (upper-bound y) 0) 
                (make-interval (* (lower-bound x) (lower-bound y))
                               (* (upper-bound x) (upper-bound y))))
               ((>= (upper-bound y) 0)
                (make-interval (* (lower-bound x) (upper-bound y))
                               (* (upper-bound x) (lower-bound y))))
               (else
                (make-interval (* (lower-bound x) (upper-bound y))
                               (* (lower-bound x) (lower-bound y))))))
        ((>= (lower-bound x) 0)
         (cond ((<= (upper-bound y) 0)
                 (make-interval (* (lower-bound x) (upper-bound y))
                                (* (upper-bound x) (lower-bound y))))
                ((>= (lower-bound y) 0)
                 (make-interval (* (lower-bound x) (lower-bound y))
                                (* (upper-bound x) (upper-bound y))))
                (else
                 (make-interval (* (upper-bound x) (lower-bound y))
                                (* (upper-bound x) (upper-bound y))))))
        (else
         (cond ((<= (upper-bound y) 0)
                (make-interval (* (upper-bound x) (lower-bound y))
                               (* (lower-bound x) (lower-bound y))))
               ((>= (lower-bound y) 0)
                (make-interval (* (lower-bound x) (upper-bound y))
                               (* (upper-bound x) (upper-bound y))))
               (else
                (make-interval (min (* (lower-bound x) (upper-bound y))
                                    (* (upper-bound x) (lower-bound y)))
                               (max (* (lower-bound x) (lower-bound y))
                                    (* (upper-bound x) (upper-bound y)))))))))

(define c1 (make-interval -3 -2))
(define c2 (make-interval -2 2))
(define c3 (make-interval 2 3))
(new-mul-interval c1 c1)
(new-mul-interval c1 c2)
(new-mul-interval c1 c3)
(new-mul-interval c2 c1)
(new-mul-interval c2 c2)
(new-mul-interval c2 c3)
(new-mul-interval c3 c1)
(new-mul-interval c3 c2)
(new-mul-interval c3 c3)
"====Ex2.12"
(define (make-center-percent c p)
  (make-interval (* c (- 1 (/ p 100)))
                 (* c (+ 1 (/ p 100)))))
(define (percent i)
  (- 1 (/ (lower-bound i) (center i))))
(define (center i)
  (/ (+ (lower-bound i) 
        (upper-bound i)
        2)))
"====Ex2.13"
;[a*(1-pa), a*(1+pa)]
;[b*(1-pb), b*(1+pb)]
;[a*b*(1-pa)*(1-pb), a*b*(1+pa)*(1+pb)]
"====Ex2.14"
(define (par1 r1 r2)
  (div-interval (mul-interval r1 r2)
                (add-interval r1 r2)))
(define (par2 r1 r2)
  (let ((one (make-interval 1 1)))
    (div-interval one
                  (add-interval (div-interval one r1)
                                (div-interval one r2)))))
(define a (make-center-percent 10 1))
(define b (make-center-percent 50 2))
(display (par1 a b))
(newline)
(display (percent (par1 a b)))
(newline)
(display (par2 a b))
(newline)
(display (percent (par2 a b)))
(newline)
"====Ex2.15"
;par1有3次导致区间扩大的动作
;par2只有2次
"====Ex2.16"

;http://cuitianyi.com/blog/sicp%E4%B9%A0%E9%A2%98%E8%A7%A3%E7%AD%94%EF%BC%9A%E7%AC%AC%E4%BA%8C%E7%AB%A0%EF%BC%88%E4%B8%8A%EF%BC%89/
;; 2.15 我认为这公式的两个形式是完全等价的,在Alyssa系统上产生的区间限界不同,是由于Alyssa系统的本质缺陷,而非两个形式的优劣。
 
;; 2.16 当同一个变量在式子中多次出现时，程序不能意识到它的每次出现必须取相同的值。每个变量出现的次数不同会导致Alyssa系统得出的结果不同。无缺陷的区间算术包等价于以下问题：多变量的多项式，每个变量有其取值范围，求多项式的值的取值范围。这个问题属于 Interval Computation 的范畴：http://www.lsi.upc.edu/~robert/mirror/interval-comp/

;http://en.wikipedia.org/wiki/Interval_arithmetic#Dependency_problem          
                              