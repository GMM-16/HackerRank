: '
Objective
In this challenge, we will practice using the sed command to parse and transform text.

Resources
Sed is a popular tool that enables quick parsing and transformation of text.

Task
For each line in a given input file, transform all the occurrences of the word "thy" with "your". The search should be case insensitive, i.e. "thy", "Thy", "tHy" etc. should be transformed to "your".

Input Format
A text file will be piped into your command via STDIN.

Output Format
Transform and display the text as required in the task.

sed 's/\bthy\b/your/ig'
'
