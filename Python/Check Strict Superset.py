'''
You are given a set A and n other sets.
Your job is to find whether set A is a strict superset of each of the N sets.
Print True, if A is a strict superset of each of the N sets. Otherwise, print False.
A strict superset has at least one element that does not exist in its subset.

Input Format
The first line contains the space separated elements of set A.
The second line contains integer n, the number of other sets.
The next n lines contains the space separated elements of the other sets.

Constraints
0 < len(set(A)) < 501
0 < N < 21
0 < len(otherSets) < 101

Output Format
Print True if set A is a strict superset of all other N sets. Otherwise, print False.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
a = set(map(int,input().split()))
n =int(input())
val =""
for i in range(n):
    b= set(map(int,input().split()))
    if len(b.difference(a))==0:
        val ="True"  
    else:
        val ="False"
        break
print(val)
