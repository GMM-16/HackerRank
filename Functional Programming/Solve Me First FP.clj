comment("
This is an introductory challenge. The purpose of this challenge is to give you a working I/O template in your preferred language. It includes scanning 2 integers from STDIN, calling a function, returning a value, and printing it to STDOUT.
Your task is to scan two numbers, A and B from STDIN, and print the sum A + B on STDOUT.
Note: The code has been saved in a template that you can submit if you want.
        
Input Format
You are given two integers, A and B on separate lines.
        
Output Format
Output an integer that denotes A + B
        
Constraints
1 <= A,B<= 1000
")

(defn solveMeFirst [x y]    
    (+ x y))
(def a (read-line))
(def b (read-line))
(println (solveMeFirst (Integer/parseInt a) (Integer/parseInt b)))
