'''
Staircase detail
This is a staircase of size n=4
        #
      # #
    # # #
  # # # #
Its base and height are both equal to . It is drawn using # symbols and spaces. The last line is not preceded by any spaces.
Write a program that prints a staircase of size .

Function Description
Complete the staircase function in the editor below.
staircase has the following parameter(s):
int n: an integer
Print
- Print a staircase as described above.

Input Format
A single integer, n, denoting the size of the staircase.

Constraints
0 <= n <= 100
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'staircase' function below.
#
# The function accepts INTEGER n as parameter.
#

def staircase(n):
    # Write your code here
    for i in range(1,n+1):
        print(" "*int(n-i),end="")
        print("#"*int(i),end="\n")

if __name__ == '__main__':
    n = int(input().strip())

    staircase(n)
