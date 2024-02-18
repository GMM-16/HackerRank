'''
You are given a string S.
S contains alphanumeric characters only.
Your task is to sort the string S in the following manner:
All sorted lowercase letters are ahead of uppercase letters.
All sorted uppercase letters are ahead of digits.
All sorted odd digits are ahead of sorted even digits.

Input Format
A single line of input contains the string S.

Constraints
0 < len(s) < 1000

Output Format
Output the sorted string S.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
S = input()
even = []
odd = []
capital = []
small = []
for i in S:
    if i.isdigit() and int(i) % 2 == 0:
        even.append(i)
    if i.isdigit() and int(i) % 2 != 0:
        odd.append(i)
    if i.isupper():
        capital.append(i)
    if i.islower():
        small.append(i)


even = ''.join(sorted(even))
odd = ''.join(sorted(odd))
capital = ''.join(sorted(capital))
small = ''.join(sorted(small))

print(''.join((small, capital, odd, even)))
