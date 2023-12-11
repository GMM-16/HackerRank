'''
Priyanka works for an international toy company that ships by container. Her task is to the determine the lowest cost way to combine her orders for shipping. She has a list of item weights. The shipping company has a requirement that all items loaded in a container must weigh less than or equal to 4 units plus the weight of the minimum weight item. All items meeting that requirement will be shipped in one container.
What is the smallest number of containers that can be contracted to ship the items based on the given list of weights?

Function Description
Complete the toys function in the editor below. It should return the minimum number of containers required to ship.
toys has the following parameter(s):
w: an array of integers that represent the weights of each order to ship

Input Format
The first line contains an integer n, the number of orders to ship.
The next line contains n space-separated integers, w[1],w[2],.....,w[n], representing the orders in a weight array.

Constraints
1 <= n <= 10^5
0 <= w[i] <= 10^4, where i ∈ [1,n]

Output Format
Return the integer value of the number of containers Priyanka must contract to ship all of the toys.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'toys' function below.
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY w as parameter.
#

def toys(w):
    # Write your code here
    w.sort()
    i = 0
    ans = 0
    while i < len(w):
        start = w[i]
        end = start + 4
        while i < len(w) and start <= w[i] <= end:
            i = i + 1
        ans = ans + 1
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    w = list(map(int, input().rstrip().split()))

    result = toys(w)

    fptr.write(str(result) + '\n')

    fptr.close()
