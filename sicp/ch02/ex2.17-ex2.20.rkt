"====Ex2.17"
(define (my-last-pair list)
  (if (null? (cdr list))
      list
      (my-last-pair (cdr list))))
(my-last-pair (list 1 2 3 4 5))
(my-last-pair (list 1))
#(my-last-pair (list))

"====Ex2.18"
(define (my-reverse alist)
  (if (null? alist)
      alist
      (append (my-reverse (cdr alist))
            (list (car alist)))))
(car (list 1 2 3 4 5))
(my-reverse (list 1 2 3 4 5))

"====Ex2.19"
(define (cc amount coin-values)
  (cond ((= amount 0) 1)
        ((or (< amount 0) (no-more? coin-values)) 0)
        (else
         (+ (cc amount
                (except-first-demination coin-values))
            (cc (- amount
                   (first-denomination coin-values))
                coin-values)))))

(define except-first-demination cdr)
(define first-denomination car)
(define no-more? null?)
(define us-coins (list 50 25 10 5 1))
(define uk-coins (list 100 50 20 10 5 2 1 0.5))
(cc 100 us-coins)
(define us-coins (list 5 1 25 50 10))
(cc 100 us-coins)

"====Ex2.20"
(define (same-parity x . z)
  (define filter (if (odd? x) odd? even?))
  (define (filter-list al)
    (if (null? al)
        al
        (if (filter (car al))
            (cons (car al) (filter-list (cdr al)))
            (filter-list (cdr al)))))
  (cons x (filter-list z)))
(same-parity 1 2 3 4 5 6 7)
(define (same-parity x . z)
  (define filter (if (odd? x) odd? even?))
  (define (filter-list al)
    (if (null? al)
        al
        (append (if (filter (car al))
                    (list (car al))
                    ()) 
                (filter-list (cdr al)))))
  (cons x (filter-list z)))
(same-parity 1 2 3 4 5 6 7)
