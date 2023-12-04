'''
Given a string, remove characters until the string is made up of any two alternating characters. When you choose a character to remove, all instances of that character must be removed. Determine the longest string possible that contains just two alternating letters.

Function Description
Complete the alternate function in the editor below.
alternate has the following parameter(s):
string s: a string
Returns.
- int: the length of the longest valid string, or  if there are none

Input Format
The first line contains a single integer that denotes the length of s.
The second line contains string s.

Constraints
1 <= length of s <= 1000
s[i] ∈ ascii[a-z]
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'alternate' function below.
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def alternate(s):
    # Write your code here
    count = 0
    for i in range(26):
        for j in range(i+1, 26):
            a = chr(97+i)
            b = chr(97+j)
            last_char = ""
            str_count = 0
            flag = True
            for char in s:
                if char == a or char == b:
                    if not last_char or char != last_char:
                        last_char = char
                        str_count += 1
                    else:
                        flag = False
                        break
            if flag and str_count>1:
                count = max(count, str_count)
    return count
                

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    l = int(input().strip())

    s = input()

    result = alternate(s)

    fptr.write(str(result) + '\n')

    fptr.close()
