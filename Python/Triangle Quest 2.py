'''
You are given a positive integer N.
Your task is to print a palindromic triangle of size N.
You can't take more than two lines. The first line (a for-statement) is already written for you.
You have to complete the code using exactly one print statement.

Note:
Using anything related to strings will give a score of 0.
Using more than one for-statement will give a score of 0.

Input Format
A single line of input containing the integer N.

Constraints
0 < N < 10

Output Format
Print the palindromic triangle of size N as explained above.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
for i in range(1,int(input())+1): 
  print((((10**i)-1)//9)**2)
