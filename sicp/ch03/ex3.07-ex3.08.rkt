#lang scheme


"====Ex3.07"
(define (make-account balance password)
  (define (withdraw amount)
    (if (>= balance amount)
        (begin (set! balance (- balance amount))
               balance)
        "Insufficient funds"))
  (define (deposit amount)
    (set! balance (+ balance amount)))
  (define (dispatch pw m)
    (cond ((not (eq? password pw)) (error "Incorrect password for" m))
          ((eq? m 'withdraw) withdraw)
          ((eq? m 'deposit) deposit)
          (else (error "Unknow request -- MAKE-ACCOUNT" m))))
  dispatch)
(define peter-acc (make-account 100 'open-sesame))
(define (make-joint old-acc old-passwd new-passwd)
  (define (dispatch pw m)
    (cond ((eq? pw new-passwd) (old-acc old-passwd m))
          (else (display "wrong-passwd"))))
    dispatch)
(define paul-acc
  (make-joint peter-acc 'open-sesame 'rosebud))
((paul-acc 'rosebud 'withdraw) 10)
((peter-acc 'open-sesame 'withdraw) 10)
((paul-acc 'rosebud 'withdraw) 10)

"====Ex3.08"

(define f 
  (let ((s 1))
    (lambda (x)
      (set! s (* s x))
      s)))
;(f 1)
;(f 0)
;(f 0)
;(f 1)
(+ (f 1) (f 0))
(+ (f 0) (f 1))