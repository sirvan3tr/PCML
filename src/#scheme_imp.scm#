;; A 'for .. in ..' iteration like python, for lists
(define-syntax for
  (syntax-rules (in)
                ((for elem in alist body ...)
                 (for-each (lambda (elem) body ...) alist))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define test-string "div\n\tmain.vmainClass1.vmainClass2\n\t\tdiv#main-container\n\t\t\tdiv#keyboard-shortcut.class2\n\t\t\t\tdiv\n\t\t\t\tdiv\n\t\tdiv.form-container\n\t\t\tform method=post\n\t\tv-icon\n\t\t\tv-con")

(define (loop string count max pos)
  (let ((elements "2"))
  (unless (> count max)
    (if (get-split string count max)
        ((print (substring string pos count))
         (loop string (add1 count) max count))
        loop string (add1 count) max pos)
    )
    ;(print count (string-ref string count) (tab? (string-ref string count)))
    )))


(define (get-split string count max)
  (if (= count max)
      (determine-split (string-ref string count) "")
      (determine-split (string-ref string count) (string-ref string (add1 count)))
      ))

(define (determine-split char1 char2)
  (if (and (equal? char1 #\tab) (not (equal? char2 #\tab)))
      #t #f))

(for x in '(2 4 8 16)
     (print x))

(loop test-string 0 (sub1 (string-length test-string)) 0)
(display test-string)

(define (tab? char)
  (if (equal? char #\tab)
      "-------------|tab"
      "not-tab"
      ))

