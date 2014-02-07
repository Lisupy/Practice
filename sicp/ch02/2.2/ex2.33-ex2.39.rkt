(define nil ())
(define (accumulate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumulate op initial (cdr sequence)))))
(accumulate + 0 '(1 2 3))
"====Ex2.33"
(define (my-map p sequence)
  (accumulate (lambda (x y) (cons (p x) y)) 
              nil 
              sequence))
(my-map odd? '(1 2 3))

(define (my-append seq1 seq2)
  (accumulate cons seq2 seq1))
(my-append '(1 2 3) '(4 5 6))

(define (my-length sequence)
  (accumulate (lambda (x y) (+ 1 y)) 0 sequence))
(my-length '(1 2 3 4 5 6))

"====Ex2.34"
(define (horner-eval x coefficient-sequence)
  (accumulate (lambda (this-coeff higher-terms) (+ this-coeff (* higher-terms x)))
                0
                coefficient-sequence))
(horner-eval 2 (list 1 3 0 5 0 1))
(horner-eval 3 (list 1 3 0 5 0 1))
"
>>> def fun(x):
...     return 1+3*x+5*x**3+x**5
...
>>> fun(3)
388
>>> fun(2)
79
>>>
"
"====Ex2.35"
;http://community.schemewiki.org/?sicp-ex-2.35
;我觉得这解法很不match题目本意
(define (count-leaves t)
  (accumulate +  0 (map (lambda (t) (if (pair? t) (count-leaves t) 1)) t)))
(define tree (list 1 2 (list 3 4) (list 5 (list 6 7)))) 
(count-leaves tree) 

"====Ex2.36"
;(car ())
(define (accumulate-n op init seqs)
  (if (null? (car seqs))
      nil
      (cons (accumulate op init (map car seqs))
            (accumulate-n op init (map cdr seqs)))))
(accumulate-n + 0 '((1 2 3) (4 5 6) (7 8 9) (10 11 12)))


"====Ex2.37"
(define m '((1 2 3 4) (5 6 7 8) (9 10 11 12)))
m
(define v '(1 2 3 4))
(define (dot-product v w)
  (accumulate + 0 (map * v w)))
(dot-product v v)
;(map dot-product v)
;(map * v m)
(define (matrix-*-vector m v)
  (map (lambda (x) (dot-product v x))  m))
(matrix-*-vector m v)
(define (transpose mat)
  (accumulate-n cons nil mat))

;(map dot-product v m)
"transpose"
(transpose m)
(define mt (transpose m))
(define (matrix-*-matrix m n)
  (let ((cols (transpose n)))
    (map (lambda (x) (map (lambda (y) (dot-product x y)) cols)) m)))
(matrix-*-matrix m mt)
;http://sicp.org.ua/sicp/Exercise2-37
(define (matrix-*-matrix m n)
  (let ((cols (transpose n)))
    (map (lambda (x) (matrix-*-vector cols x)) m)))
(matrix-*-matrix m mt)
;http://community.schemewiki.org/?sicp-ex-2.37

"====Ex2.38"
(define (fold-left op initial sequence)
  (define (iter result rest)
     (if (null?  rest)
         result
         (iter (op result (car rest))
               (cdr rest))))
  (iter initial sequence))
(define fold-right accumulate)
(fold-right / 1 (list 1 2 3)); 3/2
(fold-left / 1 (list 1 2 3)); 1/6 
(fold-right list nil (list 1 2 3));(1 (2 (3 ())))
(fold-left list nil (list 1 2 3));(((() 1) 2) 3)

"====Ex2.39"
(define (fold-right-reverse sequence)
  (fold-right (lambda (x y) (append y (list x))) nil sequence))
(fold-right-reverse '(1 2 3 4))
(define (fold-left-reverse sequence)
  (fold-left (lambda (x y) (cons y x)) nil sequence))
(fold-left-reverse '(1 2 3 4))