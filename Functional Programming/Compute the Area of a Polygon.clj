comment("
You are given the cartesian coordinates of a set of points in a 2D plane. When traversed sequentially, these points form a Polygon, P, which is not self-intersecting in nature. Can you compute the area of polygon P?

Input Format
The first line contains an integer, N, denoting the number of points.
The N subsequent lines each contain 2 space-separated integers denoting the respective x and y coordinates of a point.

Constraints
No 2 points are coincident, and polygon P is obtained by traversing the points in a counter-clockwise direction.
4 <= N <= 1000
0 <= x,y <= 1000

Output Format
For each test case, print the area of P (correct to a scale of one decimal place).
Note: Do not add any leading/trailing spaces or units; it is assumed that your result is in square units.
")

(def n (Integer/parseInt (clojure.string/trim (read-line))))
(def inputs [])
(doseq [n-itr (range n)]
    (def inputs (conj inputs (clojure.string/trim (read-line))))
)
(defn determinant [[point1 point2]]
  (- (* (:x point1) (:y point2))
     (* (:x point2) (:y point1))))

(defn get-points [inputs]
  (->> inputs
     (map #(clojure.string/split % #" "))
     (map (fn [lst]
            (map #(Integer/parseInt %) lst)
            )
          )
     (map #(hash-map :x (first %) :y (last %)))
     )
  )

(defn mount-polygon [inputs]
  (partition 2 1
             (let [points (get-points inputs)
                   start-point (first points)]
               (conj (into [] points) start-point))))

(defn area-polygon [polygon]
  (Math/abs (float (/ (reduce + (map determinant polygon)) 2))))

(println (area-polygon (mount-polygon inputs)))
