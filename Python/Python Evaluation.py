'''
The eval() expression is a very powerful built-in function of Python. It helps in evaluating an expression. The expression can be a Python statement, or a code object.
Here, eval() can also be used to work with Python keywords or defined functions and variables. These would normally be stored as strings.

Task
You are given an expression in a line. Read that line as a string variable, such as var, and print the result using eval(var).

NOTE: Python2 users, please import from __future__ import print_function.

Constraint
Input string is less than 100 characters.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
n = input().split('print')
print(eval(n[1]))
