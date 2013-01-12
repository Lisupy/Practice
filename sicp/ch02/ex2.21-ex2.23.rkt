(define nil ())
"====Ex2.21"
(define square (lambda (x) (* x x)))
(define (square-list items)
  (if (null? items)
      nil
      (cons (square (car items))
            (square-list (cdr items)))))
(square-list (list 1 2 3 4 5))

(define (square-list items)
  (map square items))
(square-list (list 1 2 3 4 5))

"====Ex2.22"
(define (square-list items)
  (define (iter things answer)
    (if (null? things)
        answer
        (iter (cdr things)
              (cons (square (car things))
                    answer))))
  (iter items nil))
(square-list (list 1 2 3 4 5))

(define (square-list items)
  (define (iter things answer)
    (if (null? things)
        answer
        (iter (cdr things)
              (cons answer
                    (square (car things))))))
  (iter items nil))
(square-list (list 1 2 3 4 5))

(define (square-list items)
  (define (iter things answer)
    (if (null? things)
        answer
        (iter (cdr things)
              (append answer
                    (list (square (car things)))))))
  (iter items nil))
(square-list (list 1 2 3 4 5))

"====Ex2.23"
(for-each (lambda (x) (newline) (display x))
          (list 57 321 88))
(define (my-for-each proc items)
  (if (not (null? items))
      (begin (proc (car items))
             (my-for-each proc (cdr items)))))
(my-for-each (lambda (x) (newline) (display x))
          (list 57 321 88))