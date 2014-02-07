(define square (lambda (x) (* x x)))
(define nil ())
"====Ex2.30"
(define t (list 1 (list 2(list 3 4 ) 5) (list 6 7)))
(define (square-tree t)
  (cond ((null? t) nil)
        ((pair? t) (cons (square-tree (car t)) (square-tree (cdr t))))
        (else (square t))))
t
(square-tree t)

"====Ex2.31"
(define (square-tree tree) (tree-map square tree))
(define (tree-map factor tree)
  (cond [(pair? tree) (cons (tree-map factor (car tree)) (tree-map  factor (cdr tree)))]
        [(null? tree) nil]
        [else (factor tree)]))
(square-tree t)

"====Ex2.32"
(define (subsets s)
  (if (null? s)
      (list nil)
      (let [(rset (subsets (cdr s)))]
        (append rset (map (lambda (x) (cons (car s) x)) rset)))))
(subsets t)
(subsets '(1 2 3))