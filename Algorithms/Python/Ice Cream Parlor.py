'''
Two friends like to pool their money and go to the ice cream parlor. They always choose two distinct flavors and they spend all of their money.
Given a list of prices for the flavors of ice cream, select the two that will cost all of the money they have.

Function Description
Complete the icecreamParlor function in the editor below.
icecreamParlor has the following parameter(s):
int m: the amount of money they have to spend
int cost[n]: the cost of each flavor of ice cream
Returns
- int[2]: the indices of the prices of the two flavors they buy, sorted ascending

Input Format
The first line contains an integer, t, the number of trips to the ice cream parlor. The next t sets of lines each describe a visit.
Each trip is described as follows:
The integer m, the amount of money they have pooled.
The integer n, the number of flavors offered at the time.
n space-separated integers denoting the cost of each flavor: cost[cost[1],cost[2],.....,cost[n]].
Note: The index within the cost array represents the flavor of the ice cream purchased.

Constraints
1 <= t <= 50
2 <= m <= 10^4
2 <= n <= 10^4
1 <= cost[i] <= 10^4 , ∀ i ∈ [1,n]
There will always be a unique solution.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'icecreamParlor' function below.
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER m
#  2. INTEGER_ARRAY arr
#

def icecreamParlor(m, arr):
    # Write your code here
    ans = []
    n = len(arr)
    for i in range(n-1):
        for j in range(i+1, n):
            if arr[i] + arr[j] == m:
                ans.append(i+1)
                ans.append(j+1)
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        m = int(input().strip())

        n = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        result = icecreamParlor(m, arr)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()
