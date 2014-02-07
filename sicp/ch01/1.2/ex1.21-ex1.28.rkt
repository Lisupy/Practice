;要选择“大”语言
"====Ex1.21"
;Exercise 1.21.  Use the smallest-divisor procedure to find the smallest divisor of each of the following numbers: 199, 1999, 19999.
(define (next-test-divisor n) (+ n 1))
(define (smallest-divisor n)
  (find-divisor n 2))
(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divides? test-divisor n) test-divisor)
        (else (find-divisor n (next-test-divisor test-divisor)))))
(define (divides? a b)
  (= (remainder b a) 0))
(define (square x)
  (* x x))
(smallest-divisor 199)
(smallest-divisor 1999)
(smallest-divisor 19999)


"==========================="
(define (smallest-divisor n)
  (find-divisor n 2))
(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divides? test-divisor n) test-divisor)
        (else (find-divisor n  (next-test-divisor test-divisor)))))
(define (divides? a b)
  (= (remainder b a) 0))

(define (prime? n)
  (= n (smallest-divisor n)))
"====Ex1.22"
;Exercise 1.22.  Most Lisp implementations include a primitive called runtime that returns an integer that specifies the amount of time the system has been running (measured, for example, in microseconds). The following timed-prime-test procedure, when called with an integer n, prints n and checks to see if n is prime. If n is prime, the procedure prints three asterisks followed by the amount of time used in performing the test.

(define (timed-prime-test n)
  (newline)
  (display n)
  (start-prime-test n (runtime)))
(define (start-prime-test n start-time)
  (display "::")
  (display n)
  (if (my-prime? n)
      (report-prime (- (runtime) start-time))))
(define (report-prime elapsed-time)
  (display " *** ")
  (display elapsed-time))
(define my-prime? prime?)
;Using this procedure, write a procedure search-for-primes that checks the primality of consecutive odd integers in a specified range. Use your procedure to find the three smallest primes larger than 1000; larger than 10,000; larger than 100,000; larger than 1,000,000. Note the time needed to test each prime. Since the testing algorithm has order of growth of (n), you should expect that testing for primes around 10,000 should take about 10 times as long as testing for primes around 1000. Do your timing data bear this out? How well do the data for 100,000 and 1,000,000 support the n prediction? Is your result compatible with the notion that programs on your machine run in time proportional to the number of steps required for the computation?

;
"Racket上不支持runtime"
(define (runtime) (current-milliseconds))

(define (search-for-primes a b)  
  (define (next guess)
    (+ guess 1))
  (define (helper)
    (timed-prime-test a)
    (search-for-primes (next a) b))
  (if (<= a b)
      (helper)))
(search-for-primes 100000000 100000010)
(define (search-for-a-prime-above n)
  (define (next guess)
    (+ guess 1))
  (if (my-prime? n)
      (start-prime-test n (runtime))
      (search-for-a-prime-above (next n))))
(define (search-for-primes-above-pow-n n k)
  (define (iter i)
    (if (<= i k)
        ((lambda () 
           (newline)
           (display i)
           (display ":")          
           (display (expt n i))            
           (search-for-a-prime-above (expt n i))
           (iter (+ i 1))))))
  (iter 1))
;(search-for-primes-above-pow-n 10 15)
(newline)
"====Ex1.23"
(define (next-test-divisor n) 
  (if (even? n)
      (+ n 1)
      (+ n 2)))

;(search-for-primes-above-pow-n 10 15)

"====Ex1.24"
(define (expmod base exp m)
  (cond ((= exp 0) 1)
         ((even? exp) (remainder (square (expmod base (/ exp 2) m)) m))
         (else (remainder (* base (expmod base (- exp 1) m)) m))))

(define (fermat-test n)
  ;(display n)
  ;(newline)
  (define (try-it a)
    (= (expmod a n n) a))
  (try-it (+ 1 (random (- (min n 4294967087) 1)))))

(define (fast-prime? n times)
  (cond ((= times 0) true)
        ((fermat-test n) (fast-prime? n (- times 1)))
        (else false)))
;(fast-prime? 10 10)
(define (my-prime? n) (fast-prime? n 10))
;(search-for-primes-above-pow-n 10 150)
;常数太小了，看不出来，而且随机用来做测试的数的大小也不一样

"====Ex1.25"
;会增加很多时间，因为计算exp后，数字太大了


"====Ex1.26"
;这样，就变成了树形递归，而不是线性递归

"====Ex1.27"
(define (test-carmichael n)
  (define (try-it a)
    (= (expmod a n n) a))
  (define (iter i)
    (if (< i n)
        ((lambda () (if (try-it i) ((lambda () (display i) (newline))))
        (iter (+ i 1))))))
  (iter 1))
(test-carmichael 561)
(prime? 561)
(test-carmichael 562)


"====Ex1.28"
;完备性证明见<<CLRS>>
(define (miller-rabin n m)
  (define (square_mod x)
    (remainder (square x) n))
  (define (mult_mod a b)
    (remainder (* a b) n))
  (define (miller-rabin-expmod base exp result)
    (define (square_mod_test_fail?)
      (and (= 1 (square_mod base)) 
           (not (or (= base (- n 1)) 
                    (= base 1))))) 
    ;(display "base=")
    ;(display base)
    ;(display " exp=")
    ;(display exp)
    ;(newline)
    (cond ((= exp 0) (= result 1))
          ((even? exp) (if (square_mod_test_fail?)
                           ((lambda () ()
                             ; (display "   base=")
                             ; (display base)
                             ; (display " exp=")
                             ; (display exp)
                             ; (newline))
                              ))
                           (miller-rabin-expmod (square_mod base) 
                                                (/ exp 2) result)))
          (else (miller-rabin-expmod base
                                     (- exp 1)
                                     (mult_mod result base)))))
;  (display "m=")
;  (display m)
;  (display " n=")
;  (display n)
 ; (newline)
  (miller-rabin-expmod m (- n 1) 1))

(define (fast-prime? n times)
  (if (= times 0)
      true
      (if (miller-rabin n (+ (random (- n 1)) 1))
          (fast-prime? n (- times 1))
          false)))
(define (my-fast-prime? n)
  (fast-prime? n 100))
;(miller-rabin 11 7)
;(my-fast-prime? 5)
;(prime? 5)
(define (check-prime-range range-left range-right prime-check)
  (if (= (remainder range-left 10000) 1)
      (display range-left))
  (if (< range-left range-right)
      (if (eq? (prime-check range-left)
             (prime? range-left))
          (check-prime-range (+ range-left 2) range-right prime-check)
          (display range-left))))
(check-prime-range 3 10000000 my-fast-prime?)