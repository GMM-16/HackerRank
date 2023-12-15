'''
Marc loves cupcakes, but he also likes to stay fit. Each cupcake has a calorie count, and Marc can walk a distance to expend those calories. If Marc has eaten j cupcakes so far, after eating a cupcake with c calories he must walk at least 2^j*c miles to maintain his weight.

Function Description
Complete the marcsCakewalk function in the editor below.
marcsCakewalk has the following parameter(s):
int calorie[n]: the calorie counts for each cupcake
Returns
- long: the minimum miles necessary

Input Format
The first line contains an integer n, the number of cupcakes in calorie.
The second line contains n space-separated integers, calorie[i].

Constraints
1 <= n <= 40
1 <= c[i] <= 1000
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'marcsCakewalk' function below.
# The function is expected to return a LONG_INTEGER.
# The function accepts INTEGER_ARRAY calorie as parameter.
#

def marcsCakewalk(calorie):
    # Write your code here
    ans = 0
    calorie = sorted(calorie, reverse=True)
    for i in range(len(calorie)):
        ans = ans + ((2**i)*calorie[i])
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    calorie = list(map(int, input().rstrip().split()))

    result = marcsCakewalk(calorie)

    fptr.write(str(result) + '\n')

    fptr.close()
