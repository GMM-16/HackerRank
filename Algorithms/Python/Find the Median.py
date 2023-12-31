'''
The median of a list of numbers is essentially its middle element after sorting. The same number of elements occur after it as before. Given a list of numbers with an odd number of elements, find the median?

Function Description
Complete the findMedian function in the editor below.
findMedian has the following parameter(s):
int arr[n]: an unsorted array of integers
Returns
- int: the median of the array

Input Format
The first line contains the integer n, the size of arr.
The second line contains n space-separated integers arr[i]

Constraints
1 <= n <= 1000001
n is odd
-10000 <= arr[i] <= 10000
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'findMedian' function below.
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def findMedian(arr):
    # Write your code here
    arr.sort()
    ans = len(arr)//2
    return arr[ans]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = findMedian(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
