;#lang planet neil/sicp
;From p186
;(require scheme/mpair)

(define (make-table)
  (let ((local-table (list '*table*)))
    (define (lookup key-1 key-2)
      (let ((subtable (assoc key-1 (cdr local-table))))
        (if subtable
            (let ((record (assoc key-2 (cdr subtable))))
              (if record
                  (cdr record)
                  false))
            false)))
    (define (insert! key-1 key-2 value)
      (let ((subtable (assoc key-1 (cdr local-table))))
        (if subtable
            (let ((record (assoc key-2 (cdr subtable))))
              (if record
                  (set-cdr! record value)
                  (set-cdr! subtable
                            (cons (cons key-2 value)
                                  (cdr subtable)))))
            (set-cdr! local-table
                      (cons (list key-1
                                  (cons key-2 value))
                            (cdr local-table)))))
      'ok)
    (define (dispatch m)
      (cond ((eq? m 'lookup-proc) lookup)
            ((eq? m 'insert-proc!) insert!)
            (else (error "Unknow operation -- TABLE" m))))
    dispatch))
(define operation-table (make-table))
(define get (operation-table 'lookup-proc))
(define put (operation-table 'insert-proc!))



"====Ex2.73"
;from p100
(define (variable? x) (symbol? x))
(define (same-variable? v1 v2)
  (and (variable? v1) (variable? v2) (eq? v1 v2)))
;(define (make-sum a1 a2) (list '+ a1 a2))
(define (make-product m1 m2) (list '* m1 m2))
(define (sum? x)
  (and (pair? x) (eq? (car x) '+)))
(define (addend s) (cadr s))
(define (augend s) (caddr s))
(define (product? x)
        (and (pair? x) (eq? (car x) '*)))
(define (multiplier p) (cadr p))
(define (multiplicand p) (caddr p))
(define (make-sum a1 a2)
  (cond ((=number? a1 0) a2)
        ((=number? a2 0) a1)
        ((and (number? a1) (number? a2)) (+ a1 a2))
        (else (list '+ a1 a2))))
(define (=number? exp num)
  (and (number? exp) (= exp num)))

;from p126
(define (deriv exp var)
  (cond ((number? exp) 0)
        ((variable? exp) (if (same-variable? exp var) 1 0))
        (else ((get 'deriv (operator exp)) (operands exp) var))))
(define (operator exp) (car exp))
(define (operands exp) (cdr exp))

"a):"
;这个要结合p100的例子和opeator和operands的代码来看
;number?和variable?谓词是没有“类型标志的”，而sum等，是使用了代数运算符作为了类型标志
;此外，operator和operands的定义无法直接作用在num和variable（symbol）上

"b):"
(define (install-deriv-sum-package)
  (define (deriv-sum exp var)
    (let ((sumexp (apply make-sum exp)))
      (make-sum (deriv (addend sumexp) var)
                (deriv (augend sumexp) var))))
  (put 'deriv '+ deriv-sum))
(install-deriv-sum-package)
(define (install-deriv-product-package)
  (define (deriv-product exp var)
    (let ((productexp (apply make-product exp)))
      (make-sum
       (make-product (multiplier productexp)
                      (deriv (multiplicand productexp) var))
       (make-product (deriv (multiplier productexp) var)
                     (multiplicand productexp)))))
  (put 'deriv '* deriv-product))

;test
(deriv '1 'x)
(deriv '3 'x)
(deriv 'x 'x)
(deriv 'y 'x)
((get 'deriv '+) '(x x) 'x)

(get 'deriv (operator '(+ x x)))
(deriv '(+ x x) 'x)
;(deriv '(* x x) 'x)
(install-deriv-product-package)
(deriv '(* x x) 'x)
(deriv '(* y x) 'x)

"c):"

;(=number? 1 3)
(define (make-exponentiation base exponent)
  (cond ;((and (number? base) (number? exponent)) (** base exponent))
        ((=number? exponent 0) 1)
        ((=number? exponent 1) base)
        (else (list '** base exponent))))
(define (exponentiation? x)
  (and (pair? x) (eq? (car x) '**)))
(define (base x)  (cadr x))
(define (exponent x) (caddr x))

(make-exponentiation 'x 3)
(define (install-deriv-exponentiation-package)
  (define (deriv-exponentiation exp1 var)
    (let ((exp (cons '** exp1)))
       (make-product (make-product (exponent exp)
                                     (make-exponentiation (base exp) 
                                                          (- (exponent exp) 1)))
                       (deriv (base exp) var)))) 
  (put 'deriv '** deriv-exponentiation))


(base (make-exponentiation 'x 3))
(install-deriv-exponentiation-package)
'(** x 0)
(deriv '(** x 1) 'x)
(deriv '(** x 4) 'x)
(deriv '(** x 2) 'x)
(deriv '(** x 3) 'x)


"d):"
;修改put函数的第一和第二个参数即可


"====Ex2.73"
"a):"




          
        