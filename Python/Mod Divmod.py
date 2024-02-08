'''
One of the built-in functions of Python is divmod, which takes two arguments a and b and returns a tuple containing the quotient of a/b first and then the remainder a.

Task
Read in two integers, a and b, and print three lines.
The first line is the integer division a//b (While using Python2 remember to import division from __future__).
The second line is the result of the modulo operator: a%b.
The third line prints the divmod of a and b.

Input Format
The first line contains the first integer, a, and the second line contains the second integer, b.

Output Format
Print the result as described above.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
a = int(input())
b = int(input())
c = divmod(a,b)
for i in c:
    print(i)
print(c)
