'''
Given an integer n, find each x such that:
0 <= x <= n
n + x = n ⊕ x
where ⊕ denotes the bitwise XOR operator. Return the number of x's satisfying the criteria.

Function Description
Complete the sumXor function in the editor below.
sumXor has the following parameter(s):
- int n: an integer
Returns
- int: the number of values found

Input Format
A single integer, n.

Constraints
0 <= n <= 10^15

Subtasks
0 <= n <= 100 for 60% of the maximum score.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'sumXor' function below.
# The function is expected to return a LONG_INTEGER.
# The function accepts LONG_INTEGER n as parameter.
#

def sumXor(n):
    # Write your code here
    ans = 0
    while n > 0:
        if n % 2 == 0:
            ans = ans + 1
        n = math.floor(n/2)
    return 2**ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    result = sumXor(n)

    fptr.write(str(result) + '\n')

    fptr.close()
