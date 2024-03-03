comment("
Count the number of elements in an array without using count, size or length operators (or their equivalents). The input and output portions will be handled automatically by the grader. You only need to write a function with the recommended method signature.

Input Format
A list of N integers, each on a separate line.

Output Format
Output a single integer N, the length of the list that was provided as input.

Constraints
1 <= N <= 100
Each element, X, in the list: 0 <= X <= 100
")

(fn[lst] (count lst))
