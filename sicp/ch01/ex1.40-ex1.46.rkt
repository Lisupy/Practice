"pre define"
(define (average x y) 
  (/ (+ x y) 2.0)) 

(define (average-damp f) 
  (lambda (x) (average x (f x)))) 
(define tolerance 0.00001)
(define (fixed-point f first-guess)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) tolerance))
  (define (try guess)
    (let ((next (f guess)))
      (if (close-enough? guess next)
          next
          (try next))))
  (try first-guess))

(define (deriv g)
  (lambda (x)
    (/ (- (g (+ x dx)) (g x))
          dx)))
(define dx 0.00001)

(define (newton-transform g)
  (lambda (x)
    (- x (/ (g x) ((deriv g) x)))))

(define (newtons-method g guess)
  (fixed-point (newton-transform g) guess))

(define (square x) (* x x))
(define (dec x) (- x 1))
(define (inc x) (+ x 1))

(define (pow b p)
  (define (iter res a n)
    (if (= n 0)
        res
        (if (even? n)
            (iter res (* a a) (/ n 2))
            (iter (* res a) a (- n 1)))))
  (iter 1 b p))
"====Ex1.40"
(define (cubic a b c)
  (lambda (x) (+ (* x x x)
                 (* a x x)
                 (* b x)
                 c)))
(define x (newtons-method (cubic 1 2 3) 1))
x
((cubic 1 2 3) x)

"====Ex1.41"
(define (double f)
  (lambda (x) (f (f x))))
(((double (double double)) inc) 5)
; (2*2) * (2*2) = 16 ; 16 + 5  = 21

"====Ex1.42"
(define (my-compose f g)
  (lambda (x) (f (g x))))
((my-compose square inc) 6)
((compose square inc) 6)

"====Ex1.43"
(define (repeated f n)
  (if (= n 1)
      f
      (lambda (x) 
        ((compose f (repeated f (dec n))) x))))
((repeated square 2) 5)

"====Ex.144"
(define (smooth f)
  (/ (+ (f (- x dx)) 
        (f x)
        (f (+ x dx))) 
     3))
(define (n-fold-smooth n)
  (lambda (f) (repeated smooth n) f))
(((n-fold-smooth 10) square) 10.0)
"====Ex1.45"
;http://community.schemewiki.org/?sicp-ex-1.45
(define (get-max-pow n) 
  (define (iter p r) 
    (if (< (- n r) 0) 
        (- p 1) 
        (iter (+ p 1) (* r 2))))   
  (iter 1 2)) 
;http://community.schemewiki.org/?sicp-ex-1.45
(define (nth-root n x) 
  (fixed-point ((repeated average-damp (get-max-pow n)) 
                (lambda (y) (/ x (pow y (- n 1))))) 
               1.0)) 
(nth-root 5 32)

"====Ex1.46"
(define (iterative-improve enough-good? improve)
  (lambda (guess)             
    (if (enough-good? guess (improve guess))
        guess
        ((iterative-improve enough-good? improve) (improve guess))))) 
(define (my-sqrt x)
  (define (close-enough? v1 v2)
    (< (abs (- v1 v2)) tolerance))
  ((iterative-improve close-enough? (lambda (y) (average (/ x y) y))) 1.0))
(my-sqrt 2)
