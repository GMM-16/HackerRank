: '
Objective
In this challenge, we will practice using the sed command to parse and transform text.

Resources
Sed is a popular tool that enables quick parsing and transformation of text.

Task
For each line in a given input file, transform the first occurrence of the word 'the' with 'this'. The search and transformation should be strictly case sensitive.

Input Format
A text file will be piped into your command through STDIN.

Output Format
Transform the text as specified by the task.
'

sed 's/\bthe\b/this/'
