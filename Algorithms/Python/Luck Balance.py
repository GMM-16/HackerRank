'''
Lena is preparing for an important coding competition that is preceded by a number of sequential preliminary contests. Initially, her luck balance is 0. She believes in "saving luck", and wants to check her theory. Each contest is described by two integers, L[i] and T[i]:
L[i] is the amount of luck associated with a contest. If Lena wins the contest, her luck balance will decrease by L[i]; if she loses it, her luck balance will increase by L[i].
T[i] denotes the contest's importance rating. It's equal to 1 if the contest is important, and it's equal to 0 if it's unimportant.
If Lena loses no more than k important contests, what is the maximum amount of luck she can have after competing in all the preliminary contests? This value may be negative.

Function Description
Complete the luckBalance function in the editor below.
luckBalance has the following parameter(s):
int k: the number of important contests Lena can lose
int contests[n][2]: a 2D array of integers where each contests[i] contains two integers that represent the luck balance and importance of the ith contest
Returns
- int: the maximum luck balance achievable

Input Format
The first line contains two space-separated integers n and k, the number of preliminary contests and the maximum number of important contests Lena can lose.
Each of the next n lines contains two space-separated integers, L[i] and T[i], the contest's luck balance and its importance rating.

Constraints
1 <= n <= 100
0 <= k <= N
1 <= L[i] <= 10^4
T[i] ∈ {0,1}
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'luckBalance' function below.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. 2D_INTEGER_ARRAY contests
#

def luckBalance(k, contests):
    # Write your code here
    ans=0;
    temp=[]
    for i in contests:
        if i[1]==0:
            ans+=i[0]
        else:
            temp.append(i[0])
    temp.sort(reverse=True)
    ans+=(sum(temp[:k])-sum(temp[k:]))
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    contests = []

    for _ in range(n):
        contests.append(list(map(int, input().rstrip().split())))

    result = luckBalance(k, contests)

    fptr.write(str(result) + '\n')

    fptr.close()
