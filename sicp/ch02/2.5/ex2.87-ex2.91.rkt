(load "predefined.rkt")
(load "tag.rkt")
(load "operation-table.rkt")
(load "apply-generic.rkt")
(load "scheme-number-package.rkt")
(load "polynomial-package.rkt")
(load "coercion.rkt")


"===Ex2.87"
(define p1 (make-polynomial 'x '((1 0))))
;(define p1 (make-polynomial 'x '((1 1))))
p1
(=zero? p1)
(define p2 (make-polynomial 'x (list (list 1 p1))))
p2
(=zero? p2)

"====Ex2.88"
(define p1 (make-polynomial 'x '((1 1))))
(define p2 (make-polynomial 'x '((1 -1))))
p1
p2
(neg-terms '((1 1)))
(neg p1)
(sub p1 p2)
"====Ex2.89"
;for dense
(define (the-empty-termlist) '())
(define (highest-order term-list) (- (length term-list) 1))
(define (first-term term-list) (make-term (highest-order term-list) (car term-list)))
(define (rest-terms term-list) (cdr term-list))
(define (empty-termlist? term-list) (null? term-list))


(define (make-term order coeff) (list order coeff))
(define (order term) (car term))
(define (coeff term) (cadr term))

(define (adjoin-term term term-list)
  (if (= (order term) (+ (highest-order term-list) 1))
      (cons (coeff term) term-list)
      (adjoin-term term (cons 0 term-list))))
(define (normalize-term-list term-list)
  (display term-list)
 ; (display (coeff (first-term term-list)))
  (cond ((empty-termlist? term-list) term-list)
        ((=zero? (coeff (first-term term-list))) (normalize (cdr term-list)))
        (else term-list)))
      


(define p1 (make-polynomial 'x (adjoin-term (make-term 1 2) (the-empty-termlist))))
p1
(sub p1 p1)
(define p2 (make-polynomial 'x (adjoin-term (make-term 3 3) (the-empty-termlist))))
(add p1 p2)
(sub p1 p2)
";====Ex2.90"

;definition: term 
(define (order x) (apply-generic 'order x))
(define (coeff x) (apply-generic 'coeff x))
(define (make-term order coeff) ((get 'make 'term) order coeff))
(define (install-term-package)
  (define (order term) (car term))
  (define (coeff term) (cadr term))
  (define (make-term order coeff) (list order coeff))
  
  (define (tag p) (attach-tag 'term p))

  (put 'order '(term) 
       (lambda (p) (order p)))
  (put 'coeff '(term) 
       (lambda (p) (coeff p)))
  
  (put 'make 'term
    (lambda (p1 p2) (tag (make-term p1 p2))))
        
  'install-term-package-done)
(install-term-package)

;definition: interface of termlist
(define (first-term x) (apply-generic 'first-term x))
(define (rest-terms x) (apply-generic 'rest-terms x))
(define (empty-termlist? x) (apply-generic 'empty-termlist? x))
(define (adjoin-term term term-list) ((apply-generic 'adjoin-term term-list) term))
;definition: sparse-terms
(define (install-sparse-terms-package)  
  (define (the-empty-termlist) '())
  (define (first-term term-list) (car term-list))
  (define (rest-terms term-list) (cdr term-list))
  (define (empty-termlist? term-list) (null? term-list))
 
  (define (adjoin-term term term-list)
    (if (=zero? (coeff term))
        term-list
        (cons term term-list)))
  
  (define (tag p) (attach-tag 'sparse-terms p))
 
  (put 'first-term '(sparse-terms)
       (lambda (p) (first-term p)))
  (put 'rest-terms '(sparse-terms)
       (lambda (p) (tag (rest-terms p))))
  (put 'empty-termlist? '(sparse-terms)
       (lambda (p) (empty-termlist? p)))
  (put 'adjoin-term '(sparse-terms)
       (lambda (p) 
         (lambda (term)
           (tag (adjoin-term term p)))))
  
  (put 'the-empty-termlist 'sparse-terms
       (lambda () (tag (the-empty-termlist))))

  'install-sparse-terms-done)

(install-sparse-terms-package)
(define (empty-sparse-termlist)
  ((get 'the-empty-termlist 'sparse-terms)))

;TEST-sparse
(empty-sparse-termlist)
(define sp0 (make-polynomial 'x (empty-sparse-termlist)))
;((apply-generic 'adjoin-term (empty-sparse-termlist)) (make-term 1 2))
;(coeff (make-term 1 2))
;(adjoin-term (make-term 1 2) (empty-sparse-termlist))
(define sp1 (make-polynomial 'x (adjoin-term (make-term 1 2) (empty-sparse-termlist))))  
sp1
(define sp2 (make-polynomial 'x (adjoin-term (make-term 3 3) (empty-sparse-termlist))))  
sp2
(define sp3 (make-polynomial 
 'x 
 (adjoin-term (make-term 4 1) 
              (adjoin-term (make-term 3 1)  (empty-sparse-termlist)))))
sp3
(add sp1 sp1)
(add sp1 sp2)
(add sp3 sp2)
(define sp4 (add sp1 (add sp3 sp2)))
sp4
(define the-empty-termlist empty-sparse-termlist)
(mul sp4 sp4)
"TEST DIV:\n"
(div sp4 sp4)
(div sp4 sp3)
(div (make-polynomial 'x
      (adjoin-term 
       (make-term 5 1) 
       (adjoin-term 
        (make-term 0 -1)
        (the-empty-termlist))))
     (make-polynomial 'x
      (adjoin-term 
       (make-term 2 1) 
       (adjoin-term 
        (make-term 0 -1)
        (the-empty-termlist)))))
;definition: dense-terms
(define (install-dense-terms-package)
  (define (the-empty-termlist) '())
  (define (highest-order term-list) (- (length term-list) 1))
  (define (first-term term-list) (make-term (highest-order term-list) (car term-list)))
  (define (rest-terms term-list) (cdr term-list))
  (define (empty-termlist? term-list) (null? term-list))
  (define (normalize terms)
    (cond ((null? terms) terms)
          ((= (car terms) 0) (normalize (cdr terms)))
          (else terms)))
  (define (adjoin-term term term-list)
    (define (adjoin-term term term-list)
      (if (= (order term) (+ (highest-order term-list) 1))
        (cons (coeff term) term-list)
        (adjoin-term term (cons 0 term-list))))
    (normalize (adjoin-term term term-list)))
  
  (define (tag p) (attach-tag 'dense-terms p))
 
  (put 'first-term '(dense-terms)
       (lambda (p) (first-term p)))
  (put 'rest-terms '(dense-terms)
       (lambda (p) (tag (rest-terms p))))
  (put 'empty-termlist? '(dense-terms)
       (lambda (p) (empty-termlist? p)))
  (put 'adjoin-term '(dense-terms)
       (lambda (p) 
         (lambda (term)
           (tag (adjoin-term term p)))))
  
  (put 'the-empty-termlist 'dense-terms
       (lambda () (tag (the-empty-termlist))))
  'install-dense-terms-package-done)
(install-dense-terms-package)

(define (empty-dense-termlist)
  ((get 'the-empty-termlist 'dense-terms)))

;TEST dense
(empty-dense-termlist)
(adjoin-term (make-term 1 2) (empty-dense-termlist))
(define dp1 (make-polynomial 'x (adjoin-term (make-term 1 2) (empty-dense-termlist))))  
dp1
(define dp2 (make-polynomial 'x (adjoin-term (make-term 3 3) (empty-dense-termlist))))  
dp2
(define dp3 (make-polynomial 
 'x 
 (adjoin-term (make-term 4 1) 
              (adjoin-term (make-term 3 1)  (empty-dense-termlist)))))
dp3
(add dp1 dp1)
(add dp1 dp2)
(add dp3 dp2)
(define dp4 (add dp1 (add dp3 dp2)))
dp4
(define the-empty-termlist empty-dense-termlist)
(mul dp4 dp4)
"TEST DIV:\n"
(div dp4 dp4)
(div dp4 dp3)
(div (make-polynomial 'x
      (adjoin-term 
       (make-term 5 1) 
       (adjoin-term 
        (make-term 0 -1)
        (the-empty-termlist))))
     (make-polynomial 'x
      (adjoin-term 
       (make-term 2 1) 
       (adjoin-term 
        (make-term 0 -1)
        (the-empty-termlist)))))

;definition: coercion of termlist
(define (sparse-terms->dense-terms L)
  (if (empty-termlist? L)
      (empty-dense-termlist)
      (adjoin-term (first-term L) (sparse-terms->sense-terms (rest-terms L)))))
(define (dense-terms->sparse-terms L)
  (if (empty-termlist? L)
      (empty-sparse-termlist)
      (adjoin-term (first-term L) (dense-terms->sparse-terms (rest-terms L)))))
;(put-coercion 'sparse-terms 'dense-terms sparse-terms->dense-terms)
;(put-coercion 'dense-terms 'sparse-terms dense-terms->sparse-terms)
;(define the-empty-termlist empty-dense-termlist)

(mul sp1 dp1)
;Test

"====Ex2.91"
(define (the-empty-termlist) (empty-sparse-termlist))
(div (make-polynomial 'x
      (adjoin-term 
       (make-term 5 1) 
       (adjoin-term 
        (make-term 0 -1)
        (the-empty-termlist))))
     (make-polynomial 'x
      (adjoin-term 
       (make-term 2 1) 
       (adjoin-term 
        (make-term 0 -1)
        (empty-sparse-termlist)))))
(define (the-empty-termlist) (empty-dense-termlist))
(div (make-polynomial 'x
      (adjoin-term 
       (make-term 5 1) 
       (adjoin-term 
        (make-term 0 -1)
        (empty-sparse-termlist))))
     (make-polynomial 'x
      (adjoin-term 
       (make-term 2 1) 
       (adjoin-term 
        (make-term 0 -1)
        (empty-sparse-termlist)))))
(define (the-empty-termlist) (empty-dense-termlist))
(div (make-polynomial 'x
      (adjoin-term 
       (make-term 5 1) 
       (adjoin-term 
        (make-term 0 -1)
        (the-empty-termlist))))
     (make-polynomial 'x
      (adjoin-term 
       (make-term 2 1) 
       (adjoin-term 
        (make-term 0 -1)
        (the-empty-termlist)))))