'''
You are given a spreadsheet that contains a list of N athletes and their details (such as age, height, weight and so on). You are required to sort the data based on the Kth attribute and print the final resulting table. Follow the example given below for better understanding.
Note that K is indexed from 0 to M-1, where M is the number of attributes.
Note: If two attributes are the same for different rows, for example, if two atheletes are of the same age, print the row that appeared first in the input.

Input Format
The first line contains N and M separated by a space.
The next N lines each contain M elements.
The last line contains K.

Constraints
1 < N,M < 1000
0 <= K < M
Each element <= 1000

Output Format
Print the N lines of the sorted table. Each line should contain the space separated elements. Check the sample below for clarity.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

if __name__ == '__main__':
    first_multiple_input = input().rstrip().split()
    n = int(first_multiple_input[0])
    m = int(first_multiple_input[1])
    arr = []
    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))
    k = int(input().strip())
    for i in range(n):
        arr[i].append(i)
    s = sorted(arr, key=lambda x: (x[k], x[-1]))
    for i in range(n):
        s[i].pop()
        print(*s[i])
