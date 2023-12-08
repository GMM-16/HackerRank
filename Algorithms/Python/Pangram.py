'''
A pangram is a string that contains every letter of the alphabet. Given a sentence determine whether it is a pangram in the English alphabet. Ignore case. Return either pangram or not pangram as appropriate.

Function Description
Complete the function pangrams in the editor below. It should return the string pangram if the input string is a pangram. Otherwise, it should return not pangram.
pangrams has the following parameter(s):
string s: a string to test
Returns
- string: either pangram or not pangram

Input Format
A single line with string s.

Constraints
0 < length of s <= 10^3
Each character of s, s[i] ∈ {a-z,A-Z,space}
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'pangrams' function below.
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def pangrams(s):
    # Write your code here
    ans = "pangram"
    temp = [0]*26
    for char in s:
        if char != ' ':
            temp[ord(char.lower()) - ord('a')] += 1
    for count in temp:
        if count == 0:
            ans = "not pangram"
            break
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = pangrams(s)

    fptr.write(result + '\n')

    fptr.close()
