comment("
Update the values of a list with their absolute values. The input and output portions will be handled automatically during grading. You only need to write a function with the recommended method signature.

Input Format
There are N integers, each on a separate line. These are the N elements of the input array.

Output Format
Output the absolute value of N integers, each on a separate line in the same input order.

Constraints
The list will have no more than 100 integers.
Each integer, X, in the list: -100 <= X <= 100
")

(fn[lst] (for [x lst] (Math/abs x)))
