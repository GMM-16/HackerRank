'''
Lily likes to play games with integers. She has created a new game where she determines the difference between a number and its reverse.
She decides to apply her game to decision making. She will look at a numbered range of days and will only go to a movie on a beautiful day.
Given a range of numbered days, [i.....j] and a number k, determine the number of days in the range that are beautiful. Beautiful numbers are defined as numbers where |i - reverse(i)| is evenly divisible by k. If a day's value is a beautiful number, it is a beautiful day. Return the number of beautiful days in the range.

Function Description
Complete the beautifulDays function in the editor below.
beautifulDays has the following parameter(s):
int i: the starting day number
int j: the ending day number
int k: the divisor
Returns
- int: the number of beautiful days in the range

Input Format
A single line of three space-separated integers describing the respective values of i, j, and k.

Constraints
1 <= i <= j <= 2*10^6
1 <= k <= 2*10^9
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'beautifulDays' function below.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER i
#  2. INTEGER j
#  3. INTEGER k
#

def beautifulDays(i, j, k):
    # Write your code here
    count = 0
    for temp in range(i,j+1):
        rev = str(temp)
        rev = int(rev[::-1])
        if (temp - rev)%k == 0:
            count = count + 1
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    i = int(first_multiple_input[0])

    j = int(first_multiple_input[1])

    k = int(first_multiple_input[2])

    result = beautifulDays(i, j, k)

    fptr.write(str(result) + '\n')

    fptr.close()
