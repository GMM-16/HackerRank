'''
itertools.product()
This tool computes the cartesian product of input iterables.
It is equivalent to nested for-loops.

Task
You are given a two lists A and B. Your task  to compute their cartesian product AXB.
Note: A and B are sorted lists, and the cartesian product's tuples should be output in sorted order.

Input Format
The first line contains the space separated elements of list A.
The second line contains the space separated elements of list B.
Both lists have no duplicate integer elements.

Constraints
0 < A < 30
0 < B < 30

Output Format
Output the space separated tuples of the cartesian product.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
from itertools import product
A = map(int, input().split(" "))
B = map(int, input().split(" "))
result = " ".join(map(str, list(product(A, B))))
print(result)
