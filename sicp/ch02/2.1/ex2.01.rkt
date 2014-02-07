"====Ex2.1"
(define (new-make-rat n d)
  (if (< d 0) 
      (cons (- n) (- d))
      (cons n d)))
(new-make-rat 1 2)
(new-make-rat -1 2)
(new-make-rat 1 -2)
(new-make-rat -1 -2)
      
        