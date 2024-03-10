comment("
You are given the cartesian coordinates of a set of points in a 2D plane. When traversed sequentially, these points form a Polygon, P, which is not self-intersecting in nature. Can you compute the perimeter of polygon P?

Input Format
The first line contains an integer, N, denoting the number of points.
The N subsequent lines each contain 2 space-separated integers denoting the respective x and y coordinates of a point.

Constraints
No 2 points are coincident, and polygon P is obtained by traversing the points in a clockwise direction.
3 <= N <= 1000
0 <= x,y <= 1000

Output Format
For each test case, print the perimeter of P (correct to a scale of one decimal place).
Note: Do not add any leading/trailing spaces or units.
")

(ns lab
  (:require [clojure.string :as str]))
(defn read-value []
  (map #(Integer/parseInt %) (-> (read-line) (str/split #" "))))
(defn calc-dist [x y]
  (let [a (first x) b (-> x rest first)
        c (first y) d (-> y rest first)]
    (Math/sqrt (+ (Math/pow (- c a) 2)
                  (Math/pow (- d b) 2)))))
(def i (atom 0))
(def ans (atom 0.0))
(defn solution []
  (let [N (first (read-value))
        POINTS (repeatedly N #(read-value))
        LIMIT (- N 1)
        FIRST (first POINTS)
        LAST  (last POINTS)]
    (while (< @i LIMIT)
      (swap! ans #(+ % (calc-dist (nth POINTS @i)
                                  (nth POINTS (inc @i)))))
      (swap! i inc))
    (println (+ @ans (calc-dist FIRST LAST)))))
(solution)
