'''
.remove(x)
This operation removes element x from the set.
If element x does not exist, it raises a KeyError.
The .remove(x) operation returns None.

.discard(x)
This operation also removes element x from the set.
If element x does not exist, it does not raise a KeyError.
The .discard(x) operation returns None.

.pop()
This operation removes and return an arbitrary element from the set.
If there are no elements to remove, it raises a KeyError.

Task
You have a non-empty set s, and you have to execute N commands given in N lines.
The commands will be pop, remove and discard.

Input Format
The first line contains integer n, the number of elements in the set s.
The second line contains n space separated elements of set s. All of the elements are non-negative integers, less than or equal to 9.
The third line contains integer N, the number of commands.
The next N lines contains either pop, remove and/or discard commands followed by their associated value.

Constraints
0 < n < 20
0 < N < 20

Output Format
Print the sum of the elements of set s on a single line.
'''
# Enter your code here. Read input from STDIN. Print output to STDOUT
n = int(input())
set_s = set(map(int, input().split()))
N = int(input())
for i in range(N):
    command = input().split()
    if command[0] == "pop":
        l = list(set_s)
        l.reverse()
        l.pop()
        l.reverse()
        set_s = set(l)
    else:
        set_s.discard(int(command[1]))
print(sum(set_s))
