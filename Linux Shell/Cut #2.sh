: '
Display the 2nd and 7th character from each line of text.

Input Format
A text file with N lines of ASCII text only.

Constraints
1 <= N <= 100

Output Format
The output should contain N lines. Each line should contain just two characters at the 2nd and the 7th position of the corresponding input line.
'

while read line
do
    echo $line | cut -c 2,7
done
