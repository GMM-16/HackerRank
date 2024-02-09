'''
Integers in Python can be as big as the bytes in your machine's memory. There is no limit in size as there is: 2^31-1 (c++ int) or 2^63-1 (C++ long long int).
As we know, the result of a^b grows really fast with increasing b.
Let's do some calculations on very large integers.

Task
Read four numbers, a, b, c, and d, and print the result of a^b+c^d

Input Format
Integers a, b, c, and d are given on four separate lines, respectively.

Constraints
1 <= a <= 1000
1 <= b <= 1000
1 <= c <= 1000
1 <= d <= 1000

Output Format
Print the result of a^b+c^d on one line.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
a = int(input())
b = int(input())
c = int(input())
d = int(input())
first_int = pow(a, b)
second_int = pow(c, d)
print(first_int+second_int)
