'''
In Python, a string of text can be aligned left, right and center.

.ljust(width)
This method returns a left aligned string of length width.
>>> width = 20
>>> print 'HackerRank'.ljust(width,'-')
HackerRank----------  

.center(width)
This method returns a centered string of length width.
>>> width = 20
>>> print 'HackerRank'.center(width,'-')
-----HackerRank-----

.rjust(width)
This method returns a right aligned string of length width.
>>> width = 20
>>> print 'HackerRank'.rjust(width,'-')
----------HackerRank

Task
You are given a partial code that is used for generating the HackerRank Logo of variable thickness.
Your task is to replace the blank (______) with rjust, ljust or center.

Input Format
A single line containing the thickness value for the logo.

Constraints
The thickness must be an odd number.
0 < thickness > 50

Output Format
Output the desired logo.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT

n = int(input())
h_block = 'H' * n
sp_block = ' ' * n
bd_line = h_block + (sp_block * 3) + h_block
ct_line = (h_block * 5)

for ii in range(1, n * 2 + 1, 2):
    print(("H" * ii).center(2 * n - 1, ' '))

for _ in range(n + 1):
    print(bd_line.center(n * 6 - 1, ' '))

for _ in range(n // 2 + 1):
    print(ct_line.center(n * 6 - 1, ' '))

for _ in range(n + 1):
    print(bd_line.center(n * 6 - 1, ' '))

for ii in range(n * 2 - 1, 0, -2):
    print(("H" * ii).center(n * 10, ' '))
