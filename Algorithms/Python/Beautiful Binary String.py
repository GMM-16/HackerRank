'''
Alice has a binary string. She thinks a binary string is beautiful if and only if it doesn't contain the substring "010".
In one step, Alice can change a 0 to a 1 or vice versa. Count and print the minimum number of steps needed to make Alice see the string as beautiful.

Function Description
Complete the beautifulBinaryString function in the editor below.
beautifulBinaryString has the following parameter(s):
string b: a string of binary digits
Returns
- int: the minimum moves required

Input Format
The first line contains an integer n, the length of binary string.
The second line contains a single binary string b.

Constraints
1 <= n <= 100
b[i] ∈ {0,1}

Output Format
Print the minimum number of steps needed to make the string beautiful.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'beautifulBinaryString' function below.
# The function is expected to return an INTEGER.
# The function accepts STRING b as parameter.
#

def beautifulBinaryString(b):
    # Write your code here
    return b.count('010')

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    b = input()

    result = beautifulBinaryString(b)

    fptr.write(str(result) + '\n')

    fptr.close()
