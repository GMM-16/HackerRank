'''
Happy Ladybugs is a board game having the following properties:
The board is represented by a string, b, of length . The ith character of the string, b[i], denotes the  cell of the board.
If b[i] is an underscore (i.e., _), it means the  cell of the board is empty.
If b[i] is an uppercase English alphabetic letter (ascii[A-Z]), it means the ith cell contains a ladybug of color b[i].
String b will not contain any other characters.
A ladybug is happy only when its left or right adjacent cell (i.e., b[i±1]) is occupied by another ladybug having the same color.
In a single move, you can move a ladybug from its current position to any empty cell.
Given the values of n and b for g games of Happy Ladybugs, determine if it's possible to make all the ladybugs happy. For each game, return YES if all the ladybugs can be made happy through some number of moves. Otherwise, return NO.

Function Description
Complete the happyLadybugs function in the editor below.
happyLadybugs has the following parameters:
string b: the initial positions and colors of the ladybugs
Returns
- string: either YES or NO

Input Format
The first line contains an integer g, the number of games.
The next g pairs of lines are in the following format:
The first line contains an integer n, the number of cells on the board.
The second line contains a string b that describes the n cells of the board.

Constraints
1 <= g,n <= 100
b[i] ∈ {_,ascii[A - Z]}
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'happyLadybugs' function below.
# The function is expected to return a STRING.
# The function accepts STRING b as parameter.
#

def happyLadybugs(b):
    # Write your code here
    if len(b) == 1:
        if b == '_':
            return "YES"
        else:
            return "NO"
    if '_' in b:
        if b.count('_') == len(b):
            return "YES"
        else:
            for i in b:
                if i != '_':
                    if b.count(i) == 1:
                        return "NO"
            return "YES"
    else:
        for i in range(len(b)):
            if i == 0:
                if b[i] != b[i+1]:
                    return "NO"
            elif i == len(b)-1:
                if b[i] != b[i-1]:
                    return "NO"
            else:
                if (b[i] != b[i-1]) and (b[i] != b[i+1]):
                    return "NO"
        return "YES"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    g = int(input().strip())

    for g_itr in range(g):
        n = int(input().strip())

        b = input()

        result = happyLadybugs(b)

        fptr.write(result + '\n')

    fptr.close()
