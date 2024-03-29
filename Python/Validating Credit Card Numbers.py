'''
You and Fredrick are good friends. Yesterday, Fredrick received N credit cards from ABCD Bank. He wants to verify whether his credit card numbers are valid or not. You happen to be great at regex so he is asking for your help!
A valid credit card from ABCD Bank has the following characteristics:
► It must start with a 4,5 or 6.
► It must contain exactly 16 digits.
► It must only consist of digits (0-9).
► It may have digits in groups of , separated by one hyphen "-".
► It must NOT use any other separator like ' ' , '_', etc.
► It must NOT have 4 or more consecutive repeated digits.

Input Format
The first line of input contains an integer N.
The next N lines contain credit card numbers.

Constraints
0 < N < 100

Output Format
Print 'Valid' if the credit card number is valid. Otherwise, print 'Invalid'. Do not print the quotes.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
test_cases = int(input())
for num in range(test_cases):
    case = input()
    valid_card_pattern = re.compile(r'^(?!.*(\d)(-*\1){3,})([4-6][0-9]{3}-?([0-9]{4}-?){3})$')
    if valid_card_pattern.match(case):
        print('Valid')
    else:
        print('Invalid')
