comment("
Objective
In this challenge, we learn how to compute GCD using the Euclidean algorithm.

Given two integers, x and y, a recursive technique to find their GCD is the Euclidean Algorithm.
The algorithm states that, for computing the GCD of two positive integers x and y, if x and y are equal, GCD(x,y) = x. Otherwise GCD(x,y) = GCD(x - y,y) if x > y. There are a few optimizations that can be made to the above logic to arrive at a more efficient implementation.

Task
Given the starter code, you need to complete a function body that returns the GCD of two given integers x and y.
The task of reading in input and printing the output will be handled by us.

Input Format
One line of input containing 2 space separated integers.

Constraints
1 <= a,b <= 10^6

Output Format
Output one integer, the GCD of the two given numbers.
")

(require '[clojure.string :as str])

(defn cmmdc [x y]
    (if (= x y) x
        (if (> x y) (recur (- x y) y)
            (recur x (- y x)))))

(let [line (map read-string (str/split (read-line) #" "))]
     (println (cmmdc (first line) (first (rest line)))))
