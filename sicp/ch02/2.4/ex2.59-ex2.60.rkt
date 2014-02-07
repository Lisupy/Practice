#lang scheme

"====Ex2.59"

(define (element-of-set? x set)
  (cond ((null? set) false)
        ((equal? x (car set)) true)
        (else (element-of-set? x (cdr set)))))
(define (adjoin-set x set)
  (if (element-of-set? x set)
      set
      (cons x set)))
(define (intersection-set set1 set2)
  (cond ((or (null? set1) (null? set2)) '())
        ((element-of-set? (car set1) set2)
         (cons (car set1)
               (intersection-set (cdr set1) set2)))))

(define (union-set set1 set2)
  (cond ((null? set1) set2)
        ((element-of-set? (car set1) set2)
         (union-set (cdr set1) set2))
        (else (cons (car set1) (union-set (cdr set1) set2)))))


(union-set '(1 2 3 7 8) '(3 4 5 6 7))
(union-set '() '(1 2 3))

"====Ex2.60"

(define (element-of-multiset? x set)
  (cond ((null? set) false)
        ((equal? x (car set)) true)
        (else (element-of-set? x (cdr set)))))
(define (adjoin-multiset? x set)
  (cons x set))

(define (intersection-multiset set1 set2)
  (cond ((or (null? set1) (null? set2)) '())
        ((element-of-set? (car set1) set2)
         (cons (car set1)
               (intersection-multiset (cdr set1) set2)))))

(define (union-multiset set1 set2)
  (if (null? set1)
      set2
      (cons (car set1) (union-multiset (cdr set1) set2))))

(union-multiset '(1 2 3 7 8) '(3 4 5 6 7))
(union-multiset '() '(1 2 3))