'''
Transpose
We can generate the transposition of an array using the tool numpy.transpose.
It will not affect the original array, but it will create a new array.

import numpy
my_array = numpy.array([[1,2,3],
                        [4,5,6]])
print numpy.transpose(my_array)
#Output
[[1 4]
 [2 5]
 [3 6]]

 Flatten
The tool flatten creates a copy of the input array flattened to one dimension.

import numpy
my_array = numpy.array([[1,2,3],
                        [4,5,6]])
print my_array.flatten()
#Output
[1 2 3 4 5 6]

Task
You are given a NXM integer array matrix with space separated elements (N = rows and M = columns).
Your task is to print the transpose and flatten results.

Input Format
The first line contains the space separated values of N and M.
The next N lines contains the space separated elements of M columns.

Output Format
First, print the transpose array and then print the flatten.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import numpy
rows_and_cols = list(map(int, input().split()))
rows = rows_and_cols[0]
cols = rows_and_cols[1]
arr = []
for i in range(rows):
    arr.append(list(map(int, input().split()))) 
new_arr = numpy.array(arr)
print(numpy.transpose(new_arr))
print(new_arr.flatten())
