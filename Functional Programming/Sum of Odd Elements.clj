comment("
You are given a list. Return the sum of odd elements from the given list. The input and output portions will be handled automatically. You need to write a function with the recommended method signature.

Constraints
The list will have 1 -100 elements.
Each element will be an integer X where -100 <= X <= 100 
")

(fn[lst] (reduce + (filter #(odd? %) lst)))
