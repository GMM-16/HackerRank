'''
Watson gives Sherlock an array of integers. His challenge is to find an element of the array such that the sum of all elements to the left is equal to the sum of all elements to the right.

Function Description
Complete the balancedSums function in the editor below.
balancedSums has the following parameter(s):
int arr[n]: an array of integers
Returns
- string: either YES or NO

Input Format
The first line contains T, the number of test cases.
The next T pairs of lines each represent a test case.
The first line contains n, the number of elements in the array arr.
The second line contains n space-separated integers arr[i] where 0 <= i < n.

Constraints
1 <= T <= 10
1 <= n <= 10^5
1 <= arr[i] <= 2*10^4
0 <= i < n
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'balancedSums' function below.
# The function is expected to return a STRING.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def balancedSums(arr):
    # Write your code here
    leftsum = 0
    totalsum = sum(arr)
    for i in range(len(arr)):
        rightsum = totalsum - leftsum - arr[i]
        if leftsum == rightsum:
            return "YES"
        else:
            leftsum = leftsum + arr[i]
    return "NO"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    T = int(input().strip())

    for T_itr in range(T):
        n = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        result = balancedSums(arr)

        fptr.write(result + '\n')

    fptr.close()
