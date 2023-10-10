'''
Little Bobby loves chocolate. He frequently goes to his favorite 5 & 10 store, Penny Auntie, to buy them. They are having a promotion at Penny Auntie. If Bobby saves enough wrappers, he can turn them in for a free chocolate.

Function Description
Complete the chocolateFeast function in the editor below.
chocolateFeast has the following parameter(s):
int n: Bobby's initial amount of money
int c: the cost of a chocolate bar
int m: the number of wrappers he can turn in for a free bar
Returns
- int: the number of chocolates Bobby can eat after taking full advantage of the promotion
Note: Little Bobby will always turn in his wrappers if he has enough to get a free chocolate.

Input Format

The first line contains an integer, , the number of test cases to analyze.
Each of the next t lines contains three space-separated integers: n, c, and m. They represent money to spend, cost of a chocolate, and the number of wrappers he can turn in for a free chocolate.

Constraints
1 <= t <= 1000
2 <= n <= 10^5
1 <= c <= n
2 <= m <= n
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'chocolateFeast' function below.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER c
#  3. INTEGER m
#

def chocolateFeast(n, c, m):
    # Write your code here
    choc = n // c
    wrap = choc
    ans = choc
    while wrap >= m:
        free = wrap // m
        wrap = wrap % m + free
        ans = ans + free
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        n = int(first_multiple_input[0])

        c = int(first_multiple_input[1])

        m = int(first_multiple_input[2])

        result = chocolateFeast(n, c, m)

        fptr.write(str(result) + '\n')

    fptr.close()
