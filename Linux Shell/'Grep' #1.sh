: '
Objective
In this challenge, we practice using the grep command to find specified strings or regular expressions.

Resources
Grep is a multi-purpose search tool that is used to find specified strings or regular expressions. A variety of options exist that makes it possible to use this command in several different ways and to handle many different situations. For example, one might opt for a case-insensitive search, or to display only the fragment matching the specified search pattern. The command could also be used to display only the line number of an input file where the specified string or regular expression has been found.
Before using grep, we recommend becoming familiar with regular expressions to be able to harness the command to its fullest.

Task
You are given a text file that will be piped into your command through STDIN. Use grep to display all the lines that contain the word the in them. The search should be sensitive to case. Display only those lines of the input file that contain the word 'the'.

Input Format
A text file will be piped into your command through STDIN.

Output Format
Output only those lines that contain the word 'the'. The search should be case sensitive. The relative ordering of the lines in the output should be the same as it was in the input.
'

grep "\bthe\b"
