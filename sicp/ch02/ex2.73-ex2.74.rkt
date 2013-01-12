#lang scheme



"====Ex2.73"

(define (deriv exp var)
  (cond ((number? exp) 0)
        ((variable? exp) (if (same-variable? exp var) 1 0))
     ;   ((sum? exp)
     ;    (make-sum (deriv (addend exp) var)
      ;             (deriv (addend exp) var)))
      ;  ((product? exp)
      ;   (make-sum
      ;    (make-product (multiplier exp)
      ;                  (deriv (multiplicand exp) var))
      ;    (make-product (deriv (multiplier exp) var)
      ;                  (multiplicand exp))))
        (else (error "unknow expression type -- DERIV" exp))))

"a):"
" number?, same-variable? are predicates. there's nothing to dispatch."
"b):"

(define (install-my-package)
  (define (variable? x) (symbol? x))
  (define (samevariable? v1 v2) 
    (and (variable? v1) (variable? v2) (eq? v1 v2)))
  (put 'variable? '(my) variable)
  (put 'samevariable? '(my) v1 v2)
  'done)

(define (apply-genric op . args)
  (let ((type-tags (map type-tag args)))
    (let ((proc (get op type-tags)))
      (if proc
          (apply proc (map contents args))
          (error
           "no method for these types -- APPLY-GENERIC"
           (list op type-tags))))))

(define (variable? x) (apply-generic 'variable? x))
(define (same-variable? v1 v2) (apply-generic 'variable? v1 v2))





          
        