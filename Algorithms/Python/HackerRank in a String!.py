'''
We say that a string contains the word hackerrank if a subsequence of its characters spell the word hackerrank. Remeber that a subsequence maintains the order of characters selected from a sequence.
More formally, let p[0],p[1]....,p[9] be the respective indices of h, a, c, k, e, r, r, a, n, k in string s if p[0] > p[1] < p[2] < ... < p[9] is true, then s contains hackerrank.
For each query, print YES on a new line if the string contains hackerrank, otherwise, print NO.

Function Description
Complete the hackerrankInString function in the editor below.
hackerrankInString has the following parameter(s):
string s: a string
Returns
- string: YES or NO

Input Format
The first line contains an integer q, the number of queries.
Each of the next q lines contains a single query string s.

Constraints
2 <= q <= 10^2
10 <= length of s <= 10^4
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'hackerrankInString' function below.
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def hackerrankInString(s):
    # Write your code here
    temp = "hackerrank"
    if len(s) >= len(temp):
        for i in s:
            if len(temp) == 0:
                break
            if i == temp[0]:
                temp = temp[1:]
    if len(temp) == 0:
        return "YES"
    else:
        return "NO"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = hackerrankInString(s)

        fptr.write(result + '\n')

    fptr.close()
