comment("
Objective
In this problem, we touch upon a basic concept that is fundamental to Functional Programming: identifying a relation which represents a valid function.

Task
You are given a set of unique (x,y) ordered pairs constituting a relation. The x-values form the domain, and the y-values form the range to which they map. For each of these relations, identify whether they may possibly represent a valid function or not.
Note: You do not have to find the actual function, you just need to determine that the relation may be representative of some valid function.

Input Format
The first line contains an integer, T, denoting the number of test cases. The subsequent lines describe T test cases, and the input for each test case is as follows:
The first line contains an integer, N, the number of (x,y) pairs in the test case.
The N subsequent lines each contain two space-separated integers describing the respective x and y values for each

Constraints
1 <= T <= 5
2 <= N <= 100
0 <= x,y <= 500
x and y are both integers

Output Format
On a new line for each test case, print YES if the set of ordered pairs represent a valid function, or NO if they do not.
")

(def n (Integer/valueOf (read-line)))
(defn validfn []
    (let [nv (Integer/parseInt (read-line))
          addxy (fn [s [x y]] (assoc s x (set (cons y (seq (get s x))))))
          mapping (reduce addxy {}
                          (for [_ (range nv)]
                               (map #(Integer/parseInt %) (re-seq #"[-\d.]+" (read-line)))))]
         (if (some #(> % 1) (map count (vals mapping))) "NO" "YES")
    ))
(doseq [_ (range n)]    
    (println (validfn)))
