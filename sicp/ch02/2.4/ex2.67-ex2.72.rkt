#lang scheme
(define (make-leaf symbol weight)
  (list 'leaf symbol weight))
(define (leaf? object)
  (eq? (car object) 'leaf))
(define (symbol-leaf x) (cadr x))
(define (weight-leaf x) (caddr x))

(define (make-code-tree left right)
  (list left 
        right 
        (append (symbols left) (symbols right))
        (+ (weight left) (weight right))))
(define (left-branch tree) (car tree))
(define (right-branch tree) (cadr tree))
(define (symbols tree)
  (if (leaf? tree)
      (list (symbol-leaf tree))
      (caddr tree)))

(define (weight tree)
  (if (leaf? tree)
      (weight-leaf tree)
      (cadddr tree)))

(define (decode bits tree)
  (define (decode-1 bits current-branch)
    (if (null? bits)
        '()
        (let ((next-branch
               (choose-branch (car bits) current-branch)))
          (if (leaf? next-branch)
              (cons (symbol-leaf next-branch)
                    (decode-1 (cdr bits) tree))
              (decode-1 (cdr bits) next-branch)))))
  (decode-1 bits tree))

(define (choose-branch bit branch)
  (cond ((= bit 0) (left-branch branch))
        ((= bit 1) (right-branch branch))
        (else (error "bad bit -- CHOOSE-BRANCH" bit))))


(define (adjoin-set x set)
  (cond ((null? set) (list x))
        (( < (weight x) (weight (car set))) (cons x set))
        (else (cons (car set)
                    (adjoin-set x (cdr set))))))

(define (make-leaf-set pairs)
  (if (null? pairs)
      '()
      (let ((pair (car pairs)))
        (adjoin-set (make-leaf (car pair)
                               (cadr pair))
                    (make-leaf-set (cdr pairs))))))
(memq 'apple '(apple banana prune))
  

"====Ex2.67"
(define sample-tree
  (make-code-tree (make-leaf 'A 4)
                  (make-code-tree
                   (make-leaf 'B 2)
                   (make-code-tree (make-leaf 'D 1)
                                   (make-leaf 'C 1)))))
sample-tree
(define sample-message '(0 1 1 0 0 1 0 1 0 1 1 1 0))
"ADABBCA"
(decode sample-message sample-tree)

"====Ex2.68"
(define (encode message tree)
  (if (null? message)
      '()
      (append (encode-symbol (car message) tree)
              (encode (cdr message) tree))))
(define (encode-symbol symbol tree)
  (if (leaf? tree)
      (if (eq? (symbol-leaf tree) symbol)
          '() 
          (error "bad symbol" symbol))
      (cond ((memq symbol (symbols (left-branch tree))) (cons 0 (encode-symbol symbol (left-branch tree))))
            ((memq symbol (symbols (right-branch tree))) (cons 1 (encode-symbol symbol (right-branch tree))))
            (else (error "bad symbol" symbol )))))
(encode '(A D A B B C A) sample-tree)

"====Ex2.69"

(define (generate-huffman-tree pairs)
  (successive-merge (make-leaf-set pairs)))

(define (successive-merge pairs-set)
  (if (null? (cdr pairs-set))
      (car pairs-set)
      (successive-merge (adjoin-set (make-code-tree (car pairs-set) 
                                                    (cadr pairs-set))
                                    (cddr pairs-set)))))
(generate-huffman-tree '((A 4) (B 2) (C 1) (D 1)))
(define result (generate-huffman-tree '((A 4) (B 2) (C 1) (D 1))))
'((leaf A 4) ((leaf B 2) ((leaf D 1) (leaf C 1) (D C) 2) (B D C) 4) (A B D C) 8)
"====Ex2.70"
(define message '(GET A JOB ;3
                      SHA NA NA NA NA NA NA NA NA;9
                      GET A JOB;3
                      SHA NA NA NA NA NA NA NA NA;9
                      WAH YIP YIP YIP YIP YIP YIP YIP YIP YIP;10
                      SHA BOOM));2
(+ 3 9 3 9 10 2)
(define pairs '((A 2) (NA 16) (BOOM 1) (SHA 3) (GET 2) (JOB 2) (YIP 9) (WAH 1)))
(define huffman-tree (generate-huffman-tree pairs))
huffman-tree
(encode message huffman-tree)
(length (encode message huffman-tree))
"定长编码需要36*log(8)=36*3=108"

"====Ex2.71"
 
"最频繁的是1位"
"最频繁的是n-1位"
"
http://sicp.readthedocs.org/en/latest/chp2/71.html
       *
       /\
      *  16
     /\
    *  8
   / \
  *   4
 /\
1  2
                     *
                 /\
                *  512
               /\
              *  256
             /\
            * 128
           /\
          *  64
         /\
        *  32
       /\
      *  16
     /\
    *  8
   / \
  *   4
 /\
1  2
"
"====Ex2.72"
"每一步是O(n)，总共是O(n^2)"
"和C语言写本质是一样的，没有使用堆O(nLogN)或双链表（O(n))"
"而且还取决于需要排序O(nLogN)"