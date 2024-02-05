'''
collections.deque()
A deque is a double-ended queue. It can be used to add or remove elements from both ends.
Deques support thread safe, memory efficient appends and pops from either side of the deque with approximately the same O(1) performance in either direction.
Click on the link to learn more about deque() methods.
Click on the link to learn more about various approaches to working with deques: Deque Recipes.

Task
Perform append, pop, popleft and appendleft methods on an empty deque d.

Input Format
The first line contains an integer N, the number of operations.
The next N lines contains the space separated names of methods and their values.

Constraints
0 < N < 100

Output Format
Print the space separated elements of deque d.
'''

from collections import deque
x = int(input())
d = deque()
for i in range(x):
    inp = input().split(' ')
    if inp[0] == 'append':
        d.append(inp[1])
    elif inp[0] == 'appendleft':
        d.appendleft(inp[1])
    elif inp[0] == 'pop':
        d.pop()
    elif inp[0] == 'popleft':
        d.popleft()
deque_list = list(d)
print(' '.join(deque_list))
