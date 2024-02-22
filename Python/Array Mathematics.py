'''
Basic mathematical functions operate element-wise on arrays. They are available both as operator overloads and as functions in the NumPy module.

import numpy

a = numpy.array([1,2,3,4], float)
b = numpy.array([5,6,7,8], float)
print a + b                     #[  6.   8.  10.  12.]
print numpy.add(a, b)           #[  6.   8.  10.  12.]
print a - b                     #[-4. -4. -4. -4.]
print numpy.subtract(a, b)      #[-4. -4. -4. -4.]
print a * b                     #[  5.  12.  21.  32.]
print numpy.multiply(a, b)      #[  5.  12.  21.  32.]
print a / b                     #[ 0.2         0.33333333  0.42857143  0.5       ]
print numpy.divide(a, b)        #[ 0.2         0.33333333  0.42857143  0.5       ]
print a % b                     #[ 1.  2.  3.  4.]
print numpy.mod(a, b)           #[ 1.  2.  3.  4.]
print a**b                      #[  1.00000000e+00   6.40000000e+01   2.18700000e+03   6.55360000e+04]
print numpy.power(a, b)         #[  1.00000000e+00   6.40000000e+01   2.18700000e+03   6.55360000e+04]

Task
You are given two integer arrays, A and B of dimensions N X M.
Your task is to perform the following operations:
Add (A + B)
Subtract (A - B)
Multiply (A * B)
Integer Division (A / B)
Mod (A % B)
Power (A ** B)

Note
There is a method numpy.floor_divide() that works like numpy.divide() except it performs a floor division.

Input Format
The first line contains two space separated integers, N and M.
The next N lines contains M space separated integers of array A.
The following N lines contains M space separated integers of array B.

Output Format
Print the result of each operation in the given order under Task.
'''

import numpy
n = list(map(int,input().split()))
n1 = [list(map(int,input().split())) for i in range(n[0])]
n2 = [list(map(int,input().split())) for i in range(n[0])]
print(numpy.add(n1,n2))
print(numpy.subtract(n1,n2))
print(numpy.multiply(n1,n2))
print(numpy.floor_divide(n1,n2))
print(numpy.mod(n1,n2))
print(numpy.power(n1,n2))
