'''
Let's dive into the interesting topic of regular expressions! You are given some input, and you are required to check whether they are valid mobile numbers.
A valid mobile number is a ten digit number starting with a 7,8 or 9.

Concept
A valid mobile number is a ten digit number starting with a 7,8 or 9.
Regular expressions are a key concept in any programming language. A quick explanation with Python examples is available here. You could also go through the link below to read more about regular expressions in Python.

Input Format
The first line contains an integer N, the number of inputs.
N lines follow, each containing some string.

Constraints
1 <= N <= 10
2 <= len(Number) <= 15

Output Format
For every string listed, print "YES" if it is a valid mobile number and "NO" if it is not on separate lines. Do not print the quotes.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
pattern = '^[789]\d{9}$'
for _ in range(int(input())):
    if re.findall(pattern, input()):
        print("YES")
    else:
        print("NO")
