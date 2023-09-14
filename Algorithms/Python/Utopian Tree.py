'''
The Utopian Tree goes through 2 cycles of growth every year. Each spring, it doubles in height. Each summer, its height increases by 1 meter.
A Utopian Tree sapling with a height of 1 meter is planted at the onset of spring. How tall will the tree be after n growth cycles?

Function Description
Complete the utopianTree function in the editor below.
utopianTree has the following parameter(s):
int n: the number of growth cycles to simulate
Returns
- int: the height of the tree after the given number of cycles

Input Format
The first line contains an integer, t, the number of test cases.
t subsequent lines each contain an integer, n, the number of cycles for that test case.

Constraints
1 <= t <= 10
0 <= n <= 60
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'utopianTree' function below.
# The function is expected to return an INTEGER.
# The function accepts INTEGER n as parameter.
#

def utopianTree(n):
    # Write your code here
    temp = 0
    ans = 1
    while temp!=n:
        if temp%2==0:
            ans = ans * 2
        else:
            ans = ans + 1
        temp = temp + 1
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        result = utopianTree(n)

        fptr.write(str(result) + '\n')

    fptr.close()
