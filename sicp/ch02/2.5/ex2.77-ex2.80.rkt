(load "operation-table.rkt")
(load "apply-generic.rkt")
(load "tag.rkt")

(load "polar-package.rkt")
(load "rational-package.rkt")
(load "rectangular-package.rkt")
(load "scheme-number-package.rkt")
(load "complex-package.rkt")
"====Ex2.77"
(define z (make-complex-from-real-imag 1 2))
z
(magnitude z)
"====Ex2.78"
(make-scheme-number 1)
"====Ex2.79"
(equ? (make-complex-from-real-imag 1 2)
      (make-complex-from-mag-ang 1 2))
(equ? (make-scheme-number 1) (make-scheme-number 1))
"====Ex2.80"
(=zero? (make-complex-from-real-imag 1 0))
(=zero? (make-complex-from-mag-ang 0 3))
(=zero? (make-scheme-number 0))
