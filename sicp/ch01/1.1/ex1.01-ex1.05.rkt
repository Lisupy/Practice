"====Ex1.1"
10
(+ 5 3 4)
(- 9 1)
(/ 6 2)
(+ (* 2 4) (- 4 6))
(define a 3)
(define b (+ a 1))
(+ a b (* a b))
(= a b)
(if (and (> b a) (< b (* a b)))
    b
    a)
(cond ((= a 4) 6)
      ((= b 4) (+ 6 7 a))
      (else 25))
(+ 2 (if (> b a) b a))
(* (cond ((> a b) a)
         ((< a b) b)
         (else -1))
   (+ a 1))
"====Ex1.2"
(/ (+ 4 
      5 
      (- 2 
         (- 3 
            (+ 6 
               (/ 4 5))))) 
   (* 3 (- 6 2) (- 2 7)))


"====Ex1.3"
(define (testEx1.3 maxsum)
  (cond ((not (= 5 (maxsum 1 2 3))) "TestFail")
        ((not (= 5 (maxsum 2 1 3))) "TestFail")
        ((not (= 5 (maxsum 1 3 2))) "TestFail")
        ((not (= 5 (maxsum 3 1 2))) "TestFail")
        ((not (= 5 (maxsum 2 3 1))) "TestFail")
        ((not (= 5 (maxsum 3 2 1))) "TestFail")
        ((not (= 3 (maxsum 1 1 2))) "TestFail")
        ("TestOK"))) 

"maxsum0"
(define (maxsum0 a b c)
  (max (+ a b) (+ b c) (+ a c)))
(testEx1.3 maxsum0) 
"maxsum1"
(define (maxsum1 a b c)
  (define (maxtwo a b) 
    (if (> a b) a b)) 
  (if (> a b) 
      (+ a 
         (maxtwo c b))
      (+ b (maxtwo c a))))
(testEx1.3 maxsum1)
"maxsum2""智力倒退了，这个是intercessor第一次问这个问题时我给出的解法"
(define (maxsum2 a b c)
  (if (and (>= a c) (>= b c)) 
      (+ a b)
      (maxsum2 b c a)))
(testEx1.3 maxsum2)


"====Ex1.4"
(define (a-plus-abs-b a b)
  ((if (> b 0) + -) a b))

"a加上b的绝对值" 
;直白的写法如下
(define (a-plus-abs-b1 a b)
  (+ a (abs b)))


"====Ex1.5"
;========================================
;Exercise 1.5.  Ben Bitdiddle has invented a test to determine whether the interpreter he is faced with is using applicative-order evaluation or normal-order evaluation. He defines the following two procedures:

(define (p) (p))

(define (test x y)
  (if (= x 0)
      0
      y))

;Then he evaluates the expression

;(test 0 (p))
;========================================
"MIT-GNU Scheme的REPL模式可以正常运行"
"MIT-GNU Scheme的Edwin模式提示出bug了"
"racket上死循环了,选择R5RS"
"我猜:死循环的都是正则序,都在展开的时候死循环了""但，这个想法是错的"
"正则序: 1.展开 2.规约"
"http://www.cppblog.com/cuigang/archive/2011/03/03/39635.html
解决这个问题主要是“正则序”(Normal order)以及“应用序”(Applicative order)展开一个组合式的规则,仔细研究了MIT 6.001课程讲义,网上的各种答案,以及中英文版。我认为,正则序以类似广度优先的方式进行展开。而应用序优先计算子表达式,类似与深度优先。那么对于这个问题,正则序会展开为
=> (if (= 0 0) 0 (p))
=> (if #t 0 (p))
接着，由于这是一个if的special form（特殊形式），就会被展开为
0
而应用序，由于(p)一直可以递归代换，从一开始就会进入一个无限递归中去。
简言之，由于应用序的原因，在 test 表达式 还没有展开为 if 特殊形式（special forms）时， (p)已经陷入了无限递归。 "
"http://oss.timedia.co.jp/show/SICP/ex-1.5"
