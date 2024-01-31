'''
You are given a string S.
Your task is to find out whether S is a valid regex or not.

Input Format
The first line contains integer T, the number of test cases.
The next T lines contains the string S.

Constraints
0 < T < 100

Output Format
Print "True" or "False" for each test case without quotes.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
if __name__ == '__main__':
    n = int(input())
    
    for i in range(0, n):
        try:
            # Try to compile regex
            re.compile(input())
            print(True)
        except Exception:
            print(False)
