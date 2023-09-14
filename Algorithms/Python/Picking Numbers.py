'''
Given an array of integers, find the longest subarray where the absolute difference between any two elements is less than or equal to 1.

Function Description
Complete the pickingNumbers function in the editor below.
pickingNumbers has the following parameter(s):
int a[n]: an array of integers
Returns
- int: the length of the longest subarray that meets the criterion

Input Format
The first line contains a single integer n, the size of the array .
The second line contains n space-separated integers, each an a[i].

Constraints
2 <= n <= 100
0 < a[i] < 100
The answer will always be >= 2.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'pickingNumbers' function below.
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY a as parameter.
#

def pickingNumbers(a):
    # Write your code here
    ans = 0
    for i in a:
        count = 0
        for j in a:
            if i==j or i==j+1:
                count = count + 1
        ans = max(ans,count)
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = pickingNumbers(a)

    fptr.write(str(result) + '\n')

    fptr.close()
