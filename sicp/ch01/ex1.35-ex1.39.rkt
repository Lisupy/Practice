"====Ex1.35"
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
"golden ratio:"
(fixed-point (lambda (x) (+ 1 (/ 1 x))) 1.0)

"====Ex1.36"
(define (fixed-point-print f first-guess)
  (fixed-point (lambda (x) 
                 (display x) 
                 (newline)
                 (f x)) first-guess))
(fixed-point-print (lambda (x)
                     (/ (log 1000)
                        (log x))) 2)
(define (average x y) (/ (+ x y) 2))
(fixed-point-print (lambda (x)
                     (average x (/ (log 1000)
                        (log x)))) 2)


"====Ex1.37"
"recursive"
(define (cont-frac-recursive n d k)
  (define (cont-frac-iter i)
    (define (next-result) 
      (/ (n i)
           (+ (d i)
              (cont-frac-iter (+ i 1)))))
    (if (> i k) 
        1
        (next-result)))
  (cont-frac-iter 1))
(cont-frac-recursive (lambda (i)  (display i) (display ",") 1.0)
           (lambda (i) 1.0)
           10)
"iterative"
(define (cont-frac-iterative n d k)
  (define (iter i result)
    (define (next-result) 
      (iter (- i 1) 
            (/ (n i) 
               (+ (d i)
                  result))))
    (if (= 0 i)
        result
        (next-result)))
  (iter k 0))
(cont-frac-iterative (lambda (i) (display i) (display ",") 1.0)
           (lambda (i) 1.0)
           11)

"===Ex1.38"
(define (get-e k)
  (let ((e-2 (cont-frac-recursive (lambda (i) 1.0)
                                  (lambda (i)
                                    (if (= (remainder i 3) 2)
                                        i
                                        1)) 11)))
    (+ e-2 2)))
(get-e 11)

"====Ex1.39"
(define (tan-cf x k)
  (let ((neg-square-x  (- (* x x))))
    (cont-frac-recursive (lambda (i) (if (= i 1) x neg-square-x))
                         (lambda (i) (- (* 2.0 i) 1.0)) 
                         k)))

(tan-cf 0.5 10)
  
