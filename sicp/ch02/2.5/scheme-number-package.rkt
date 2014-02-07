(define (install-scheme-number-package)
  (define (tag x)
    (attach-tag 'scheme-number x))
  (put 'add '(scheme-number scheme-number)
       (lambda (x y) (tag (+ x y))))
  (put 'sub '(scheme-number scheme-number)
       (lambda (x y) (tag (- x y))))
  (put 'mul '(scheme-number scheme-number)
       (lambda (x y) (tag (* x y))))
  (put 'div '(scheme-number scheme-number)
       (lambda (x y) (tag x)))
  (put 'make 'scheme-number
       (lambda (x) (tag x)))
  ;;Ex2.79
  (put 'equ? '(scheme-number scheme-number)
       (lambda (x y) (= x y)))
  
  ;;Ex2.80
  (put '=zero? '(scheme-number)
       (lambda (x) (= x 0)))
  
  ;;Ex2.81
  (put 'exp '(scheme-number scheme-number)
       (lambda (x y) (tag (expt x y))))
 
  
  ;;Ex2.83
  (put 'raise '(scheme-number)
       (lambda (x) (make-rational x 1)))
  ;;Ex2.85
  
  ;;Ex2.88
  (put 'neg '(scheme-number)
       (lambda (x) (tag (- 0 x))))
  'done)
(install-scheme-number-package)
(define (make-scheme-number n)
  ((get 'make 'scheme-number) n))