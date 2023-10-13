'''
You are given a square map as a matrix of integer strings. Each cell of the map has a value denoting its depth. We will call a cell of the map a cavity if and only if this cell is not on the border of the map and each cell adjacent to it has strictly smaller depth. Two cells are adjacent if they have a common side, or edge.
Find all the cavities on the map and replace their depths with the uppercase character X.

Function Description
Complete the cavityMap function in the editor below.
cavityMap has the following parameter(s):
string grid[n]: each string represents a row of the grid
Returns
- string{n}: the modified grid

Input Format
The first line contains an integer n, the number of rows and columns in the grid.
Each of the following n lines (rows) contains n positive digits without spaces (columns) that represent the depth at grid[row,column].

Constraints
1 <= n <= 100
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'cavityMap' function below.
# The function is expected to return a STRING_ARRAY.
# The function accepts STRING_ARRAY grid as parameter.
#

def cavityMap(grid):
    # Write your code here
    for i in range(1, len(grid) - 1):
        for j in range(1, len(grid[i]) - 1):
            if grid[i][j] > grid[i - 1][j] and grid[i][j] > grid[i + 1][j] and grid[i][j] > grid[i][j - 1] and grid[i][j] > grid[i][j + 1]:
                grid[i] = grid[i][:j] + 'X' + grid[i][j + 1:]
    return grid

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    grid = []

    for _ in range(n):
        grid_item = input()
        grid.append(grid_item)

    result = cavityMap(grid)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
