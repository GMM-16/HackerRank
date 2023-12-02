'''
Louise joined a social networking site to stay in touch with her friends. The signup page required her to input a name and a password. However, the password must be strong. The website considers a password to be strong if it satisfies the following criteria:
Its length is at least 6.
It contains at least one digit.
It contains at least one lowercase English character.
It contains at least one uppercase English character.
It contains at least one special character. The special characters are: !@#$%^&*()-+
She typed a random string of length  in the password field but wasn't sure if it was strong. Given the string she typed, can you find the minimum number of characters she must add to make her password strong?
Note: Here's the set of types of characters in a form you can paste in your solution:
numbers = "0123456789"
lower_case = "abcdefghijklmnopqrstuvwxyz"
upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
special_characters = "!@#$%^&*()-+"

Function Description
Complete the minimumNumber function in the editor below.
minimumNumber has the following parameters:
int n: the length of the password
string password: the password to test
Returns
- int: the minimum number of characters to add

Input Format
The first line contains an integer n, the length of the password.
The second line contains the password string. Each character is either a lowercase/uppercase English alphabet, a digit, or a special character.

Constraints
1 <= n <= 100
All characters in password are in [a-z], [A-Z], [0-9], or [!@#$%^&*()-+ ].
'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'minimumNumber' function below.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. STRING password
#

def minimumNumber(n, password):
    # Return the minimum number of characters to make the password strong
    numbers = "0123456789"
    lower_case = "abcdefghijklmnopqrstuvwxyz"
    upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    special_characters = "!@#$%^&*()-+"
    hasNumbers=False
    hasLowerCase=False
    hasUpperCase=False
    hasSpecialChar=False
    
    for char in password:
        if char in numbers:
            hasNumbers=True
        if char in lower_case:
            hasLowerCase=True
        if char in upper_case:
            hasUpperCase=True
        if char in special_characters:
            hasSpecialChar=True   
    count=0
    if not hasNumbers:
        count += 1
    if not hasLowerCase:
        count += 1
    if not hasUpperCase:
        count += 1
    if not hasSpecialChar:
        count += 1  
    ans = max(6- len(password), count)
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    password = input()

    answer = minimumNumber(n, password)

    fptr.write(str(answer) + '\n')

    fptr.close()
