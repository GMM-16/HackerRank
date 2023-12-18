'''
You are given a string containing characters A and B only. Your task is to change it into a string such that there are no matching adjacent characters. To do this, you are allowed to delete zero or more characters in the string.
Your task is to find the minimum number of required deletions.

Function Description
Complete the alternatingCharacters function in the editor below.
alternatingCharacters has the following parameter(s):
string s: a string
Returns
- int: the minimum number of deletions required

Input Format
The first line contains an integer q, the number of queries.
The next q lines each contain a string s to analyze.

Constraints
1 <= q <= 10
1 <= length of s <= 10^5
Each string s will consist only of characters A and B.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'alternatingCharacters' function below.
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def alternatingCharacters(s):
    # Write your code here
    ans = 0
    for i in range(len(s)-1):
        if s[i] == s[i+1]:
            ans = ans + 1
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        s = input()

        result = alternatingCharacters(s)

        fptr.write(str(result) + '\n')

    fptr.close()
