'''
HackerLand Enterprise is adopting a new viral advertising strategy. When they launch a new product, they advertise it to exactly 5 people on social media.
On the first day, half of those 5 people like the advertisement and each shares it with 3 of their friends.
Assuming nobody receives the advertisement twice, determine how many people have liked the ad by the end of a given day, beginning with launch day as day 1.

Function Description
Complete the viralAdvertising function in the editor below.
viralAdvertising has the following parameter(s):
int n: the day number to report
Returns
- int: the cumulative likes at that day

Input Format
A single integer, n, the day number.

Constraints
1 <= n <= 50
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'viralAdvertising' function below.
# The function is expected to return an INTEGER.
# The function accepts INTEGER n as parameter.
#

def viralAdvertising(n):
    # Write your code here
    ans = 0
    temp = 5
    for i in range(n):
        temp = math.floor(temp/2)
        ans = ans + temp
        temp = temp * 3
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    result = viralAdvertising(n)

    fptr.write(str(result) + '\n')

    fptr.close()
