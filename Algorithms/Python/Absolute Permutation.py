'''
We define P to be a permutation of the first n natural numbers in the range [1,n]. Let pos[i] denote the value at position i in permutation P using 1-based indexing.
P is considered to be an absolute permutation if |pos[i] - i| = k holds true for every 1 ∈ [1,n].
Given n and k, print the lexicographically smallest absolute permutation P. If no absolute permutation exists, print -1.

Function Description

Complete the absolutePermutation function in the editor below.

absolutePermutation has the following parameter(s):
int n: the upper bound of natural numbers to consider, inclusive
int k: the absolute difference between each element's value and its index
Returns
- int[n]: the lexicographically smallest permutation, or [-1] if there is none

Input Format
The first line contains an integer t, the number of queries.
Each of the next t lines contains 2 space-separated integers, n and k.

Constraints
1 <= t <= 10
1 <= n <= 10^5
0 <= k < n
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'absolutePermutation' function below.
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER k
#

def absolutePermutation(n, k):
    # Write your code here
    ans = [0] * n
    used = [False] * (n + 1)
    
    for i in range(1, n + 1):
        if i - k > 0 and not used[i - k]:
            ans[i - 1] = i - k
            used[i - k] = True
        elif i + k <= n and not used[i + k]:
            ans[i - 1] = i + k
            used[i + k] = True
        else:
            return [-1]
    return ans
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        n = int(first_multiple_input[0])

        k = int(first_multiple_input[1])

        ans = absolutePermutation(n, k)

        fptr.write(' '.join(map(str, ans)))
        fptr.write('\n')

    fptr.close()
