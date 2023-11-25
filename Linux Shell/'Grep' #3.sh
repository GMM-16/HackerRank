: '
Objective
In this challenge, we practice using the grep command to find specified strings or regular expressions.

Resources
Grep is a multi-purpose search tool that is used to find specified strings or regular expressions. A variety of options exist that makes it possible to use this command in several different ways and to handle many different situations. For example, one might opt for a case-insensitive search, or to display only the fragment matching the specified search pattern. The command could also be used to display only the line number of an input file where the specified string or regular expression has been found.
Before using grep, we recommend becoming familiar with regular expressions to be able to harness the command to its fullest.

Task
You are given a text file that will be piped into your command through STDIN. Use grep to remove all those lines that contain the word 'that'. The search should NOT be sensitive to case.

Input Format
A text file will be piped into your command through STDIN.

Output Format
Only display those lines that do NOT contain the word 'that'. The relative ordering of the lines should be the same as it was in the input file.
'

grep -v -i "\bthat\b"
