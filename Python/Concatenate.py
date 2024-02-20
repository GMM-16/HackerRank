'''
Concatenate
Two or more arrays can be concatenated together using the concatenate function with a tuple of the arrays to be joined:

import numpy
array_1 = numpy.array([1,2,3])
array_2 = numpy.array([4,5,6])
array_3 = numpy.array([7,8,9])
print numpy.concatenate((array_1, array_2, array_3))    
#Output
[1 2 3 4 5 6 7 8 9]

If an array has more than one dimension, it is possible to specify the axis along which multiple arrays are concatenated. By default, it is along the first dimension.

Task
You are given two integer arrays of size N X P and M X P (N & M are rows, and P is the column). Your task is to concatenate the arrays along axis 0.

Input Format
The first line contains space separated integers N, M and P.
The next N lines contains the space separated elements of the P columns.
After that, the next M lines contains the space separated elements of the P columns.

Output Format
Print the concatenated array of size (N + M) X P.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT

import numpy
  
def get_input_list(n):
    arr = []
    for i in range(int(n)):
        line = [int(x) for x in input().split(" ")]
        arr.append(line)
    return arr

def concatenate_arrays():  
    n, m, p = input().split(" ")
    array_a = get_input_list(n)
    array_b = get_input_list(m)
    print(numpy.concatenate((array_a, array_b), axis=0))
    
if __name__ == "__main__":
    concatenate_arrays()
