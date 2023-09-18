'''
You are given a number of sticks of varying lengths. You will iteratively cut the sticks into smaller sticks, discarding the shortest pieces until there are none left. At each iteration you will determine the length of the shortest stick remaining, cut that length from each of the longer sticks and then discard all the pieces of that shortest length. When all the remaining sticks are the same length, they cannot be shortened so discard them.
Given the lengths of n sticks, print the number of sticks that are left before each iteration until there are none left.

Function Description
Complete the cutTheSticks function in the editor below. It should return an array of integers representing the number of sticks before each cut operation is performed.
cutTheSticks has the following parameter(s):
int arr[n]: the lengths of each stick
Returns
- int[]: the number of sticks after each iteration

Input Format
The first line contains a single integer n, the size of arr.
The next line contains n space-separated integers, each an arr[i], where each value represents the length of the i'th stick.

COnstraints
1 <= n <= 1000
1 <= arr[i] <= 1000
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'cutTheSticks' function below.
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def cutTheSticks(arr):
    # Write your code here
    ans = []
    size = len(arr)
    arr.sort()
    i = 0
    while i < size:
        ans.append(size - i)
        cut = arr[i]
        while i < size and arr[i] == cut:
            i += 1
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = cutTheSticks(arr)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
