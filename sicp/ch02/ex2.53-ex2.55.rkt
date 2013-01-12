#lang scheme


"====Ex2.53"
"(a b c)"
(list 'a 'b 'c)

"((george))"
(list (list 'george))

"(y1 y2)"
(cdr '((x1 x2) (y1 y2)))

"#f"
(pair? (car '(a short list)))

"#f"
(memq 'red '((red shoes) (blue socks)))

"(red shoes blue socks)"
(memq 'red '(red shoes blue socks))

"====Ex2.54"
(define (my-equal? a b)
  (cond ((null? a) (null? b))
        ((eq? (car a) (car b)) (my-equal? (cdr a) (cdr b)))
        (else false)))
                   
(equal? '(this is a list) '(this is a list))
(my-equal? '(this is a list) '(this is a list))
(equal? '(this is a list) '(this (is a) list))
(my-equal? '(this ia a list) '(this (is a) list))

"====Ex2.55"
;因为 'abracadabra 在解析器里是 (quote 'abracadabra)
;然后 ''abracadabra 就是 '(quote 'abracadabra)
;因此 (car ''abracadabra) 等价于 (car '(quote 'abracadabra))
 (car ''abracadabra)
 (car '(quote 'abracadabra))