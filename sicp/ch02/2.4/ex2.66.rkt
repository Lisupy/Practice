#lang scheme

(define (entry tree) (car tree))
(define (left-branch tree) (cadr tree))
(define (right-branch tree) (caddr tree))

;(equal? "123" "123")
"====Ex2.66"
(define (key record) (car record))
(define (make-record key record) (cons key record))

(define (lookup given-key set-of-records)
  (cond ((null? set-of-records) '())
        ((equal? given-key (key (entry set-of-records))) (entry set-of-records))
        ((< given-key (key (entry set-of-records))) (lookup given-key (left-branch set-of-records)))
        ((> given-key (key (entry set-of-records))) (lookup given-key (right-branch set-of-records)))))
(cons 1 "b")
'(1 . "b")
(define set1 '((2 . "b")  ((1 . "a") () () )  ((3 . "c") () ()) ))
"set1:"set1
(lookup 2 set1)
(lookup 1 set1)
(lookup 3 set1)
(lookup 4 set1)