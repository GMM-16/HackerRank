'''
There is a strange counter. At the first second, it displays the number 3. Each second, the number displayed by decrements by 1 until it reaches 1. In next second, the timer resets to 2 * the initial number for the prior cycle and continues counting down.
Find and print the value displayed by the counter at time t.

Function Description
Complete the strangeCounter function in the editor below.
strangeCounter has the following parameter(s):
int t: an integer
Returns
- int: the value displayed at time t

Input Format
A single integer, the value of t.

Constraints
1 <= t <= 10^12
Subtask
1 <= t <= 10^5 for 60% of the maximum score
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'strangeCounter' function below.
# The function is expected to return a LONG_INTEGER.
# The function accepts LONG_INTEGER t as parameter.
#

def strangeCounter(t):
    # Write your code here
    ans = 4
    while t >= ans:
        ans = (ans * 2) + 2
    ans = ans - t
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    result = strangeCounter(t)

    fptr.write(str(result) + '\n')

    fptr.close()
