'''
itertools.combinations(iterable, r)
This tool returns the r length subsequences of elements from the input iterable.
Combinations are emitted in lexicographic sorted order. So, if the input iterable is sorted, the combination tuples will be produced in sorted order.

Task
You are given a string .
Your task is to print all possible combinations, up to size , of the string in lexicographic sorted order.

Input Format
A single line containing the string  and integer value  separated by a space.

Constraints
0 < k <= len(S)
The string contains only UPPERCASE characters.

Output Format
Print the different combinations of string  on separate lines.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
from itertools import combinations
S, k = input().split()
for i in range(1, int(k) + 1):
    for e in list(combinations(sorted(S), i)):
        print("".join(e))
