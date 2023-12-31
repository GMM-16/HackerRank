'''
\b
\b assert position at a word boundary.
Three different positions qualify for word boundaries :
► Before the first character in the string, if the first character is a word character.
► Between two characters in the string, where one is a word character and the other is not a word character.
► After the last character in the string, if the last character is a word character.

Task
You have a test String S.
Your task is to write a regex which will match word starting with vowel (a,e,i,o, u, A, E, I , O or U).
The matched word can be of any length. The matched word should consist of letters (lowercase and uppercase both) only.
The matched word must start and end with a word boundary.

Note
This is a regex only challenge. You are not required to write a code.
You have to fill the regex pattern in the blank (_________).
'''

Regex_Pattern = r'\b[aeiouAEIOU]\D+\b'	
# Do not delete 'r'.

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())
