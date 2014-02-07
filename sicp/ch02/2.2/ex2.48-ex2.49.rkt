#lang scheme
(require (planet "sicp.ss" ("soegaard" "sicp.plt" 2 1)))
"====Ex2.48"
(require "ex2.46-ex2.47.rkt")

(define (make-segment2 start end) (cons start end))
(define (start-segment2 segment) (car segment))
(define (end-segment2 segment) (cdr segment))

"====Ex2.49"

;(define (segments-painter segment-list)
;  (lambda (frame)
;    (for-each
;     (lambda (segment)
;       (draw-line
;        ((frame-coord-map frame) (start-segment segment))
;        ((frame-coord-map frame) (end-segment segment))))
;     segment-list)))
(define top-left (make-vect 0.0 1.0))
(define top-right (make-vect 1.0 1.0))
(define bottom-left (make-vect 0.0 0.0))
(define bottom-right (make-vect 1.0 0.0))
(define a
  (segments->painter
     (list (make-segment top-left top-right)
           (make-segment top-right bottom-right)
           (make-segment bottom-right bottom-left)
           (make-segment bottom-left top-left))))
"a):" (paint a)
(define b
  (segments->painter
   (list (make-segment top-left bottom-right)
         (make-segment bottom-left top-right))))
"b):" (paint b)

(define top-mid (make-vect 0.5 1.0))
(define bottom-mid (make-vect 0.5 0))
(define left-mid (make-vect 0 0.5))
(define right-mid (make-vect 1 0.5))
(define c
  (segments->painter
   (list (make-segment top-mid right-mid)
         (make-segment right-mid bottom-mid)
         (make-segment bottom-mid left-mid)
         (make-segment left-mid top-mid))))
"c):" (paint c)

"d):"
;en.....