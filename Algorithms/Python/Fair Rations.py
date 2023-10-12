'''
You are the benevolent ruler of Rankhacker Castle, and today you're distributing bread. Your subjects are in a line, and some of them already have some loaves. Times are hard and your castle's food stocks are dwindling, so you must distribute as few loaves as possible according to the following rules:
Every time you give a loaf of bread to some person i, you must also give a loaf of bread to the person immediately in front of or behind them in the line (i.e., persons i+1 or i-1).
After all the bread is distributed, each person must have an even number of loaves.
Given the number of loaves already held by each citizen, find and print the minimum number of loaves you must distribute to satisfy the two rules above. If this is not possible, print NO.

Function Description
Complete the fairRations function in the editor below.
fairRations has the following parameter(s):
int B[N]: the numbers of loaves each persons starts with
Returns
- string: the minimum number of loaves required, cast as a string, or 'NO'

Input Format
The first line contains an integer N, the number of subjects in the bread line.
The second line contains N space-separated integers B[i].

Constraints
2 <= N <= 1000
1 <= B[i] <= 10, where 1 <= i <= n
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'fairRations' function below.
# The function is expected to return a STRING.
# The function accepts INTEGER_ARRAY B as parameter.
#

def fairRations(B):
    # Write your code here
    ans = 0
    for i in range(len(B)-1):
        if B[i] % 2 != 0:
            B[i] = B[i] + 1
            B[i+1] = B[i+1] + 1
            ans = ans + 2
    if B[-1] % 2 != 0:
        return 'NO'
    else:          
        return str(ans)          

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    N = int(input().strip())

    B = list(map(int, input().rstrip().split()))

    result = fairRations(B)

    fptr.write(result + '\n')

    fptr.close()
