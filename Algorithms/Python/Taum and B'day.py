'''
Taum is planning to celebrate the birthday of his friend, Diksha. There are two types of gifts that Diksha wants from Taum: one is black and the other is white. To make her happy, Taum has to buy b black gifts and w white gifts.
The cost of each black gift is bc units.
The cost of every white gift is wc units.
The cost to convert a black gift into white gift or vice versa is z units.
Determine the minimum cost of Diksha's gifts.

Function Description
Complete the function taumBday in the editor below. It should return the minimal cost of obtaining the desired gifts.
taumBday has the following parameter(s):
int b: the number of black gifts
int w: the number of white gifts
int bc: the cost of a black gift
int wc: the cost of a white gift
int z: the cost to convert one color gift to the other color
Returns
- int: the minimum cost to purchase the gifts

Input Format
The first line will contain an integer t, the number of test cases.
The next t pairs of lines are as follows:
- The first line contains the values of integers b and w.
- The next line contains the values of integers bc, wc, and z.

Constraints
1 <= t <= 10
0 <= b,w,bc,wc,z <= 10^9

Output Format
t lines, each containing an integer: the minimum amount of units Taum needs to spend on gifts.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'taumBday' function below.
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. INTEGER b
#  2. INTEGER w
#  3. INTEGER bc
#  4. INTEGER wc
#  5. INTEGER z
#

def taumBday(b, w, bc, wc, z):
    # Write your code here
    black = min(bc,wc+z)
    white = min(wc,bc+z)
    ans = black * b + white * w
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        first_multiple_input = input().rstrip().split()

        b = int(first_multiple_input[0])

        w = int(first_multiple_input[1])

        second_multiple_input = input().rstrip().split()

        bc = int(second_multiple_input[0])

        wc = int(second_multiple_input[1])

        z = int(second_multiple_input[2])

        result = taumBday(b, w, bc, wc, z)

        fptr.write(str(result) + '\n')

    fptr.close()
