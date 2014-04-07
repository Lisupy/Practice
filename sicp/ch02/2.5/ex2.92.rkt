
(load "predefined.rkt")
(load "tag.rkt")
(load "operation-table.rkt")
(load "apply-generic.rkt")
(load "scheme-number-package.rkt")
(load "polynomial-package.rkt")
(load "coercion.rkt")
"====Ex2.92"

(define p1 (make-polynomial 'x '((1 1))))
(define p2 (make-polynomial 'y '((1 -1))))
(define p1 (make-polynomial 'x ((3 10) (2 11) (1 4) (0 3))))
