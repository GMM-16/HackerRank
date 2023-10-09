'''
The distance between two array values is the number of indices between them. Given a, find the minimum distance between any pair of equal elements in the array. If no such value exists, return -1.

Function Description
Complete the minimumDistances function in the editor below.
minimumDistances has the following parameter(s):
int a[n]: an array of integers
Returns
- int: the minimum distance found or -1 if there are no matching elements

Input Format
The first line contains an integer n, the size of array a.
The second line contains n space-separated integers a[i].

Constraints
1 <= n <= 10^3
1 <= a[i] <= 10^5

Output Format
Print a single integer denoting the minimum d[i,j] in a. If no such value exists, print -1.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumDistances' function below.
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY a as parameter.
#

def minimumDistances(a):
    # Write your code here
    ans = float('inf')
    for i in range(len(a)):
        for j in range(i + 1, len(a)):
            if a[i] == a[j]:
                temp = abs(i - j)
                if temp < ans:
                    ans = temp
    if ans == float('inf'):
        return -1
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = minimumDistances(a)

    fptr.write(str(result) + '\n')

    fptr.close()
