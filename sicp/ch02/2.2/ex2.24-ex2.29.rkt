(define nil ())
"====Ex2.24"
(list 1 (list 2 (list 3 4)))
"====Ex2.25"
(define l `(1 3 (5 7) 9))
(car (cdaddr l))
(define l `((7)))
(caar l)
(caar `((7)))
(define l '(1 2 3 4 5 6 7))
(caddr (cddddr l))
"====Ex2.26"
(define x (list 1 2 3))
(define y (list 4 5 6))

(append x y)
`(1 2 3 4 5 6)
(cons x y)
`((1 2 3) . (4 5 6))
(list x y)
`((1 2 3) (4 5 6))
"====Ex2.27"
(define x (list (list 1 2 5) (list 3 4 6)))
(define (my-reverse items)
  (if (null? items)
      nil
      (append (my-reverse (cdr items))
              (list (car items)))))
(reverse x)
(my-reverse x)
(define (deep-reverse x)
  (cond ((null? x) nil)
        ((not (pair? x))  x)
        (else (append (deep-reverse (cdr x))
                       (list (deep-reverse (car x)))))))
;(define (deep-reverse x)
;  (cond ((null? x) nil)
;        ((not (pair? x))  x)
;        (else (cons (deep-reverse (cdr x))
;                    (deep-reverse (car x))))))


;(cdr x) = ((3 4 6))
;(car x) = (1 2 5)
(deep-reverse x)

"====Ex2.28"
(define (fringe tree)
  (cond ((null? tree) nil)
        ((not (pair? tree)) (list tree))
        (else (append (fringe (car tree))
                      (fringe (cdr tree))))))
(fringe x)
(fringe (list x x))

"====Ex2.29"
(define (make-mobile left right)
  (list left right))
(define (make-branch length structure)
  (list length structure))
"a>"
(define (left-branch mobile)
  (car mobile))
(define (right-branch mobile)
  (cadr mobile))
(define (mobile? mobile)
  (list? mobile)) 
;(list? '(1 2))
"b>"
(define branch-structure cadr)
(define branch-length car)
(define (branch-weight branch)
  (if (mobile? (branch-structure branch))
      (total-weight (branch-structure branch))
      (branch-structure branch)))
(define (total-weight mobile)
  (+ (branch-weight (left-branch mobile))
     (branch-weight (right-branch mobile))))
"c>"
(define (branch-torque branch)
  (* (branch-weight branch)
     (branch-length branch)))
(define (blance? mobile)
  (= (branch-torque (left-branch mobile))
     (branch-torque (left-branch mobile))))
"TEST"
(display "new Test!!")
(define a (make-branch 1 2))
(define b (make-branch 1 3))
(define c (make-mobile a b))
(define d (make-branch 4 c))
(branch-weight d)
(branch-torque d)
(define em (make-mobile d d))
(blance? em)
(display "Test end!!===")
(newline)

"d>"
(define (make-mobile left right)
  (cons left right))
(define (make-branch length structure)
  (cons length structure))
"new"
(define left-branch car)
(define right-branch cdr)
(define branch-structure cdr)
(define branch-length car)
(define mobile? pair?)
"TEST"
(display "new Test!!")
(newline)
(define a (make-branch 1 2))
(define b (make-branch 1 3))
(define c (make-mobile a b))
(define d (make-branch 4 c))
d
;(* (branch-length d)
(branch-weight d)
(branch-torque d)
(define em (make-mobile d d))
(blance? em)
(display "Test end!!===")
(newline)

