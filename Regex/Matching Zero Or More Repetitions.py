'''
*
The * tool will match zero or more repetitions of character/character class/group.

Task
You have a test string S.
Your task is to write a regex that will match S using the following conditions:
S should begin with 2 or more digits.
After that, S should have 0 or more lowercase letters.
S should end with 0 or more uppercase letters

Note
This is a regex only challenge. You are not required to write any code.
You have to fill the regex pattern in the blank (_________).
'''

Regex_Pattern = r'^\d{2,}[a-z]*[A-Z]*$'	
# Do not delete 'r'.

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())
