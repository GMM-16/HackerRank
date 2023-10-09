'''
You wish to buy video games from the famous online video game store Mist.
Usually, all games are sold at the same price,p  dollars. However, they are planning to have the seasonal Halloween Sale next month in which you can buy games at a cheaper price. Specifically, the first game will cost p dollars, and every subsequent game will cost d dollars less than the previous one. This continues until the cost becomes less than or equal to m dollars, after which every game will cost m dollars. How many games can you buy during the Halloween Sale?

Function Description
Complete the howManyGames function in the editor below.
howManyGames has the following parameters:
int p: the price of the first game
int d: the discount from the previous game price
int m: the minimum cost of a game
int s: the starting budget

Input Format
The first and only line of input contains four space-separated integers p, d, m and s.

Constraints
1 <= m <= p <= 100
1 <= d <= 100
1 <= s <= 10^4
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'howManyGames' function below.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER p
#  2. INTEGER d
#  3. INTEGER m
#  4. INTEGER s
#

def howManyGames(p, d, m, s):
    # Return the number of games you can buy
    games = 0
    while(s >= p):
        games = games + 1
        s = s - p
        p = max(p-d, m)
    return games

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    p = int(first_multiple_input[0])

    d = int(first_multiple_input[1])

    m = int(first_multiple_input[2])

    s = int(first_multiple_input[3])

    answer = howManyGames(p, d, m, s)

    fptr.write(str(answer) + '\n')

    fptr.close()
