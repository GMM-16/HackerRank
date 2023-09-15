'''
A jail has a number of prisoners and a number of treats to pass out to them. Their jailer decides the fairest way to divide the treats is to seat the prisoners around a circular table in sequentially numbered chairs. A chair number will be drawn from a hat. Beginning with the prisoner in that chair, one candy will be handed to each prisoner sequentially around the table until all have been distributed.
The jailer is playing a little joke, though. The last piece of candy looks like all the others, but it tastes awful. Determine the chair number occupied by the prisoner who will receive that candy.

Function Description
Complete the saveThePrisoner function in the editor below. It should return an integer representing the chair number of the prisoner to warn.
saveThePrisoner has the following parameter(s):
int n: the number of prisoners
int m: the number of sweets
int s: the chair number to begin passing out sweets from
Returns
- int: the chair number of the prisoner to warn

Input Format
The first line contains an integer, t, the number of test cases.
The next  lines each contain 3 space-separated integers:
n : the number of prisoners
m : the number of sweets
s : the chair number to start passing out treats at

Constraints:-
1 <= t <= 100
1 <= n <= 10^9
1 <= m <= 10^9
1 <= s <= n
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'saveThePrisoner' function below.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER m
#  3. INTEGER s
#

def saveThePrisoner(n, m, s):
    # Write your code here
    rem = (m - 1) % n
    ans = (rem + s) % n
    if ans == 0:
        return n
    else:
        return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        n = int(first_multiple_input[0])

        m = int(first_multiple_input[1])

        s = int(first_multiple_input[2])

        result = saveThePrisoner(n, m, s)

        fptr.write(str(result) + '\n')

    fptr.close()
