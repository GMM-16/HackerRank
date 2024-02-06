'''
In this task, we would like for you to appreciate the usefulness of the groupby() function of itertools . To read more about this function
You are given a string S. Suppose a character 'c' occurs consecutively X times in the string. Replace these consecutive occurrences of the character 'c' with (X,c) in the string.
For a better understanding of the problem, check the explanation.

Input Format
A single line of input consisting of the string S.

Output Format
A single line of output consisting of the modified string.

Constraints
All the characters of  denote integers between 0 and 9.
1 <= |S| <= 10^4
'''

from itertools import groupby
string = input()
group = groupby(string)
for key, value in group:
    tu = tuple(value)
    print(tuple((len(tu), int(key))), end=' ')
