(define (apply-generic op . args)
  (let ((type-tags (map type-tag args)))
    (let ((proc (get op type-tags)))
      (if proc
          (apply proc (map contents args))
          (error
           "No method for these types -- APPLY-GENERIC"
           (list op type-tags))))))

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
                (let ((t1->t2 (get-coercion type1 type2))
                      (t2->t1 (get-coercion type2 type1)))
                  (cond (t1->t2
                         (apply-generic op (t1->t2 a1) a2))
                        (t2->t1
                         (apply-generic op a1 (t2->t1 a2)))
                        (else
                         (error "No Method for these types"
                                (list op type-tags))))))
              (error "No method for these types"
                     (list op type-tags)))))))

(define (real-part z) (apply-generic 'real-part z))
(define (imag-part z) (apply-generic 'imag-part z))
(define (magnitude z) (apply-generic 'magnitude z))
(define (angle z) (z) (apply-generic 'angle z))

(define (add x y) (apply-generic 'add x y))
(define (sub x y) (apply-generic 'sub x y))
(define (mul x y) (apply-generic 'mul x y))
(define (div x y) (apply-generic 'div x y)) 

(define (equ? x y) (apply-generic 'equ? x y))
(define (=zero? x) (apply-generic '=zero? x))

(define (raise x) (apply-generic 'raise x))
(define (can-raise? x) 
  (if (get 'raise (list (type-tag x)))
      true
      false))
(define (can-project? x)
  (if (get 'project (list (type-tag x)))
      true
      false))
(define (project x) 
  (if (can-project? x)
      (apply-generic 'project x)
      x))

         
(define (drop x)
  (let ((pro-x (project x)))
    (if (eq? (type-tag x) (type-tag pro-x))
        x
        (drop pro-x))))


(define (neg x) (apply-generic 'neg x))