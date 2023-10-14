'''
Given an array of strings of digits, try to find the occurrence of a given pattern of digits. In the grid and pattern arrays, each string represents a row in the grid.
The pattern begins at the second row and the third column of the grid and continues in the following two rows. The pattern is said to be present in the grid. The return value should be YES or NO, depending on whether the pattern is found. In this case, return YES.

Function Description
Complete the gridSearch function in the editor below. It should return YES if the pattern exists in the grid, or NO otherwise.
gridSearch has the following parameter(s):
- string G[R]: the grid to search
- string P[r]: the pattern to search for

Input Format
The first line contains an integer t, the number of test cases.
Each of the t test cases is represented as follows:
The first line contains two space-separated integers R and C, the number of rows in the search grid G and the length of each row string.
This is followed by R lines, each with a string of C digits that represent the grid G.
The following line contains two space-separated integers, r and c, the number of rows in the pattern grid P and the length of each pattern row string.
This is followed by r lines, each with a string of c digits that represent the pattern grid P.
Returns
- string: either YES or NO

Constraints
1 <= t <= 5
1 <= R,r,C,c <= 1000
1 <= r <= R
1 <= c <= C
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'gridSearch' function below.
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING_ARRAY G
#  2. STRING_ARRAY P
#

def gridSearch(G, P):
    # Write your code here
    rows_G = len(G)
    cols_G = len(G[0])
    rows_P = len(P)
    cols_P = len(P[0])

    for i in range(rows_G - rows_P + 1):
        for j in range(cols_G - cols_P + 1):
            match = True
            for x in range(rows_P):
                for y in range(cols_P):
                    if G[i + x][j + y] != P[x][y]:
                        match = False
                        break
                if not match:
                    break
            if match:
                return "YES"
    return "NO"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        R = int(first_multiple_input[0])

        C = int(first_multiple_input[1])

        G = []

        for _ in range(R):
            G_item = input()
            G.append(G_item)

        second_multiple_input = input().rstrip().split()

        r = int(second_multiple_input[0])

        c = int(second_multiple_input[1])

        P = []

        for _ in range(r):
            P_item = input()
            P.append(P_item)

        result = gridSearch(G, P)

        fptr.write(result + '\n')

    fptr.close()
