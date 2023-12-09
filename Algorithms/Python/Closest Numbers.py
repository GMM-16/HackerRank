'''
Sorting is useful as the first step in many different tasks. The most common task is to make finding things easier, but there are other uses as well. In this case, it will make it easier to determine which pair or pairs of elements have the smallest absolute difference between them.

Note
As shown in the example, pairs may overlap.
Given a list of unsorted integers, arr, find the pair of elements that have the smallest absolute difference between them. If there are multiple pairs, find them all.

Function Description
Complete the closestNumbers function in the editor below.
closestNumbers has the following parameter(s):
int arr[n]: an array of integers
Returns
- int[]: an array of integers as described

Input Format
The first line contains a single integer n, the length of arr.
The second line contains n space-separated integers, arr[i].

Constraints
2 <= n <= 200000
-10^7 <= arr[i] <= 10^7
All a[i] are unique in arr
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'closestNumbers' function below.
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def closestNumbers(arr):
    # Write your code here
    ans = []
    temp = []
    arr.sort()
    for i in range(len(arr) - 1):
        temp.append(arr[i+1]-arr[i])
    min_val = min(temp)
    for i in range(len(temp)):
        if temp[i] == min_val:
            ans.append(arr[i])
            ans.append(arr[i+1])
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = closestNumbers(arr)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
