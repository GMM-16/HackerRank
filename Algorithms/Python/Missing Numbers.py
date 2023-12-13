'''
Given two arrays of integers, find which elements in the second array are missing from the first array.

Notes
If a number occurs multiple times in the lists, you must ensure that the frequency of that number in both lists is the same. If that is not the case, then it is also a missing number.
Return the missing numbers sorted ascending.
Only include a missing number once, even if it is missing multiple times.
The difference between the maximum and minimum numbers in the original list is less than or equal to 100.

Function Description
Complete the missingNumbers function in the editor below. It should return a sorted array of missing numbers.
missingNumbers has the following parameter(s):
int arr[n]: the array with missing numbers
int brr[m]: the original array of numbers
Returns
- int[]: an array of integers

Input Format
There will be four lines of input:
n - the size of the first list, arr
The next line contains n space-separated integers arr[i]
m - the size of the second list, brr
The next line contains m space-separated integers brr[i]

Constraints
1 <= n,m <= 2*10^5
n <= m
1 <= brr[i] <= 10^4
max(brr) - min(brr) <= 100
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'missingNumbers' function below.
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY arr
#  2. INTEGER_ARRAY brr
#

def missingNumbers(arr, brr):
    # Write your code here
    ans = []
    temp = set(brr)
    for i in temp:
        a = arr.count(i)
        b = brr.count(i)
        if a < b:
            ans.append(i)
    return ans
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    m = int(input().strip())

    brr = list(map(int, input().rstrip().split()))

    result = missingNumbers(arr, brr)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
