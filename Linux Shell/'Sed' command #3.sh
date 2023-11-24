: '
Sed is a popular utility which enables quick parsing and transformation of text.

Task
Given an input file, in each line, highlight all the occurrences of 'thy' by wrapping them up in brace brackets. The search should be case-insensitive.

Input Format
A text file will be piped to your command via STDIN.

Output Format
Highlight all occurrences of 'thy' as shown in the example below.
'

sed 's/thy/{&}/ig'
