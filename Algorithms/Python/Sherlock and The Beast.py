'''
Sherlock Holmes suspects his archenemy Professor Moriarty is once again plotting something diabolical. Sherlock's companion, Dr. Watson, suggests Moriarty may be responsible for MI6's recent issues with their supercomputer, The Beast.
Shortly after resolving to investigate, Sherlock receives a note from Moriarty boasting about infecting The Beast with a virus. He also gives him a clue: an integer. Sherlock determines the key to removing the virus is to find the largest Decent Number having that number of digits.
A Decent Number has the following properties:
Its digits can only be 3's and/or 5's.
The number of 3's it contains is divisible by 5.
The number of 5's it contains is divisible by 3.
It is the largest such number for its length.
Moriarty's virus shows a clock counting down to The Beast's destruction, and time is running out fast. Your task is to help Sherlock find the key before The Beast is destroyed!

Function Description
Complete the decentNumber function in the editor below.
decentNumber has the following parameter(s):
int n: the length of the decent number to create
Prints
Print the decent number for the given length, or -1 if a decent number of that length cannot be formed. No return value is expected.

Input Format
The first line is an integer, t, the number of test cases.
The next t lines each contain an integer n, the number of digits in the number to create.

Constraints
1 <= t <= 20
1 <= n <= 100000
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'decentNumber' function below.
# The function accepts INTEGER n as parameter.
#

def decentNumber(n):
    # Write your code here
    if n % 3 == 0:
        print("5" * n)
    else:
        i = n
        while i >= 0 and (i % 3 != 0 or (n - i) % 5 != 0):
            i -= 5
        if i >= 0:
            print("5" * i, "3" * (n - i), sep="")
        else:
            print(-1)

if __name__ == '__main__':
    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        decentNumber(n)
