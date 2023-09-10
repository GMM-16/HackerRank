'''
Given an array of integers, calculate the ratios of its elements that are positive, negative, and zero. Print the decimal value of each fraction on a new line with 6 places after the decimal.
Note: This challenge introduces precision problems. The test cases are scaled to six decimal places, though answers with absolute error of up to 10^-4 are acceptable.

Function Description
Complete the plusMinus function in the editor below.
plusMinus has the following parameter(s):
int arr[n]: an array of integers
Print
- Print the ratios of positive, negative and zero values in the array. Each value should be printed on a separate line with 6 digits after the decimal. The function should not return a value.

Input Format
The first line contains an integer, n, the size of the array.
The second line contains n space-separated integers that describe .

Constraints
0 < n <= 100
-100 <= arr[i] <= 100

Output Format
Print the following  lines, each to 6 decimals:
proportion of positive values
proportion of negative values
proportion of zeros
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    # Write your code here
    pos = neg = zero = 0
    for i in arr:
        if i>0:
            pos = pos + 1
        if i<0:
            neg = neg + 1
        if i==0:
            zero = zero + 1
    total = len(arr)
    pos = pos/total
    neg = neg/total
    zero = zero/total
    print(pos,"\n",neg,"\n",zero)

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
