'''
Given an array of integers, find the sum of its elements.

Function Description

Complete the simpleArraySum function in the editor below. It must return the sum of the array elements as an integer.
simpleArraySum has the following parameter(s):
ar: an array of integers

Input Format
The first line contains an integer, n, denoting the size of the array.
The second line contains n space-separated integers representing the array's elements.

Constraints
0 < n, ar[i] <= 1000

Output Format
Print the sum of the array's elements as a single integer.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'simpleArraySum' function below.
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY ar as parameter.
#

def simpleArraySum(ar):
    # Write your code here
    ans = 0
    for i in ar:
        ans = ans + i
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ar_count = int(input().strip())

    ar = list(map(int, input().rstrip().split()))

    result = simpleArraySum(ar)

    fptr.write(str(result) + '\n')

    fptr.close()
