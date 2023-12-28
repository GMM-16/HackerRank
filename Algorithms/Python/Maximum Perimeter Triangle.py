'''
Given an array of stick lengths, use 3 of them to construct a non-degenerate triangle with the maximum possible perimeter. Return an array of the lengths of its sides as 3 integers in non-decreasing order.
If there are several valid triangles having the maximum perimeter:
Choose the one with the longest maximum side.
If more than one has that maximum, choose from them the one with the longest minimum side.
If more than one has that maximum as well, print any one them.
If no non-degenerate triangle exists, return [-1].

Function Description
Complete the maximumPerimeterTriangle function in the editor below.
maximumPerimeterTriangle has the following parameter(s):
int sticks[n]: the lengths of sticks available
Returns
- int[3] or int[1]: the side lengths of the chosen triangle in non-decreasing order or -1

Input Format
The first line contains single integer n, the size of array sticks.
The second line contains n space-separated integers sticks[i], each a stick length.

Constraints
3 <= n <= 50
1 <= sticks[i] <= 10^9
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'maximumPerimeterTriangle' function below.
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY sticks as parameter.
#

def maximumPerimeterTriangle(sticks):
    # Write your code here
    sticks.sort(reverse=True)
    size = len(sticks)
    for i in range(size-2):
        if sticks[i+1] + sticks[i+2] > sticks[i]:
            print(sticks[i+2], sticks[i+1], sticks[i])
            return [sticks[i+2], sticks[i+1], sticks[i]]
    return [-1]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    sticks = list(map(int, input().rstrip().split()))

    result = maximumPerimeterTriangle(sticks)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
