
(load "predefined.rkt")
(load "tag.rkt")
(load "operation-table.rkt")
(load "coercion.rkt")
(load "apply-generic.rkt")

(load "polar-package.rkt")
(load "rational-package.rkt")
(load "rectangular-package.rkt")
(load "scheme-number-package.rkt")
(load "complex-package.rkt")

"====Ex2.81"
(add (make-scheme-number 1) (make-complex-from-mag-ang 1 2))
"a)"
(define (install-louis-package)
  (define (scheme-number->scheme-number n) n)
  (define (complex->complex z) z)
  (put-coercion 'scheme-number 'scheme-number
                scheme-number->scheme-number)
  (put-coercion 'complex 'complex complex->complex))
(install-louis-package) 
(define (exp x y) (apply-generic 'exp x y))
(define c1 (make-complex-from-mag-ang 1 2))
(define s1 (make-scheme-number 1))
c1
;(exp c1 c1)   ;死循环了
"b)"


"c)"
(define (apply-generic op . args)
  (let ((type-tags (map type-tag args)))
    (let ((proc (get op type-tags)))      
      (if proc
          (apply proc (map contents args))
          (if (= (length args) 2)
              (let ((type1 (car type-tags))
                    (type2 (cadr type-tags))
                    (a1 (car args))
                    (a2 (cadr args)))
                (if (eq? type1 type2)
                    (error "No method for these types"
                           (list op type-tags))
                    (let ((t1->t2 (get-coercion type1 type2))
                          (t2->t1 (get-coercion type2 type1)))
                      (cond (t1->t2
                             (apply-generic op (t1->t2 a1) a2))
                            (t2->t1
                             (apply-generic op a1 (t2->t1 a2)))
                            (else
                             (error "No Method for these types"
                                    (list op type-tags)))))))
              (error "No method for these types"
                     (list op type-tags)))))))
(exp c1 c1) 
"====Ex2.82"
;题目没要求写代码
;假设类似图2-25，加入存在一个（func complex complex），那(func integer rational）用题目描述的策略，
;也无法找到（func complex complex)
"====Ex2.83"
(raise 1)
(raise (raise 1))
(raise (make-scheme-number 1))
"====Ex2.84"
(define (apply-generic op . args)
  (define (try-raise-to v1 v2)
    (if (eq? (type-tag v1) (type-tag v2))
        v1
        (if (can-raise? v1)              
            (try-raise-to (raise v1) v2)
            false)))
  
  (let ((type-tags (map type-tag args)))
    (let ((proc (get op type-tags)))      
      (if proc
          (apply proc (map contents args))
          (if (= (length args) 2)
              (let ((type1 (car type-tags))
                    (type2 (cadr type-tags))
                    (a1 (car args))
                    (a2 (cadr args)))
                (cond ((eq? type1 type2) (error "No method for these types" (list op type-tags)))
                      ((try-raise-to a1 a2) (apply-generic op (try-raise-to a1 a2) a2))
                      ((try-raise-to a2 a1) (apply-generic op a1 (try-raise-to a2 a1)))
                      (else (error "No method for these types" (list op type-tags)))))
              (error "No method for these types" (list op type-tags)))))))
(add (make-scheme-number 1) (make-complex-from-mag-ang 3 1))
(sub (make-complex-from-mag-ang 3 1) (make-scheme-number 3))
"====Ex2.85"
(drop (make-rational 3 1))
(drop (make-complex-from-mag-ang 3 0))
(drop (make-complex-from-mag-ang 3 1))
(drop (make-complex-from-real-imag 3 0))
(drop (make-complex-from-real-imag 3 1))
(define (apply-generic op . args)
  (define (try-raise-to v1 v2)
    (if (eq? (type-tag v1) (type-tag v2))
        v1
        (if (can-raise? v1)              
            (try-raise-to (raise v1) v2)
            false)))
  
  (let ((type-tags (map type-tag args)))
    (let ((proc (get op type-tags)))      
      (if proc
          (drop (apply proc (map contents args)))
          (if (= (length args) 2)
              (let ((type1 (car type-tags))
                    (type2 (cadr type-tags))
                    (a1 (car args))
                    (a2 (cadr args)))
                (cond ((eq? type1 type2) (error "No method for these types" (list op type-tags)))
                      ((try-raise-to a1 a2) (apply-generic op (try-raise-to a1 a2) a2))
                      ((try-raise-to a2 a1) (apply-generic op a1 (try-raise-to a2 a1)))
                      (else (error "No method for these types" (list op type))))))))))
(add (make-complex-from-mag-ang 3 0) (make-complex-from-real-imag 3 0))
"====Ex2.86"
;将+-*/修改为add,sub,mul,div
;用apply-generic定义sine和cosine

