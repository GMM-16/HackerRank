'''
The factorial of the integer n, written n! is defined as:
n! = n * (n-1) * (n-2) * ..... * 3 * 2 * 1
Calculate and print the factorial of a given integer.

Function Description
Complete the extraLongFactorials function in the editor below. It should print the result and return.
extraLongFactorials has the following parameter(s):
- n: an integer
Note: Factorials of n>20 can't be stored even in a 64-bit long long variable. Big integers must be used for such calculations. Languages like Java, Python, Ruby etc. can handle big integers, but we need to write additional code in C/C++ to handle huge values.
We recommend solving this challenge using BigIntegers.

Input Format
Input consists of a single integer n

Constraints
1 <= n <= 100

Output Format
Print the factorial of n.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'extraLongFactorials' function below.
# The function accepts INTEGER n as parameter.
#

def extraLongFactorials(n):
    # Write your code here
    ans = 1
    for i in range(1, n+1):
        ans = ans * i
    print(ans)

if __name__ == '__main__':
    n = int(input().strip())

    extraLongFactorials(n)
