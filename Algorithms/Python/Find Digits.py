'''
An integer d is a divisor of an integer n if the remainder of n / d = 0.
Given an integer, for each digit that makes up the integer determine whether it is a divisor. Count the number of divisors occurring within the integer.

Function Description
Complete the findDigits function in the editor below.
findDigits has the following parameter(s):
int n: the value to analyze
Returns
- int: the number of digits in n that are divisors of n.

Input Format
The first line is an integer, t, the number of test cases.
The t subsequent lines each contain an integer, n.

Constraints
1 <= t <= 15
0 < n <10^9
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'findDigits' function below.
# The function is expected to return an INTEGER.
# The function accepts INTEGER n as parameter.
#

def findDigits(n):
    # Write your code here
    n_str = str(n)
    count = 0
    for digit_str in n_str:
        digit = int(digit_str)
        if digit != 0 and n % digit == 0:
            count += 1
    return count


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        result = findDigits(n)

        fptr.write(str(result) + '\n')

    fptr.close()
