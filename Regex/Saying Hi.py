'''
Given a sentence, s, write a RegEx to match the following criteria:
The first character must be the letter H or h.
The second character must be the letter I or i.
The third character must be a single space (i.e.: \s).
The fourth character must not be the letter D or d.
Given n lines of sentences as input, print each sentence matching your RegEx on a new line.

Input Format
The first line contains an integer, n, denoting the number of lines of sentences.
Each of the n subsequent lines contains some sentence s you must match.

Constraints
1 <= n <= 10
Each sentence, s, contains 1 to 10 words.
Each word/token in a sentence is comprised only of upper and lowercase English letters.

Output Format
Find each sentence, s, satisfying the RegEx criteria mentioned above, and print it on a new line.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
n = int(input())
for _ in range(n):
    S = input()
    if re.search("^[Hh][Ii]\s[^Dd]",S):
        print(S)
