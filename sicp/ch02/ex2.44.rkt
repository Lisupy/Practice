#lang scheme

(require (planet "sicp.ss" ("soegaard" "sicp.plt" 2 1)))
 
(define nil '())
 
(define (connect vect-list)
  (define (iter segment-list remaining)
    (if (null? (cdr remaining))
        (reverse segment-list)
        (iter (cons (make-segment (car remaining)
                                  (cadr remaining))
                    segment-list)
              (cdr remaining))))
  (iter nil vect-list))
 
(define (wave frame)
  ((segments->painter (append (connect (list (make-vect 0.4  0.0)
                                             (make-vect 0.5  0.33)
                                             (make-vect 0.6  0.0))) ;inside legs
                              (connect (list (make-vect 0.25 0.0)
                                             (make-vect 0.33 0.5)
                                             (make-vect 0.3  0.6)
                                             (make-vect 0.1  0.4)
                                             (make-vect 0.0  0.6))) ;lower left
                              (connect (list (make-vect 0.0  0.8)
                                             (make-vect 0.1  0.6)
                                             (make-vect 0.33 0.65)
                                             (make-vect 0.4  0.65)
                                             (make-vect 0.35 0.8)
                                             (make-vect 0.4  1.0))) ;upper left
                              (connect (list (make-vect 0.75 0.0)
                                             (make-vect 0.6  0.45)
                                             (make-vect 1.0  0.15)));lower right
                              (connect (list (make-vect 1.0  0.35)
                                             (make-vect 0.8  0.65)
                                             (make-vect 0.6  0.65)
                                             (make-vect 0.65 0.8)
                                             (make-vect 0.6  1.0)))));upper right
   frame))
;To modify it, we simply work at the level of the connect primitive by adding a new sequence of line segments for the smile. Here's one possible rather non-artistic definition:
(define (smile-wave frame)
  ((segments->painter (append (connect (list (make-vect 0.4  0.0)
                                             (make-vect 0.5  0.33)
                                             (make-vect 0.6  0.0))) ;inside legs
                              (connect (list (make-vect 0.25 0.0)
                                             (make-vect 0.33 0.5)
                                             (make-vect 0.3  0.6)
                                             (make-vect 0.1  0.4)
                                             (make-vect 0.0  0.6))) ;lower left
                              (connect (list (make-vect 0.0  0.8)
                                             (make-vect 0.1  0.6)
                                             (make-vect 0.33 0.65)
                                             (make-vect 0.4  0.65)
                                             (make-vect 0.35 0.8)
                                             (make-vect 0.4  1.0))) ;upper left
                              (connect (list (make-vect 0.75 0.0)
                                             (make-vect 0.6  0.45)
                                             (make-vect 1.0  0.15)));lower right
                              (connect (list (make-vect 1.0  0.35)
                                             (make-vect 0.8  0.65)
                                             (make-vect 0.6  0.65)
                                             (make-vect 0.65 0.8)
                                             (make-vect 0.6  1.0)));upper right
                              (connect (list (make-vect 0.45 0.75)
                                             (make-vect 0.5  0.7)
                                             (make-vect 0.55 0.75)));smile
                              ))
   frame))
(paint wave)

(define wave2 (beside wave (flip-vert wave)))
(define wave4 (below wave2 wave2))
"wave2:" (paint wave2)
"wave4:" (paint wave4)

(define (flipped-pairs painter)
  (let ((painter2 (beside painter (flip-vert painter))))
    (below painter2 painter2)))
(define new_wave4 (flipped-pairs wave))
"newwave4:" (paint new_wave4)
"====Ex2.44"
"wave:" (paint wave)
(define (up-split painter n)
  (if (= n 0)
      painter
      (let ((smaller (up-split painter (- n 1))))
        (let ((up (beside smaller smaller)))
          (below painter up)))))
"up-split-wave:" (paint (up-split wave 10))
(define (right-split painter n)
  (if (= n 0)
      painter
      (let ((smaller (right-split painter (- n 1))))
        (beside painter (below smaller smaller)))))
"right-split-wave:" (paint (right-split wave 10))
(define (corner-split painter n)
  (if (= n 0)
      painter
      (let ((up (up-split painter (- n 1)))
            (right (right-split painter (- n 1))))
        (let ((top-left (beside up up))
              (bottom-right (below right right))
              (corner (corner-split painter (- n 1))))
          (beside (below painter top-left)
                  (below bottom-right corner))))))
"corner-split-wave:" (paint (corner-split wave 10))


