
"====Ex1.14"
;空间，就是最深的深度O(N)

;计算步数，和树的大小同阶
;f(n, 1) = f(n-1, 1) + f(n, 2) = O(N^5)
;f(n, 2) = f(n-2, 2) + f(n, 3) = O(N^4)
;f(n, 3) = f(n-3, 3) + f(n, 4) = O(N^3)
;f(n, 4) = f(n-4, 4) + f(n, 5) = f(n-4, 4) + O(n) = O(N^2)
;f(n, 5) = n / 5 = O(N)


"====Ex1.15"
(define (cube x) (* x x x))
(define p_x_cnt 0)
(define (inc x) (+ x 1))
(define (p x) (display x) (newline)(- (* 3 x) (* 4 (cube x))))
 
(define (sine angle)
  (if (not (> (abs angle) 0.1))
      angle
      (p (sine (/ angle 3.0)))))

(sine 12.15)
;>>> 12.15 / 3
;4.05
;>>> 12.15 / 3 / 3
;1.3499999999999999
;>>> 12.15 / 3 / 3 / 3
;0.44999999999999996
;>>> 12.15 / 3 / 3 / 3 /3
;0.15
;>>> 12.15 / 3 / 3 / 3 /3 /3
;0.049999999999999996
;3^n > 121.5
;nlog3> log(121.5)
;n = log(121.5)/log(3)
(ceiling (/ (log 121.5) (log 3)))
;空间和步数增长的阶都是一样的，都是O(log(n)) 