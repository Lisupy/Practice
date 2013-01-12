#lang scheme

"====Ex2.46"
(define (make-vect x y) (cons x y))
(define (xcor-vect v) (car v))
(define (ycor-vect v) (cdr v))
(define (display-vect v) 
  (display "(")
  (display (xcor-vect v))
  (display ",")
  (display (ycor-vect v))
  (display ")")) 

(define (add-vect v1 v2) 
  (make-vect (+ (xcor-vect v1) (ycor-vect v2)) 
             (+ (ycor-vect v1) (ycor-vect v2))))
(define (sub-vect v1 v2)
  (make-vect (- (xcor-vect v1) (ycor-vect v2))
             (- (ycor-vect v1) (ycor-vect v2))))
(define (scale-vect v s)
  (make-vect (* s (xcor-vect v))
             (* s (ycor-vect v))))

(define v1 (make-vect 1 2))
(define v2 (make-vect 2 3))
(display-vect v1)
(display-vect (add-vect v1 v2))
(display-vect (sub-vect v1 v2))
(display-vect (scale-vect v1 10))
(display "\r\n")
"====Ex2.47"
(define (make-frame origin edge1 edge2)
  (list origin edge1 edge2))

(define (make-frame2 origin edge1 edge2)
  (list origin edge1 edge2))

(define (origin-frame frame)
  (car frame))
(define (edge1-frame frame)
  (cadr frame))
(define (edge2-frame frame)
  (caddr frame))

(define f (make-frame 1 2 3))
(origin-frame f)
(edge1-frame f)
(edge2-frame f)

(define f2 (make-frame2 1 2 3))
(origin-frame f2)
(edge1-frame f2)
(edge2-frame f2)
(paint wave)