'''
There will be two arrays of integers. Determine all integers that satisfy the following two conditions:
The elements of the first array are all factors of the integer being considered
The integer being considered is a factor of all elements of the second array
These numbers are referred to as being between the two arrays. Determine how many such numbers exist.

Function Description
Complete the getTotalX function in the editor below. It should return the number of integers that are betwen the sets.
getTotalX has the following parameter(s):
int a[n]: an array of integers
int b[m]: an array of integers
Returns
- int: the number of integers that are between the sets

Input Format
The first line contains two space-separated integers, n and m, the number of elements in arrays a and b.
The second line contains  distinct space-separated integers a[i] where 0 <= i < n.
The third line contains  distinct space-separated integers b[j] where 0 <= j < m.

Constarints
1 <= n,m <= 10
1 <= a[i] <= 100
1 <= b[j] <= 100
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'getTotalX' function below.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b
#

def getTotalX(a, b):
    # Write your code here
    a_size = len(a)
    b_size = len(b)
    ans = 0
    end = a[-1]
    
    for x in range(end, b[0] + 1):
        factor = True
        
        for i in range(a_size):
            if x % a[i] != 0:
                factor = False
                break
        
        if factor:
            for i in range(b_size):
                if b[i] % x != 0:
                    factor = False
                    break
        
        if factor:
            ans = ans + 1
            
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    brr = list(map(int, input().rstrip().split()))

    total = getTotalX(arr, brr)

    fptr.write(str(total) + '\n')

    fptr.close()
