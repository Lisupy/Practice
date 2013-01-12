#lang scheme

(require (planet "sicp.ss" ("soegaard" "sicp.plt" 2 1)))
(paint einstein)

"====Ex2.50"
"flip-horiz:" 
(define (my-flip-horiz painter)
  ((transform-painter (make-vect 1.0 0.0)
                     (make-vect 0.0 0.0)
                     (make-vect 1.0 1.0))
                     painter))
(paint (flip-horiz einstein))
(paint (my-flip-horiz einstein))

"rotate-90:" 
(define (my-rotate90 painter)
  ((transform-painter (make-vect 1.0 0.0)
                      (make-vect 1.0 1.0)
                      (make-vect 0.0 0.0))
                      painter))
(paint (rotate90 einstein)) 
(paint (my-rotate90 einstein))

"rotate-180:" 
(define (my-rotate180 painter)
  ((transform-painter (make-vect 1.0 1.0)
                      (make-vect 0.0 1.0)
                      (make-vect 1.0 0.0))
                      painter))
(paint (rotate180 einstein))
(paint (rotate180 einstein))

"rotate-270:" 
(define (my-rotate270 painter)
  ((transform-painter (make-vect 0.0 1.0)
                      (make-vect 0.0 0.0)
                      (make-vect 1.0 1.0))
                      painter))
(paint (rotate270 einstein))
(paint (my-rotate270 einstein))

"====Ex2.51"
(define (my-below-1 painter1 painter2)
  (let ((paint-up 
         ((transform-painter (make-vect 0.0 0.5)
                            (make-vect 1.0 0.5)
                            (make-vect 0.0 1.0))
          painter2))
        (paint-down
         ((transform-painter (make-vect 0.0 0.0)
                             (make-vect 1.0 0.0)
                             (make-vect 0.0 0.5))
          painter1)))
    (lambda (frame)
      (paint-up frame)
      (paint-down frame))))
(define (my-below-2 painter1 painter2)
  (rotate90 (beside (rotate270 painter1) (rotate270 painter2))))
(paint (below einstein (rotate180 einstein)))
(paint (my-below-1 einstein (rotate180 einstein)))
(paint (my-below-2 einstein (rotate180 einstein)))