'''
A new identification number is given for every Citizen of the Country Utopia and it has the following format.
The string must begin with between 0-3 (inclusive) lowercase letters.
Immediately following the letters, there must be a sequence of digits (0-9). The length of this segment must be between 2 and 8, both inclusive.
Immediately following the numbers, there must be atleast 3 uppercase letters.
Your task is to find out if a given identification number is valid or not.

Input Format
The first line contains N, N lines follow each line containing an identification number.

Constraints
1 <= N <= 100

Output Format
For every identification number, please print
VALID
if the identification number is valid and print
INVALID
otherwise.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
N = int(input())
for _ in range(N):
    S = input()
    if re.search(r"^[a-z]{,3}\d{2,8}[A-Z]{3,}$",S):
        print("VALID")
    else:
        print("INVALID")
