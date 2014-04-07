(define (install-polynomial-package)
  
  (define (make-poly variable term-list)
    (cons variable term-list))
  (define (variable p) (car p))
  (define (term-list p) (cdr p))
  
  (define (variable? x) (symbol? x))
  (define (same-variable? v1 v2)
    (and (variable? v1) (variable? v2) (eq? v1 v2)))
  
  
 
  
  
  
  (define (tag p) (attach-tag 'polynomial p))
  (put 'add '(polynomial polynomial)
       (lambda (p1 p2) (tag (add-poly p1 p2))))
  (put 'mul '(polynomial polynomial)
       (lambda (p1 p2) (tag (mul-poly p1 p2))))
  (put 'make 'polynomial
       (lambda (var terms) (tag (make-poly var terms))))
  
  
  
   ;ex2.92
  (define (adjust-to-new-variable newvar p)
    (if (or (empty-termlist? (term-list p))
            (= (order (first-term (term-list p))) 0))
        (make-poly newvar (term-list p))                             
        (make-poly newvar (adjoin-term (make-term 0 (tag p)) (the-empty-termlist)))))  
  (define (addjust-and-call p1 p2 fun)
    (if (or (string>? (symbol->string (variable p1)) (symbol->string (variable p2)))
            (empty-termlist? (term-list p2))
            (= (order (first-term (term-list p2))) 0))            
        (fun p1 (adjust-to-new-variable (variable p1) p2))
        (fun (adjust-to-new-variable (variable p2) p1) p2)))
  
  (define (add-poly p1 p2)
    (if (same-variable? (variable p1) (variable p2))
        (make-poly (variable p1)
                   (add-terms (term-list p1)
                              (term-list p2)))
        (addjust-and-call p1 p2 add-poly)))
  
  (define (mul-poly p1 p2)
    (if (same-variable? (variable p1) (variable p2))
        (make-poly (variable p1)
                   (mul-terms (term-list p1)
                              (term-list p2)))
        (addjust-and-call p1 p2 mul-poly)))
  ;Ex2.87  
  (define (=zero-polymial? p)  ;这里不能使用=zero? 
    (define (zero-termlist? L)     
      (cond ((empty-termlist? L) true)
            ((=zero? (coeff (first-term L))) (zero-termlist? (rest-terms L)))
            (else false)))
    (zero-termlist? (term-list p)))
  (put '=zero? '(polynomial) =zero-polymial?)
  
  ;Ex2.88
  (define (neg p)
    (tag (make-poly (variable p) (neg-terms (term-list p)))))
  (put 'neg '(polynomial) neg)
  
  (define (sub-poly p1 p2)
    (if (same-variable? (variable p1) (variable p2))
        (make-poly (variable p1)
                   (sub-terms (term-list p1)
                              (term-list p2)))
        (addjust-and-call p1 p2 sub-poly)))
  (put 'sub '(polynomial polynomial)
       (lambda (p1 p2) (tag (sub-poly p1 p2))))
  
  ;Ex2.91
  (define (div-poly p1 p2)
    (if (same-variable? (variable p1) (variable p2))
        (let ((div-result (div-terms (term-list p1) (term-list p2))))
          (list (make-poly (variable p1) (car div-result))
                (make-poly (variable p1) (cadr div-result))))
        (addjust-and-call p1 p2 div-poly)))
  (put 'div '(polynomial polynomial)
       (lambda (p1 p2) 
         (let ((result (div-poly p1 p2)))
           (list (tag (car result))
                 (tag (cadr result))))))
                      
  
  
  'done)
(install-polynomial-package)

(define (add-terms L1 L2)
  (cond ((empty-termlist? L1) L2)
        ((empty-termlist? L2) L1)
        (else
         (let ((t1 (first-term L1))
               (t2 (first-term L2)))
           (cond ((> (order t1) (order t2))
                  (adjoin-term
                   t1 (add-terms (rest-terms L1) L2)))
                 ((< (order t1) (order t2))
                  (adjoin-term
                   t2 (add-terms L1 (rest-terms L2))))
                 (else
                  (adjoin-term
                   (make-term (order t1)
                              (add (coeff t1) (coeff t2)))
                   (add-terms (rest-terms L1)
                              (rest-terms L2)))))))))
;Ex2.88
(define (neg-terms L) 
  (define (neg-term term)
    (make-term (order term) (neg (coeff term))))
  (if (empty-termlist? L)
      (the-empty-termlist)
      (adjoin-term (neg-term (first-term L)) (neg-terms (rest-terms L)))))
(define (sub-terms L1 L2)
  (add-terms L1 (neg-terms L2)))
;Ex2.91
(define (div-terms L1 L2)
  (if (empty-termlist? L1)
      (list (the-empty-termlist) (the-empty-termlist))
      (let ((t1 (first-term L1))
            (t2 (first-term L2)))
        (if (> (order t2) (order t1))
            (list (the-empty-termlist) L1)
            (let ((new-c (div (coeff t1) (coeff t2)))
                  (new-o (- (order t1) (order t2))))
              (let ((rest-of-result
                     (div-terms (sub-terms L1 
                                     (mul-terms L2 
                                          (adjoin-term (make-term new-o new-c) 
                                                       (the-empty-termlist)))) 
                                     L2)
                     ))

                (list (adjoin-term (make-term new-o new-c) (car rest-of-result)) 
                      (cadr rest-of-result))
                ))))))
              


(define (mul-terms L1 L2)
  (if (empty-termlist? L1)
      (the-empty-termlist)
      (add-terms (mul-term-by-all-terms (first-term L1) L2)
                 (mul-terms (rest-terms L1) L2))))

(define (mul-term-by-all-terms t1 L)
  (if (empty-termlist? L)
      (the-empty-termlist)
      (let ((t2 (first-term L)))
        (adjoin-term
         (make-term (+ (order t1) (order t2))
                    (mul (coeff t1) (coeff t2)))
         (mul-term-by-all-terms t1 (rest-terms L))))))
;(> (order term) (order (first-term term-list)))
(define (adjoin-term term term-list)
  (if (=zero? (coeff term))
      term-list
      (cons term term-list)))

(define (the-empty-termlist) '())
(define (first-term term-list) (car term-list))
(define (rest-terms term-list) (cdr term-list))
(define (empty-termlist? term-list) (null? term-list))

(define (make-term order coeff) (list order coeff))
(define (order term) (car term))
(define (coeff term) (cadr term))


(define (make-polynomial var terms)
  ((get 'make 'polynomial) var terms))

(define (scheme-number->polynomial n)
  (make-polynomial 'x (adjoin-term (make-term 0 n) (the-empty-termlist))))