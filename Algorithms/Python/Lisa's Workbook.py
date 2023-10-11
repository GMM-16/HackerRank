'''
Lisa just got a new math workbook. A workbook contains exercise problems, grouped into chapters. Lisa believes a problem to be special if its index (within a chapter) is the same as the page number where it's located. The format of Lisa's book is as follows:
There are  chapters in Lisa's workbook, numbered from 1 to n.
The ith chapter has arr[i] problems, numbered from 1 to arr[i].
Each page can hold up to k problems. Only a chapter's last page of exercises may contain fewer than k problems.
Each new chapter starts on a new page, so a page will never contain problems from more than one chapter.
The page number indexing starts at 1.
Given the details for Lisa's workbook, can you count its number of special problems?

Function Description
Complete the workbook function in the editor below.
workbook has the following parameter(s):
int n: the number of chapters
int k: the maximum number of problems per page
int arr[n]: the number of problems in each chapter
Returns
- int: the number of special problems in the workbook

Input Format
The first line contains two integers n and k, the number of chapters and the maximum number of problems per page.
The second line contains n space-separated integers arr[i] where arr[i] denotes the number of problems in the ith chapter.

Constraints
1 <= n,k,arr[i] <= 100
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'workbook' function below.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER k
#  3. INTEGER_ARRAY arr
#

def workbook(n, k, arr):
    # Write your code here
    special = 0
    page = 1
    for chapter in range(n):
        prob = arr[chapter]
        for problem in range(1, prob + 1):
            if problem == page:
                special = special + 1
            if problem % k == 0 or problem == prob:
                page = page + 1
    return special

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    result = workbook(n, k, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
