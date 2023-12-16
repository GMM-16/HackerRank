'''
Given two integers, l and r, find the maximal value of a xor b, written a ⊕ b, where a and b satisfy the following condition:
l <= a <= b <= r

Function Description
Complete the maximizingXor function in the editor below. It must return an integer representing the maximum value calculated.
maximizingXor has the following parameter(s):
l: an integer, the lower bound, inclusive
r: an integer, the upper bound, inclusive

Input Format
The first line contains the integer l.
The second line contains the integer r.

Constraints
1 <= l <= r <= 10^3

Output Format
Return the maximal value of the xor operations for all permutations of the integers from l to r, inclusive.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'maximizingXor' function below.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER l
#  2. INTEGER r
#

def maximizingXor(l, r):
    # Write your code here
    ans = []
    for i in range(l, r+1):
        for j in range(l, r+1):
            ans.append(i ^ j)
    return max(ans)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    l = int(input().strip())

    r = int(input().strip())

    result = maximizingXor(l, r)

    fptr.write(str(result) + '\n')

    fptr.close()
