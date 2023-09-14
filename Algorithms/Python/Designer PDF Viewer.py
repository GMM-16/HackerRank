'''
When a contiguous block of text is selected in a PDF viewer, the selection is highlighted with a blue rectangle. In this PDF viewer, each word is highlighted independently.
There is a list of 26 character heights aligned by index to their letters. For example, 'a' is at index 0 and 'z' is at index 25. There will also be a string. Using the letter heights given, determine the area of the rectangle highlight in mm^2 assuming all letters are 1mm wide.

Function Description
Complete the designerPdfViewer function in the editor below.
designerPdfViewer has the following parameter(s):
int h[26]: the heights of each letter
string word: a string
Returns
- int: the size of the highlighted area

Input Format
The first line contains 26 space-separated integers describing the respective heights of each consecutive lowercase English letter, ascii[a-z].
The second line contains a single word consisting of lowercase English alphabetic letters.

Constraints
1 <= h[?] <= 7, where ? is an lowercase English letter
word contains no more than 10 letters
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'designerPdfViewer' function below.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY h
#  2. STRING word
#

def designerPdfViewer(h, word):
    # Write your code here
    ans = 0
    length = 0
    breadth = len(word)
    
    for i in range(breadth):
        temp = ord(word[i]) - ord('a')
        if h[temp] > length:
            length = h[temp]
    
    ans = length * breadth
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    h = list(map(int, input().rstrip().split()))

    word = input()

    result = designerPdfViewer(h, word)

    fptr.write(str(result) + '\n')

    fptr.close()
