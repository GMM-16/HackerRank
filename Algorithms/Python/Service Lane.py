'''
A driver is driving on the freeway. The check engine light of his vehicle is on, and the driver wants to get service immediately. Luckily, a service lane runs parallel to the highway. It varies in width along its length.
You will be given an array of widths at points along the road (indices), then a list of the indices of entry and exit points. Considering each entry and exit point pair, calculate the maximum size vehicle that can travel that segment of the service lane safely.

Function Description
Complete the serviceLane function in the editor below.
serviceLane has the following parameter(s):
int n: the size of the width array
int cases[t][2]: each element contains the starting and ending indices for a segment to consider, inclusive
Returns
- int[t]: the maximum width vehicle that can pass through each segment of the service lane described

Input Format
The first line of input contains two integers, n and t, where n denotes the number of width measurements and t, the number of test cases. The next line has n space-separated integers which represent the array width.
The next t lines contain two integers, i and j, where i is the start index and j is the end index of the segment to check.

Constraints
2 <= n <= 100000
1 <= t <= 1000
0 <= i < j < n
2 <= j - i + 1 <= min(n,1000)
1 <= width(k) <= 3, where 0 <= k < n
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'serviceLane' function below.
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER n
#  2. 2D_INTEGER_ARRAY cases
#

def serviceLane(n, cases):
    # Write your code here
    results = []
    for i in cases:
        results.append(min(width[i[0]:i[1]+1]))
    return results

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    t = int(first_multiple_input[1])

    width = list(map(int, input().rstrip().split()))

    cases = []

    for _ in range(t):
        cases.append(list(map(int, input().rstrip().split())))

    result = serviceLane(n, cases)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
