'''
Given the time in numerals we may convert it into words.
At minutes = 0, use o' clock. For 1 <= minutes <= 30, use past and for 30 < minutes use to. Note the space between the apostrophe and clock in o' clock. Write a program which prints the time in words for the input given in the format described.

Function Description
Complete the timeInWords function in the editor below.
timeInWords has the following parameter(s):
int h: the hour of the day
int m: the minutes after the hour
Returns
- string: a time string as described

Input Format
The first line contains h, the hours portion The second line contains m, the minutes portion

Constraints
1 <= h <= 12
0 <= m < 60
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeInWords' function below.
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. INTEGER h
#  2. INTEGER m
#

def timeInWords(h, m):
    # Write your code here
    words = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine"]
    if m == 0:
        return f"{words[h]} o' clock"
    elif m == 1:
        return f"one minute past {words[h]}"
    elif m == 59:
        return f"one minute to {words[(h % 12) + 1]}"
    elif m == 15:
        return f"quarter past {words[h]}"
    elif m == 45:
        return f"quarter to {words[(h % 12) + 1]}"
    elif m == 30:
        return f"half past {words[h]}"
    elif m <= 30:
        return f"{words[m]} minutes past {words[h]}"
    else:
        return f"{words[60 - m]} minutes to {words[(h % 12) + 1]}"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    h = int(input().strip())

    m = int(input().strip())

    result = timeInWords(h, m)

    fptr.write(result + '\n')

    fptr.close()
