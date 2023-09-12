'''
Maria plays college basketball and wants to go pro. Each season she maintains a record of her play. She tabulates the number of times she breaks her season record for most points and least points in a game. Points scored in the first game establish her record for the season, and she begins counting from there.

Function Description
Complete the breakingRecords function in the editor below.
breakingRecords has the following parameter(s):
int scores[n]: points scored per game
Returns
- int[2]: An array with the numbers of times she broke her records. Index  is for breaking most points records, and index  is for breaking least points records.

Input Format
The first line contains an integer n, the number of games.
The second line contains n space-separated integers describing the respective values of score0, score1, .......... , score(n-1).

Constraints
1 <= n <= 1000
0 <= scores[i] <= 10^8
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'breakingRecords' function below.
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY scores as parameter.
#

def breakingRecords(scores):
    # Write your code here
    ans = [0,0]
    min = max = scores[0]
    for i in range(1,len(scores)):
        if scores[i]<min:
            ans[1] = ans[1] + 1
            min = scores[i]
        if scores[i]>max:
            ans[0] = ans[0] + 1
            max = scores[i]
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    scores = list(map(int, input().rstrip().split()))

    result = breakingRecords(scores)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
