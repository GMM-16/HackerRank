'''
An English text needs to be encrypted using the following encryption scheme.
First, the spaces are removed from the text. Let L be the length of this text.
Then, characters are written into a grid, whose rows and columns have the following constraints:
[√L] <= row <= column <= [√L], where [x] is floor function and [x] is ceil function

Function Description
Complete the encryption function in the editor below.
encryption has the following parameter(s):
string s: a string to encrypt
Returns
- string: the encrypted string

Input Format
One line of text, the string s

Constraints
1 <= length of s <= 81
s contains characters in the range ascii[a-z] and space, ascii(32)
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'encryption' function below.
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def encryption(s):
    # Write your code here
    size = len(s)
    n = math.ceil(math.sqrt(size))
    ans = ''
    for i in range(n):
        ans = ans + ' '
        while i < size:
            ans = ans + s[i]
            i = i + n
    ans = ans.lstrip()
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = encryption(s)

    fptr.write(result + '\n')

    fptr.close()
