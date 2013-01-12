
"====Ex1.11"
;Exercise 1.11.  A function f is defined by the rule that f(n) = n if n<3 and f(n) = f(n - 1) + 2f(n - 2) + 3f(n - 3) if n>= 3. Write a procedure that computes f by means of a recursive process. Write a procedure that computes f by means of an iterative process.
(define (f-recursive n)
  (if (>= n 3) 
      (+ (f-recursive (- n 1))
         (* 2
            (f-recursive (- n 2)))
         (* 3
            (f-recursive (- n 3))))
      n))
(define (f-iterative n)
  (define (f-iter f_i-1 f_i-2 f_i-3 i i-end)
    (define f_i (+ f_i-1
                   (* 2 f_i-2)
                   (* 3 f_i-3)))
    (display i)
    (display "==>")
    (display f_i)
    (newline)
    (cond ((= i i-end) f_i)
          (else (f-iter f_i f_i-1 f_i-2 (+ 1 i) i-end))))
  (cond ((< n 3) n)
        (else (f-iter 2 1 0 3 n))))
(f-recursive 10)     
(f-iterative 10)

"====Ex1.12"
(define (pascal-triangle row col) 
  (cond ((> col row) 0) 
        ((< col 0) 0) 
        ((= col 1) 1) 
        ((+ (pascal-triangle (- row 1) (- col 1)) 
            (pascal-triangle (- row 1) col))))) 
(pascal-triangle 1 1) 
(pascal-triangle 2 2) 
(pascal-triangle 3 2) 
(pascal-triangle 4 2) 
(pascal-triangle 5 2) 
(pascal-triangle 5 3) 
;0 0 0 0 1
;0 0 0 1 4
;0 0 1 3 6
;0 1 2 3 4
;1 1 1 1 1
"暂时不做: 不会操作列表"
"====EX1.13"
;http://www.cppblog.com/cuigang/archive/2008/03/12/44316.html
"中文版原题翻译遗漏 提示 :ψ=(1-√5)/2
已知，φ^2 = φ + 1, 那么 φ^n = φ^(n-1) + φ^(n-2)
同理，ψ^2 = ψ + 1, 那么 ψ^n = ψ^(n-1) + ψ^(n-2)
又 φ-ψ = (1+√5)/2 - (1-√5)/2 = √5

when n=0, Fib(0) = 0 = (φ^0-ψ^0)/√5
when n=1, Fib(1) = 1 = √5/√5 = (φ-ψ)/√5
when n>2, Fib(n) = Fib(n-1) + Fib(n-2) = (φ^(n-1)-ψ^(n-1))/√5 + (φ^(n-2)-ψ^(n-2))/√5
                 = ((φ^(n-1)+(φ^(n-2))) - (ψ^(n-1)+ψ^(n-2)))/√5
                 = (φ^n - ψ^n)/√5

又 -1< ψ < 0, 故 -0.5< -1/√5< ψ^n/√5 < 1/√5 <0.5 , 而 φ^n/√5 = ψ^n/√5 + Fib(n)

可知 |φ^n/√5 - Fib(n)| < 0.5, Fib(n)是最接近φ^n/√5的整数。"
