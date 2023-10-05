'''
Given a set of distinct integers, print the size of a maximal subset of S where the sum of any 2 numbers in S' is not evenly divisible by k.

Function Description
Complete the nonDivisibleSubset function in the editor below.
nonDivisibleSubset has the following parameter(s):
int S[n]: an array of integers
int k: the divisor
Returns
- int: the length of the longest subset of S meeting the criteria

Input Format
The first line contains 2 space-separated integers, n and k, the number of values in S and the non factor.
The second line contains n space-separated integers, each an S[i], the unique values of the set.

Constraints
1 <= n <= 10^5
1 <= k <= 100
1 <= S[i] <= 10^9
All of the given numbers are distinct.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'nonDivisibleSubset' function below.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. INTEGER_ARRAY s
#

def nonDivisibleSubset(k, s):
    # Write your code here
    rem_count = [0] * k
    for num in s:
        rem_count[num % k] += 1
    result = 0
    if rem_count[0] > 0:
        result += 1
    for i in range(1, k // 2 + 1):
        if i != k - i:
            result += max(rem_count[i], rem_count[k - i])
        else:
            result += 1
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    s = list(map(int, input().rstrip().split()))

    result = nonDivisibleSubset(k, s)

    fptr.write(str(result) + '\n')

    fptr.close()
