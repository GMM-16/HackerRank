'''
You are given a string, and you have to validate whether it's a valid Roman numeral. If it is valid, print True. Otherwise, print False. Try to create a regular expression for a valid Roman numeral.

Input Format
A single line of input containing a string of Roman characters.

Output Format
Output a single line containing True or False according to the instructions above.

Constraints
The number will be between 1 and 3999 (both included).
'''

regex_pattern = r"^(M{0,3})(D?C{0,3}|C[DM])(L?X{0,3}|X[LC])(V?I{0,3}|I[VX])$"	# Do not delete 'r'.
import re
print(str(bool(re.match(regex_pattern, input()))))
