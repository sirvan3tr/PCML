(define test-string "div\n\tmain.vmainClass1.vmainClass2\n\t\tdiv#main-container\n\t\t\tdiv#keyboard-shortcut.class2\n\t\t\t\tdiv\n\t\t\t\tdiv\n\t\tdiv.form-container\n\t\t\tform method=post\n\t\tv-icon\n\t\t\tv-con")

(define (loop string count)
  (unless (< count 0)
    ;(print (string-ref string count))
    ;(print (string-ref string count))
    (get-split string count)
    (print count (string-ref string count) (tab? (string-ref string count)))
    (print "------------------------")
    (loop string (sub1 count))))

(define (tab? char)
  (if (equal? char #\tab)
      "-------------|tab"
      "not-tab"
      ))

(define (get-split string count)
  (if (= count (sub1 (string-length string)))
      (determine-split (string-ref string count) " ")
      (determine-split (string-ref string count) (string-ref string (add1 count)))
      ;(print ":: count= " count " :: string-count: " (string-length string))
      ))

(define (determine-split char1 char2)
  (print char1)
  (print char2)
  (if (and (equal? char1 #\tab) (not (equal? char2 #\tab)))
    (print "yes")
    (print "No")
    ))

(loop test-string (sub1 (string-length test-string)))
(display test-string)

