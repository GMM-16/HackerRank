'''
A weighted string is a string of lowercase English letters where each letter has a weight. Character weights are 1 to 26 from a to z.
The weight of a string is the sum of the weights of its characters.
A uniform string consists of a single character repeated zero or more times.
Given a string, s, let U be the set of weights for all possible uniform contiguous substrings of string s. There will be n queries to answer where each query consists of a single integer. Create a return array where for each query, the value is Yes if query[i] ∈ U. Otherwise, append No.
Note: The ∈ symbol denotes that x[i] is an element of set U.

Function Description
Complete the weightedUniformStrings function in the editor below.
weightedUniformStrings has the following parameter(s):
- string s: a string
- int queries[n]: an array of integers
Returns
- string[n]: an array of strings that answer the queries

Input Format
The first line contains a string s, the original string.
The second line contains an integer n, the number of queries.
Each of the next n lines contains an integer queries[i], the weight of a uniform subtring of  that may or may not exist.

Constraints
1 <= lenghofs, n <= 10^5
1 <= queries[i] <= 10^7
s will only contain lowercase English letters, ascii[a-z].
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'weightedUniformStrings' function below.
# The function is expected to return a STRING_ARRAY.
# The function accepts following parameters:
#  1. STRING s
#  2. INTEGER_ARRAY queries
#

def weightedUniformStrings(s, queries):
    # Write your code here
    temp = []
    ans = []
    for i in range(len(s)):
        wt = ord(s[i]) - 96
        if i==0 or s[i]!=s[i-1]:
            temp.append(wt)
        else:
            temp.append(wt+temp[i-1])
    temp = set(temp)
    for q in queries:
        if q in temp:
            ans.append("Yes")
        else:
            ans.append("No")
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    queries_count = int(input().strip())

    queries = []

    for _ in range(queries_count):
        queries_item = int(input().strip())
        queries.append(queries_item)

    result = weightedUniformStrings(s, queries)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
