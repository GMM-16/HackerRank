'''
A space explorer's ship crashed on Mars! They send a series of SOS messages to Earth for help.
Letters in some of the SOS messages are altered by cosmic radiation during transmission. Given the signal received by Earth as a string, s, determine how many letters of the SOS message have been changed by radiation.

Function Description
Complete the marsExploration function in the editor below.
marsExploration has the following parameter(s):
string s: the string as received on Earth
Returns
- int: the number of letters changed during transmission

Input Format
There is one line of input: a single string, s.

Constraints
1 <= length of s <= 99
length of s modulo 3 = 0
s will contain only uppercase English letters, ascii[A-Z].
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'marsExploration' function below.
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

def marsExploration(s):
    # Write your code here
    ans = 0
    for i in range(len(s)):
        if (i % 3 == 0) or (i % 3 == 2):
            if (s[i] != 'S'):
                ans = ans + 1
        if (i % 3 == 1):
            if (s[i] != 'O'):
                ans = ans + 1
    return ans
                

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = marsExploration(s)

    fptr.write(str(result) + '\n')

    fptr.close()
