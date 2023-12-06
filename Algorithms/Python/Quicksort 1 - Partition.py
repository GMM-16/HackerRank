'''
The previous challenges covered Insertion Sort, which is a simple and intuitive sorting algorithm with a running time of O(n^2). In these next few challenges, we're covering a divide-and-conquer algorithm called Quicksort (also known as Partition Sort). This challenge is a modified version of the algorithm that only addresses partitioning. It is implemented as follows:
Step 1: Divide
Choose some pivot element, p, and partition your unsorted array, arr, into three smaller arrays: left, right, and equal, where each element in left < p, each element in right > p, and each element in equal = p.

Function Description
Complete the quickSort function in the editor below.
quickSort has the following parameter(s):
int arr[n]: arr[0] is the pivot element
Returns
- int[n]: an array of integers as described above

Input Format
The first line contains n, the size of aarr.
The second line contains n space-separated integers arr[i] (the unsorted array). The first integer, arr[0], is the pivot element, p.

Constraints
1 <= n <= 1000
-1000 <= arr[i] <= 1000 where 0 <= i < n
All elements are distinct.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'quickSort' function below.
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def quickSort(arr):
    # Write your code here
    left, right = [], []
    for i in range(1, len(arr)):
        if arr[0] > arr[i]:
            left.append(arr[i])
        else:
            right.append(arr[i])
    left.append(arr[0])
    return left + right

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = quickSort(arr)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
