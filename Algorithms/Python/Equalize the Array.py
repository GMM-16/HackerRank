'''
Given an array of integers, determine the minimum number of elements to delete to leave only elements of equal value.

Function Description
Complete the equalizeArray function in the editor below.
equalizeArray has the following parameter(s):
int arr[n]: an array of integers
Returns
- int: the minimum number of deletions required

Input Format
The first line contains an integer n, the number of elements in arr.
The next line contains n space-separated integers arr[i].

Constraints
1 <= n <= 100
1 <= arr[i] <= 100
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'equalizeArray' function below.
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def equalizeArray(arr):
    # Write your code here
    maximum = -1
    count = 0
    temp = [0] * 101
    
    for num in arr:
        temp[num] += 1
        count = max(count, temp[num])
    
    ans = len(arr) - count
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = equalizeArray(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
