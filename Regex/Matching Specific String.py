'''
Regular expression (or RegEx)
A regular expression is a sequence of characters that define a search pattern. It is mainly used for string pattern matching.
Regular expressions are extremely useful in extracting information from text such as: code, log files, spreadsheets, documents, etc.
We can match a specific string X in a test string S by making our regex pattern X. This is one of the simplest patterns. However, in the coming challenges, we'll see how well we can match more complex patterns and learn about their syntax.

Task
You have a test string S. Your task is to match the string hackerrank. This is case sensitive.

Note
This is a regex only challenge. You are not required to write code.
You only have to fill in the regex pattern in the blank (_________).
'''

Regex_Pattern = r'\bhackerrank\b'	
# Do not delete 'r'.

import re

Test_String = input()

match = re.findall(Regex_Pattern, Test_String)

print("Number of matches :", len(match))
