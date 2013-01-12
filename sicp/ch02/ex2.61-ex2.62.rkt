#lang scheme

(define (element-of-set? x set)
  (cond ((null? set) false)
        ((= x (car set)) true)
        ((< x (car set)) false)
        (else (element-of-set? x (cdr set)))))
(define (intersection-set set1 set2)
  (if (or (null? set1) (null? set2))
      '()
      (let ((x1 (car set1)) (x2 (car set2)))
        (cond ((= x1 x2)
               (cons x1
                     (intersection-set (cdr set1)
                                       (cdr set2))))
              ((< x1 x2)
               (intersection-set (cdr set1) set2))
              ((< x2 x1)
               (intersection-set set1 (cdr set2)))))))
(element-of-set? 1 '())
(element-of-set? 1 '(1))
(element-of-set? 1 '(0 1))
(element-of-set? 2 '(0 1))
(intersection-set '(0 1 3) '(1 2 3))
"====Ex2.61"
(define (adjoin-set x set)
  (cond ((null? set) '())
        ((= x (car set)) set)
        ((< x (car set)) (cons x set))
        ((> x (car set)) (cons (car set) (adjoin-set x (cdr set))))))


(adjoin-set 1 '())   
(adjoin-set 3 (list 1 2 3)) 
(adjoin-set 3 (list 1 2 4 5))  
"====Ex2.62"

(define (union-set set1 set2)
  (cond ((null? set1) set2)
        ((null? set2) set1)
        (else (let ((x1 (car set1)) (x2 (car set2)))
                (cond ((= x1 x2) (cons x1 (union-set (cdr set1) (cdr set2))))
                      ((< x1 x2) (cons x1 (union-set (cdr set1) set2)))
                      ((> x1 x2) (cons x2 (union-set set1 (cdr set2))))))))) 

(union-set '() (list 1 2 3))
(union-set (list 1 2 3) (list 1 3 5))
(union-set (list 1 2 3) (list 1 3 5 7 9))
