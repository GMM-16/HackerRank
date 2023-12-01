'''
In Insertion Sort Part 1, you inserted one element into an array at its correct sorted position. Using the same approach repeatedly, can you sort an entire array?
Guideline: You already can place an element into a sorted array. How can you use that code to build up a sorted array, one element at a time? Note that in the first step, when you consider an array with just the first element, it is already sorted since there's nothing to compare it to.
In this challenge, print the array after each iteration of the insertion sort, i.e., whenever the next element has been inserted at its correct position. Since the array composed of just the first element is already sorted, begin printing after placing the second element.

Function Description
Complete the insertionSort2 function in the editor below.
insertionSort2 has the following parameter(s):
int n: the length of arr
int arr[n]: an array of integers
Prints
At each iteration, print the array as space-separated integers on its own line.

Input Format
The first line contains an integer, n, the size of arr.
The next line contains n space-separated integers arr[i].

Constraints
1 <= n <= 1000
-10000 <= arr[i] <= 10000, 0 <= i < n

Output Format
Print the entire array on a new line at every iteration.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'insertionSort2' function below.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER_ARRAY arr
#

def insertionSort2(n, arr):
    # Write your code here
    for i in range(1, len(arr)):
        key_value = arr[i]
        j = i-1
        while arr[j]> key_value and j>=0:
            arr[j+1] = arr[j]
            j-=1
        arr[j+1] = key_value    
        print(*arr)

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    insertionSort2(n, arr)
