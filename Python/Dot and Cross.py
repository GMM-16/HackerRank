'''
dot
The dot tool returns the dot product of two arrays.

import numpy
A = numpy.array([ 1, 2 ])
B = numpy.array([ 3, 4 ])
print numpy.dot(A, B)       #Output : 11

cross
The cross tool returns the cross product of two arrays.

import numpy
A = numpy.array([ 1, 2 ])
B = numpy.array([ 3, 4 ])
print numpy.cross(A, B)     #Output : -2

Task
You are given two arrays A and B. Both have dimensions of N X N.
Your task is to compute their matrix product.

Input Format
The first line contains the integer N.
The next N lines contains  space separated integers of array A.
The following N lines contains N space separated integers of array B.

Output Format
Print the matrix multiplication of A and B.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import numpy
n=int(input())
a,b=[],[]
for _ in range(n):
    a.append(list(map(int,input().split())))
for _ in range(n):
    b.append(list(map(int,input().split())))
print(numpy.dot(numpy.array(a),numpy.array(b)))
