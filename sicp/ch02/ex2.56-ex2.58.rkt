;#lang R5RS


"====Ex2.56"
(define (deriv exp var)
  (cond ((number? exp) 0)
        ((variable? exp)
         (if (same-variable? exp var) 1 0))
        ((sum? exp)
         (make-sum (deriv (addend exp) var)
                   (deriv (augend exp) var)))
        ((product? exp)
         (make-sum
          (make-product (multiplier exp)
                        (deriv (multiplicand exp) var))
          (make-product (deriv (multiplier exp) var)
                        (multiplicand exp))))
        ((exponentiation? exp)
         (make-product (make-product (exponent exp)
                                     (make-exponentiation (base exp) 
                                                          (- (exponent exp) 1)))
                       (deriv (base exp) var))) 
        (else
         (error "unknow expression type -- DERIV" exp))))

(define (variable? x) (symbol? x))
(define (same-variable? v1 v2)
  (and (variable? v1) (variable? v2) (eq? v1 v2)))

;(define (make-sum a1 a2) (list '+ a1 a2))
(define (make-sum a1 a2)
  (cond ((=number? a1 0) a2)
        ((=number? a2 0) a1)
        ((and (number? a1) (number? a2)) (+ a1 a2))
        (else (list '+ a1 a2))))
(define (=number? exp num)
  (and (number? exp) (= exp num)))
(define (sum? x)
  (and (pair? x) (eq? (car x) '+)))
(define (addend a) (cadr a))
(define (augend s) (caddr s))


;(define (make-product m1 m2) (list '* m1 m2))
(define (make-product m1 m2)
  (cond ((or (=number? m1 0) (=number? m2 0)) 0)
        ((=number? m1 1) m2)
        ((=number? m2 1) m1)
        ((and (number? m1) (number? m2)) (* m1 m2))
        (else (list '* m1 m2))))  
(define (product? x)
  (and (pair? x) (eq? (car x) '*)))
(define (multiplier p) (cadr p))
(define (multiplicand p) (caddr p))

(define (exponentiation? x)
  (and (pair? x) (eq? (car x) '**)))
(define (base x)  (cadr x))
(define (exponent x) (caddr x))
(define (** base exponent)
  (if (= exponent 0)
      1
      (* base (** base (- exponent 1)))))

;(define (make-exponentiation base exponent)
;  (list '** base exponent))
(define (make-exponentiation base exponent)
  (cond ;((and (number? base) (number? exponent)) (** base exponent))
        ((=number? exponent 0) 1)
        ((=number? exponent 1) base)
        (else (list '** base exponent))))

(deriv '(+ x 3) 'x)
(deriv '(* x y) 'x)
(deriv '(* (* x y) (+ x 3)) 'x)
(deriv '(** x 0) 'x)
(deriv '(** x 1) 'x)
(deriv '(** x 2) 'x)
(deriv '(** x 3) 'x)

"====Ex2.57"
(define (make-sum . y)
   (define (make-sum-list l)   
     (if (= (length l) 1) 
       (car l) 
       (list '+ (car l) (make-sum-list (cdr l)))))
  (make-sum-list y))

"=TEST MAKE-SUM BEGIN="
(make-sum 1)
(make-sum 1 2)
(make-sum 1 2 3)
(make-sum 1 2 3 4)
"=TEST MAKE-SUM END="


(define (make-product . y)
  (define (make-product-list l)
    (if (= (length l) 1)
        (car l)
        (list '* (car l) (make-product-list (cdr l)))))
  (make-product-list y))

"=TEST MAKE-PRODUCT BEGIN="
(make-product 1)
(make-product 1 2)
(make-product 1 2 3)
(make-product 1 2 3 4)
"=TEST MAKE-PRODUCT END="

(deriv '(+ x 3 1) 'x)
(deriv '(* x y) 'x)
(deriv '(* (* x y) (+ x 3 1 2 4)) 'x)
(deriv '(** x 0) 'x)
(deriv '(** x 1) 'x)
(deriv '(** x 2) 'x)
(deriv '(** x 3) 'x)

"====EX2.58"
"==a>:"
(define (make-sum x y)
  (list x '+ y))
(define (sum? x)
  (and (pair? x) (eq? (cadr x) '+)))
(define (addend x)
  (caddr x))
(define (augend x)
  (car x))

(define (make-product multiplicand multiplier)
  (list multiplicand '* multiplier))
(define (product? x)
  (and (pair? x) (eq? (cadr x) '*)))
(define (mulitiplicand x)
  (car x))
(define (mulitiplier x)
  (caddr x))

(make-product 'x 'y)
(make-sum 'x 'y)
(sum? '(x + y))
(deriv '(x + y) 'x)
(deriv '((x * y) * (x + 3)) 'x)