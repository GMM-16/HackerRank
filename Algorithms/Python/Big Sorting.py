'''
Consider an array of numeric strings where each string is a positive number with anywhere from 1 to 10^6 digits. Sort the array's elements in non-decreasing, or ascending order of their integer values and return the sorted array.

Function Description
Complete the bigSorting function in the editor below.
bigSorting has the following parameter(s):
string unsorted[n]: an unsorted array of integers as strings
Returns
- string[n]: the array sorted in numerical order

Input Format
The first line contains an integer, n, the number of strings in unsorted.
Each of the n subsequent lines contains an integer string, unsorted[i].

Constraints
1 <= n <= 2*10^5
Each string is guaranteed to represent a positive integer.
There will be no leading zeros.
The total number of digits across all strings in unsorted is between 1 and 10^6 (inclusive).
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'bigSorting' function below.
# The function is expected to return a STRING_ARRAY.
# The function accepts STRING_ARRAY unsorted as parameter.
#

def bigSorting(unsorted):
    # Write your code here
    ans = sorted(unsorted, key=lambda x: (len(x), x))
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    unsorted = []

    for _ in range(n):
        unsorted_item = input()
        unsorted.append(unsorted_item)

    result = bigSorting(unsorted)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
