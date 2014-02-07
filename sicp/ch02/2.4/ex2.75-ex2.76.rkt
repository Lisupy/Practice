
"====Ex2.75"
(define (make-from-mag-ang r a)
  (define (dispatch op)
    (cond ((eq? op 'real-part) (* r (cos z)))
          ((eq? op 'imag-part) (* r (sin z)))
          ((eq? op 'magnitude) r)
          ((eq? op ''angle) a)
          (else
           (error "Unknow op -- MAKE-FROM-MAG-ANG" op))))
  dispatch)
"====Ex2.76"
;加入新类型，加入新操作
;显式分派==》都不合适
;数据导向==》合适加入新操作，想对合适加入新类型
;消息传递==》合适加入新类型，不合适加入新操作

          