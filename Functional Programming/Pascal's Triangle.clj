comment("
For a given integer K, print the first K rows of Pascal's Triangle. Print each row with each value separated by a single space. The value at the nth row and rth column of the triangle is equal to n!/(r! * (n - r)!) where indexing starts from 0. These values are the binomial coefficients.

The Pascal Triangle
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
....

Input Format
A single line of input, integer K.

Constraints
2 <= K <= 10

Output Format
Output the first K rows of Pascal's triangle.
")

(let [n (read-string (read-line))
      i '(1)]
  (loop [a i]
    (apply prn a)
    (when (< (count a) n)
      (recur (concat i (map + a (next a)) i)))))
