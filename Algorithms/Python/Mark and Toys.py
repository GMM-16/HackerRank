'''
Mark and Jane are very happy after having their first child. Their son loves toys, so Mark wants to buy some. There are a number of different toys lying in front of him, tagged with their prices. Mark has only a certain amount to spend, and he wants to maximize the number of toys he buys with this money. Given a list of toy prices and an amount to spend, determine the maximum number of gifts he can buy.
Note Each toy can be purchased only once.

Function Description
Complete the function maximumToys in the editor below.
maximumToys has the following parameter(s):
int prices[n]: the toy prices
int k: Mark's budget
Returns
- int: the maximum number of toys

Input Format
The first line contains two integers, n and k, the number of priced toys and the amount Mark has to spend.
The next line contains n space-separated integers prices[i]

Constraints
1 <= n <= 10^5
1 <= k <= 10^9
1 <= prices[i] <= 10^9
A toy can't be bought multiple times.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'maximumToys' function below.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY prices
#  2. INTEGER k
#

def maximumToys(prices, k):
    # Write your code here
    prices.sort()
    ans = 0
    for i in range(len(prices)):
        if ((k-prices[i]) > 0):
            ans = ans + 1
            k = k - prices[i]
    return ans
            
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    prices = list(map(int, input().rstrip().split()))

    result = maximumToys(prices, k)

    fptr.write(str(result) + '\n')

    fptr.close()
