'''
Flatland is a country with a number of cities, some of which have space stations. Cities are numbered consecutively and each has a road of 1km length connecting it to the next city. It is not a circular route, so the first city doesn't connect with the last city. Determine the maximum distance from any city to its nearest space station.

Function Description
Complete the flatlandSpaceStations function in the editor below.
flatlandSpaceStations has the following parameter(s):
int n: the number of cities
int c[m]: the indices of cities with a space station
Returns
- int: the maximum distance any city is from a space station

Input Format
The first line consists of two space-separated integers, n and m.
The second line contains m space-separated integers, the indices of each city that has a space-station. These values are unordered and distinct.

Constraints
1 <= n <= 10^5
1 <= m <= n
There will be at least 1 city with a space station.
No city has more than one space station.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the flatlandSpaceStations function below.
def flatlandSpaceStations(n, c):
    c.sort()
    ans = c[0]
    for i in range(1, len(c)):
        distance = (c[i] - c[i - 1]) // 2
        ans = max(ans, distance)
    ans = max(ans, n - 1 - c[-1])
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    c = list(map(int, input().rstrip().split()))

    result = flatlandSpaceStations(n, c)

    fptr.write(str(result) + '\n')

    fptr.close()
