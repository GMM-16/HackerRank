'''
Given a square matrix, calculate the absolute difference between the sums of its diagonals.
Function description
Complete the  function in the editor below.
diagonalDifference takes the following parameter:
int arr[n][m]: an array of integers
Return
- int: the absolute diagonal difference
Input Format
The first line contains a single integer, n, the number of rows and columns in the square matrix arr.
Each of the next n lines describes a row, arr[i], and consists of n space-separated integers arr[i][j].
Constraints
-100 <= arr[i][j] <= 100
Output Format
Return the absolute difference between the sums of the matrix's two diagonals as a single integer.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'diagonalDifference' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def diagonalDifference(arr):
    # Write your code here
    ldiag = 0
    rdiag = 0
    for i in range(len(arr)):
        ldiag = ldiag + arr[i][i]
        rdiag = rdiag + arr[i][len(arr)-i-1]
    return abs(ldiag-rdiag)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
