'''
Jim's Burgers has a line of hungry customers. Orders vary in the time it takes to prepare them. Determine the order the customers receive their orders. Start by numbering each of the customers from 1 to n, front of the line to the back. You will then be given an order number and a preparation time for each customer.
The time of delivery is calculated as the sum of the order number and the preparation time. If two orders are delivered at the same time, assume they are delivered in ascending customer number order.

Function Description
Complete the jimOrders function in the editor below. It should return an array of integers that represent the order that customers' orders are delivered.
jimOrders has the following parameter(s):
orders: a 2D integer array where each orders[i] is in the form [orders[i],prep[i]].

Input Format
The first line contains an integer n, the number of customers.
Each of the next n lines contains two space-separated integers, an order number and prep time for customer[i].

Constraints
1 <= n <= 10^3
1 <= i <= n
1 <= order[i],prep[i] <= 10^6

Output Format
Print a single line of n space-separated customer numbers (recall that customers are numbered from 1 to n) that describes the sequence in which the customers receive their burgers. If two or more customers receive their burgers at the same time, print their numbers in ascending order.
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'jimOrders' function below.
# The function is expected to return an INTEGER_ARRAY.
# The function accepts 2D_INTEGER_ARRAY orders as parameter.
#

def jimOrders(orders):
    # Write your code here
    ans = []
    temp = []
    for i in range(len(orders)):
        temp.append((orders[i][0]+orders[i][1], i+1))
    temp.sort()
    for i in range(len(temp)):
        ans.append(temp[i][1])
    return ans
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    orders = []

    for _ in range(n):
        orders.append(list(map(int, input().rstrip().split())))

    result = jimOrders(orders)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
