'''
Reduce a string of lowercase characters in range ascii[‘a’..’z’]by doing a series of operations. In each operation, select a pair of adjacent letters that match, and delete them.
Delete as many characters as possible using this method and return the resulting string. If the final string is empty, return Empty String

Function Description
Complete the superReducedString function in the editor below.
superReducedString has the following parameter(s):
string s: a string to reduce
Returns
- string: the reduced string or Empty String

Input Format
A single string, s.

Constraints
1 <= length of s <= 100
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'superReducedString' function below.
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def superReducedString(s):
    # Write your code here
    for char in s:
        if char * 2 in s:
            s = s.replace(char*2, '')
    if s:
        return s
    else:
        return 'Empty String'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = superReducedString(s)

    fptr.write(result + '\n')

    fptr.close()
