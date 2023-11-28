: '
An Introduction to Grep
Grep is a multi-purpose search tool, which is used to find specified strings or regular expressions. A variety of options exist, which make it possible to use the command in several different ways and to handle many different situations. For example, one might opt for case-insensitive search, or to display only the fragment matching the specified search pattern, or to display only the line number of an input file where the specified string or regular expression has been found.
More details about common examples of grep usage may be read here.
Before using grep it is recommended that one should become familiar with regular expressions, to be able to harness the command to its fullest.

Current Task
Given a text file, which will be piped to your command through STDIN, use grep to display all those lines which contain any of the following words in them:
the
that
then
those
The search should not be sensitive to case. Display only those lines of an input file, which contain the required words.

Input Format
A text file with multiple lines will be piped to your command through STDIN.

Output Format
Display the required lines without any changes to their relative ordering.
'

grep -i '\<the\>\|\<that\>\|\<then\>\|\<those\>'
