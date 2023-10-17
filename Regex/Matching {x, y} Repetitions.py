'''
{x,y}
The {x,y} tool will match between x and y (both inclusive) repetitions of character/character class/group.

Task
You have a test string S.
Your task is to write a regex that will match S using the following conditions:
S should begin with 1 or 2 digits.
After that, S should have 3 or more letters (both lowercase and uppercase).
Then S should end with up to 3 . symbol(s). You can end with 0 to 3 . symbol(s), inclusively.

Note
This is a regex only challenge. You are not required to write any code.
You have to fill the regex pattern in the blank (_________).
'''

Regex_Pattern = r'^[0-9]{1,2}[A-z]{3,}[.]{,3}$'	
# Do not delete 'r'.

import re

print(str(bool(re.search(Regex_Pattern, input()))).lower())
