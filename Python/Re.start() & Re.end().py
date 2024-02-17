'''
start() & end()
These expressions return the indices of the start and end of the substring matched by the group.

Code
>>> import re
>>> m = re.search(r'\d+','1234')
>>> m.end()
4
>>> m.start()
0

Task
You are given a string S.
Your task is to find the indices of the start and end of string k in S.

Input Format
The first line contains the string S.
The second line contains the string k.

Constraints
0 < len(S) < 100
0 < len(k) < len(S)

Output Format
Print the tuple in this format: (start _index, end _index).
If no match is found, print (-1, -1).
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
inp, pat = input(), input()
pattern = '(?=('+pat+'))'
if re.findall(pattern, inp):
    for res in re.finditer(pattern, inp):
        print((res.start(), res.start()+len(pat)-1))
else: print((-1, -1))
