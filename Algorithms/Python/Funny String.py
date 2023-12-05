'''
In this challenge, you will determine whether a string is funny or not. To determine whether a string is funny, create a copy of the string in reverse e.g. abc -> cba. Iterating through each string, compare the absolute difference in the ascii values of the characters at positions 0 and 1, 1 and 2 and so on to the end. If the list of absolute differences is the same for both strings, they are funny.
Determine whether a give string is funny. If it is, return Funny, otherwise return Not Funny.

Function Description
Complete the funnyString function in the editor below.
funnyString has the following parameter(s):
string s: a string to test
Returns
- string: either Funny or Not Funny

Input Format
The first line contains an integer q, the number of queries.
The next q lines each contain a string, s.

Constraints
1 <= q <= 10
2 <= length of s <= 10000
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'funnyString' function below.
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def funnyString(s):
    # Write your code here
    r = s[::-1]
    for i in range(1, len(s)):
        if abs(ord(s[i]) - ord(s[i-1])) != abs(ord(r[i]) - ord(r[i-1])):
            return "Not Funny"
    return "Funny"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = funnyString(s)

        fptr.write(result + '\n')

    fptr.close()
