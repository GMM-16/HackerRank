'''
An arcade game player wants to climb to the top of the leaderboard and track their ranking. The game uses Dense Ranking, so its leaderboard works like this:
The player with the highest score is ranked number 1 on the leaderboard.
Players who have equal scores receive the same ranking number, and the next player(s) receive the immediately following ranking number.

Function Description
Complete the climbingLeaderboard function in the editor below.
climbingLeaderboard has the following parameter(s):
int ranked[n]: the leaderboard scores
int player[m]: the player's scores
Returns
- int[m]: the player's rank after each new score

Input Format
The first line contains an integer n, the number of players on the leaderboard.
The next line contains n space-separated integers ranked[i], the leaderboard scores in decreasing order.
The next line contains an integer, m, the number games the player plays.
The last line contains m space-separated integers player[j], the game scores.

Constraints
1 <= n <= 2 * 10^5
1 <= m <= 2 * 10^5
0 <= ranked[i] <= 10^9 for 0 <= i < n
0 <= player[j] <= 10^9 for 0 <= j < m
The existing leadarboard, ranked, is in descending order
The player's scores, player, are in ascending order.

Subtask
For 60% of the maximum score:
1 <= n <= 200
1 <= m <= 200
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'climbingLeaderboard' function below.
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY ranked
#  2. INTEGER_ARRAY player
#

def climbingLeaderboard(ranked, player):
    # Write your code here
    player_ranks = []
    ranked = sorted(set(ranked), reverse=True)
    position = len(ranked)
    for temp in player:
        while position > 0 and temp >= ranked[position - 1]:
            position = position - 1
        player_rank = position + 1
        player_ranks.append(player_rank)
    return player_ranks

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ranked_count = int(input().strip())

    ranked = list(map(int, input().rstrip().split()))

    player_count = int(input().strip())

    player = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(ranked, player)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
