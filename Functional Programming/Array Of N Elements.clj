comment("
Create an array of n integers, where the value of n is passed as an argument to the pre-filled function in your editor. This challenge uses a custom checker, so you can create any array of n integers.
Note: Code stubs are provided for almost every language in which you must either fill in a blank (i.e., ____) or write your code in the area specified by comments.

Method Signature
Number Of Parameters: 1
Parameters: [n]
Returns: List or Vector

Input Format
A single integer, n.

Constraints
1 <= n <= 100
The members returned by the list/vector/array must be integers.

Output Format
The function must return an array, list, or vector of n integers. Stub code in the editor prints this to stdout as a space, comma, or semicolon-separated list (depending on your submission language).
Note: Your output need not match the Expected Output exactly; the size of your printed list is confirmed by a custom checker, which determines whether or not you passed each test case.
")

(
    let [lines (line-seq (java.io.BufferedReader. *in*))] (
        println(

            (fn[n] (range n))

            (Integer. (first lines))
        )
    )
)
