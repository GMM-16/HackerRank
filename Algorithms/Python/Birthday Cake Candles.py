'''
You are in charge of the cake for a child's birthday. You have decided the cake will have one candle for each year of their total age. They will only be able to blow out the tallest of the candles. Count how many candles are tallest.

Function Description
Complete the function birthdayCakeCandles in the editor below.
birthdayCakeCandles has the following parameter(s):
int candles[n]: the candle heights
Returns
- int: the number of candles that are tallest

Input Format
The first line contains a single integer, n, the size of candles[].
The second line contains n space-separated integers, where each integer i describes the height of candles[i].

Constraints
1 <= n <= 10^5
1 <= candles[i] <= 10^7
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    # Write your code here
    time = s.split(':')
    hh,mm,ss = int(time[0]),int(time[1]),int(time[2][:2])
    pm = s[-2:]=="PM"
    if pm and hh!=12:
        hh = hh + 12
    if not pm and hh==12:
        hh = 0
    return f"{hh:02d}:{mm:02d}:{ss:02d}"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
