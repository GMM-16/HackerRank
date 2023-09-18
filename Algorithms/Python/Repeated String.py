'''
There is a string, s, of lowercase English letters that is repeated infinitely many times. Given an integer, n, find and print the number of letter a's in the first n letters of the infinite string.

Function Description
Complete the repeatedString function in the editor below.
repeatedString has the following parameter(s):
s: a string to repeat
n: the number of characters to consider
Returns
- int: the frequency of a in the substring

Input Format
The first line contains a single string, s.
The second line contains an integer, n.

Constraints
1 <= |s| <= 100
1 <= n <= 10^12
For 25% of test cases, n <= 10^6
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'repeatedString' function below.
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. STRING s
#  2. LONG_INTEGER n
#

def repeatedString(s, n):
    # Write your code here
    count = s.count('a')
    repeats = n // len(s)
    remainder = n % len(s)
    total_count = count * repeats
    total_count += s[:remainder].count('a')
    return total_count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    n = int(input().strip())

    result = repeatedString(s, n)

    fptr.write(str(result) + '\n')

    fptr.close()
