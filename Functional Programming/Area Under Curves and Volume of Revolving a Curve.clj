comment("
Definite Integrals via Numerical Methods
This relates to definite integration via numerical methods.
Consider the algebraic expression given by:
(a1)x^b1 + (a2)x^b2 + (a3)x^b3 ..... (an)x^bn
For the purpose of numerical computation, the area under the curve y = f(x) between the limits a and b can be computed by the Limit Definition of a Definite Integral.
Here is some background about areas and volume computation.
Using equal subintervals of length 0.001, you need to:
Evaluate the area bounded by a given polynomial function of the kind described above, between the given limits of L and R.
Evaluate the volume of the solid obtained by revolving this polynomial curve around the x-axis.
A relative error margin of 0.01 will be tolerated.

Input Format
The first line contains N integers separated by spaces, which are the values of a1,a2,.....an.
The second line contains N integers separated by spaces, which are the values of b1,b2,.....b2.
The third line contains two space separated integers, L and R, the lower and upper range limits in which the integration needs to be performed, respectively.

Constraints
-1000 <= a <= 1000
-20 <= b <= 20
1 <= L < R <= 20

Output Format
The first line should contain the area between the curve and the x-axis, bound between the specified limits.
The second line should contain the volume of the solid obtained by rotating the curve around the x-axis, between the specified limits.
")

; Enter your code here. Read input from STDIN. Print output to STDOUT
;
(defn f [x coeff exp res]
 (if (empty? coeff)
    res
    (recur x (rest coeff) (rest exp) (+ res (* (first coeff) (Math/pow x (first exp)))))))

(defn calc-area-volume [coeff exp intvl c area volume]
 (let [iter (/ (- (second intvl) (first intvl)) 0.001)
        x (+ (first intvl) (* 0.001 c))
        r (f x coeff exp 0)]
    (if (<= c iter)
      (recur coeff exp intvl (inc c) (+ area (* 0.001 r)) (+ volume (* (* Math/PI (Math/pow r 2)) 0.001)))
      [area volume])))
(defn read-as-list []
 (map #(Double/parseDouble %) (clojure.string/split (read-line) #"\s+")))
(defn -main []
 (let [coeff (read-as-list)
        expon (read-as-list)
        intvl (read-as-list)]
    (let [[area volume] (calc-area-volume coeff expon intvl 1 0 0)]
      (println (format "%.1f" area))
      (println (format "%.1f" volume)))))
(-main)
