'''
We define a magic square to be an n * n matrix of distinct positive integers from 1 to n^2 where the sum of any row, column, or diagonal of length n is always equal to the same number: the magic constant.
You will be given a 3 * 3 matrix s integers in the inclusive range [1,9]. We can convert any digit  to any other digit b in the range [1,9] at a cost of |a - b|. Given s, convert it into a magic square at minimal cost. Print this cost on a new line.
Note: The resulting magic square must contain distinct integers in the inclusive range [1,9].

Function Description
Complete the formingMagicSquare function in the editor below.
formingMagicSquare has the following parameter(s):
int s[3][3]: a 3 * 3 array of integers
Returns
- int: the minimal total cost of converting the input square to a magic square

Input Format
Each of the 3 lines contains three space-separated integers of row s[i].

Constraints
s[i][j] ∈ |1,9|
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'formingMagicSquare' function below.
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY s as parameter.
#

def formingMagicSquare(s):
    # Write your code here
    magic_squares = [
        [[2, 9, 4], [7, 5, 3], [6, 1, 8]],
        [[4, 9, 2], [3, 5, 7], [8, 1, 6]],
        [[2, 7, 6], [9, 5, 1], [4, 3, 8]],
        [[6, 1, 8], [7, 5, 3], [2, 9, 4]],
        [[8, 1, 6], [3, 5, 7], [4, 9, 2]],
        [[6, 7, 2], [1, 5, 9], [8, 3, 4]],
        [[8, 3, 4], [1, 5, 9], [6, 7, 2]],
        [[4, 3, 8], [9, 5, 1], [2, 7, 6]],
    ]
    min_cost = float('inf')
    for magic_square in magic_squares:
        cost = 0
        for i in range(3):
            for j in range(3):
                cost = cost + abs(s[i][j] - magic_square[i][j])
        min_cost = min(min_cost, cost)
    return min_cost

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = []

    for _ in range(3):
        s.append(list(map(int, input().rstrip().split())))

    result = formingMagicSquare(s)

    fptr.write(str(result) + '\n')

    fptr.close()
