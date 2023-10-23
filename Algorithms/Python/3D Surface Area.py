'''
Madison is a little girl who is fond of toys. Her friend Mason works in a toy manufacturing factory . Mason has a 2D board A of size H * W with H rows and W columns. The board is divided into cells of size 1*1 with each cell indicated by its coordinate (i,j). The cell (i,j) has an integer Aij written on it. To create the toy Mason stacks Aij number of cubes of size 1*1*1 on the cell (i,j)
Given the description of the board showing the values of Aij and that the price of the toy is equal to the 3d surface area find the price of the toy.

Input Format
The first line contains two space-separated integers H and W the height and the width of the board respectively.
The next H lines contains W space separated integers. The jth integer in ith line denotes Aij.

Constraints
1 <= H,W <= 100
1 <= Aij <= 100

Output Format
Print the required answer, i.e the price of the toy, in one line.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'surfaceArea' function below.
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY A as parameter.
#

def surfaceArea(A):
    # Write your code here
    x = len(A)
    y = len(A[0])
    ans = 2 * x * y
    for i in range(x):
        for j in range(y):
            if i > 0:
                ans = ans + abs(A[i][j] - A[i-1][j])
            else:
                ans = ans + A[i][j]
            if j > 0:
                ans = ans + abs(A[i][j] - A[i][j-1])
            else:
                ans = ans + A[i][j]
            if i == x-1:
                ans = ans + A[i][j]
            if j == y-1:
                ans = ans + A[i][j]
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    H = int(first_multiple_input[0])

    W = int(first_multiple_input[1])

    A = []

    for _ in range(H):
        A.append(list(map(int, input().rstrip().split())))

    result = surfaceArea(A)

    fptr.write(str(result) + '\n')

    fptr.close()
