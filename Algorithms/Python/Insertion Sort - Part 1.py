'''
Sorting
One common task for computers is to sort data. For example, people might want to see all their files on a computer sorted by size. Since sorting is a simple problem with many different possible solutions, it is often used to introduce the study of algorithms.
Insertion Sort
These challenges will cover Insertion Sort, a simple and intuitive sorting algorithm. We will first start with a nearly sorted list.
Insert element into sorted list
Given a sorted list with an unsorted number e in the rightmost cell, can you write some simple code to insert e into the array so that it remains sorted?
Since this is a learning exercise, it won't be the most efficient way of performing the insertion. It will instead demonstrate the brute-force method in detail.
Assume you are given the array arr = [1,2,3,4,5] indexed 0...4. Store the value of arr[4]. Now test lower index values successively from 3 to 0 until you reach a value that is lower than arr[4], at arr[1] in this case. Each time your test fails, copy the value at the lower index to the current index and print your array. When the next lower indexed value is smaller than arr[4], insert the stored value at the current index and print the entire array.

Function Description
Complete the insertionSort1 function in the editor below.
insertionSort1 has the following parameter(s):
n: an integer, the size of arr
arr: an array of integers to sort
Returns
None: Print the interim and final arrays, each on a new line. No return value is expected.

Input Format
The first line contains the integer n, the size of the array arr.
The next line contains n space-separated integers arr[0]...arr[n-1].

Constraints
1 <= n <= 1000
-10000 <= arr[i] <= 10000

Output Format
Print the array as a row of space-separated integers each time there is a shift or insertion.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'insertionSort1' function below.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER_ARRAY arr
#

def insertionSort1(n, arr):
    # Write your code here
    value = arr[-1]
    sorted_arr = sorted(arr)
    for i in arr[-2::-1]:
        if arr == sorted_arr:
            break
        elif i > value:
            arr[arr.index(i) + 1] = i
        else:
            arr[arr.index(i) + 1] = value
        print(*arr)
    else:
        if arr != sorted_arr: 
            arr[0] = value
            print(*arr)

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    insertionSort1(n, arr)
