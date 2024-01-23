'''
Mr. Vincent works in a door mat manufacturing company. One day, he designed a new door mat with the following specifications:
Mat size must be NXM. (N is an odd natural number, and M is 3 times N.)
The design should have 'WELCOME' written in the center.
The design pattern should only use |, . and - characters.

Input Format
A single line containing the space separated values of N and M.

Constraints
5 < N < 101
15 < M < 303
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
n, m = input().split()
n=int(n)
m=int(m)
x=1
for i in range(int(n/2)+1):
    if i==int(n/2):
        print(int((m-7)/2)*"-"+"WELCOME"+int((m-7)/2)*"-")
    else:
        y=m-3*x
        print(int(y/2)*"-"+x*".|."+int(y/2)*"-")
        x+=2
x=x-2
for i in range(int(n/2),0,-1):
    y=m-3*x
    print(int(y/2)*"-"+x*".|."+int(y/2)*"-")
    x-=2
