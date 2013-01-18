#lang scheme

(define (monte-carlo trials experiment)
  (define (iter trials-remaining trials-passed)
    (cond ((= trials-remaining 0)
           (/ trials-passed trials))
          ((experiment)
           (iter (- trials-remaining 1) (+ trials-passed 1)))
          (else
           (iter (- trials-remaining 1) trials-passed))))
  (iter trials 0))
"====Ex3.5"
(define (random-in-range low high)
  (let ((range (- high low)))
    (+ low (random range))))

(define (estimate-integral P x1 x2 y1 y2 trials)
  (* (monte-carlo trials 
                  (lambda ()
                    (P (random-in-range x1 x2)
                       (random-in-range y1 y2))))
     (* (- x2 x1) (- y2 y1))))

(define (square x) (* x x))
(define (make-P x y r)
  (lambda (x1 y1)
    (<= (+ (square (- x x1)) (square (- y y1))) (square r))))

(define (estimate-pi x y r trials)
  (/ (estimate-integral (make-P x y r) 
                      (- x r) (+ x r) (- y r) (+ y r) trials) 
     (square r)))

(estimate-pi 5 7 3 100000)

"====Ex3.6"
(define (random-update x)
  (/ (* x x) 3))
(define rand
  (let ((x 32))
    (lambda (m)
      (define (generate)
        (set! x (random-update  x))
        x)
      (define (reset new-value)
        (set! x new-value))
      (define (dispatch m)
        (cond ((eq? m 'generate) (generate))
              ((eq? m 'reset) reset)
              (else (display "Unkown request" ))))
      (dispatch m))))
((rand 'reset) 1008611)
(rand 'generate)
(rand 'generate)
(rand 'generate)
((rand 'reset) 1008611)
(rand 'generate)
(rand 'generate)
(rand 'generate)