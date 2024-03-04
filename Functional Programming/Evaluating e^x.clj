comment("
The series expansion of e^x is given by:
1 + x + x^2/2! + x^3/3! + x^4/4! + .....
Evaluate e^x for given values of x by using the above expansion for the first 10 terms.

Input Format
The first line contains an integer N, the number of test cases.
N lines follow. Each line contains a value of x for which you need to output the value of e^x using the above series expansion. These input values have exactly 4 decimal places each.

Output Format
Output N lines, each containing the value of e^x, computed by your program.

Constraints
1 <= N <= 50
-20.00 <= x <= 20.00
Var, Val in Scala and def and defn in Clojure are blocked keywords. The challenge is to accomplish this without either mutable state or direct declaration of local variables.
")

(defn fact[x] (if (= x 0) 1 (reduce * (range 1 (inc x)))))
(defn expf[x] (loop [sum 0.0 i 0](if (= i 10) sum (recur (+ (/ (Math/pow x i) (fact i))sum)(inc i)))))
(def n (Integer/parseInt (clojure.string/trim (read-line))))
(doseq [n-itr (range n)](def x (Double/parseDouble (clojure.string/trim (read-line))))(println (expf x)))
