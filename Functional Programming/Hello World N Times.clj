comment("
Print "Hello World" N amount of times. The input portion will be handled automatically. You need to write a function with the recommended method signature.

Input Format
A single line of input containing integer N, the number of times to print "Hello World".

Output Format
Output N lines, each containing "Hello World".

Constraints
0 <= N <= 50
")

(defn hello_word_n_times[n]
    (dotimes [_ n]
        (println "Hello World")))
(def n (Integer/parseInt (read-line)))
(hello_word_n_times n)

