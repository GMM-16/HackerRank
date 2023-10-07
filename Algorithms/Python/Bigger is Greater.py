'''
Lexicographical order is often known as alphabetical order when dealing with strings. A string is greater than another string if it comes later in a lexicographically sorted list.
Given a word, create a new word by swapping some or all of its characters. This new word must meet two criteria:
It must be greater than the original word
It must be the smallest word that meets the first condition

Function Description
Complete the biggerIsGreater function in the editor below.
biggerIsGreater has the following parameter(s):
string w: a word
Returns
- string: the smallest lexicographically higher string possible or no answer

Input Format
The first line of input contains T, the number of test cases.
Each of the next T lines contains w.

Constraints
1 <= T <= 10^5
1 <= lengthofw <= 100
w will contain only letters in the range ascii[a...z]
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'biggerIsGreater' function below.
# The function is expected to return a STRING.
# The function accepts STRING w as parameter.
#

def biggerIsGreater(w):
    # Write your code here
    w = list(w)
    i = len(w)-2
    while i>=0 and w[i]>=w[i+1]:
        i = i - 1
    if i == -1:
        return "no answer"
    j = len(w)-1
    while w[j]<=w[i]:
        j = j - 1
    w[i], w[j] = w[j], w[i]
    w[i+1:] = reversed(w[i+1:])
    ans = ''.join(w)
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    T = int(input().strip())

    for T_itr in range(T):
        w = input()

        result = biggerIsGreater(w)

        fptr.write(result + '\n')

    fptr.close()
