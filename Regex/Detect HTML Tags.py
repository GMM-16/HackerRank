'''
In this challenge, we're using regular expressions to detect the various tags used in an HTML document.
Tags come in pairs. Some tag name, t, will have an opening tag, <t>, followed by some intermediate text, followed by a closing tag, </t>. The forward slash in a closing tag will always come before the tag name.
The exception to this is self-closing tags, which consist of a single tag (not a pair) with a forward slash after the tag name: <p/>

Task
Given N lines of HTML, find the tag names (ignore any attributes) and print them as a single line of lexicographically ordered semicolon-separated values (e.g.: tag1;tag2;tag3).

Input Format
The first line contains an integer, N, the number of HTML fragments.
Each of the N subsequent lines contains a fragment of an HTML document.

Constraints
1 <= N <= 100
Each fragment contains <10000 ASCII characters.
The fragments are chosen from Wikipedia, so analyzing and observing their markup structure may help.
Leading and trailing spaces/indentation have been trimmed from the HTML fragments.

Output Format

Print a single line containing all of the unique tag names found in the input. Your output tags should be semicolon-separated and ordered lexicographically (i.e.: alphabetically). Do not print the same tag name more than once.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
open_tag = re.compile(r'<\s*([a-z1-6]+)[^>]*/?>')
ans = []
for _ in range(int(input())):
    s = input()    
    ans.extend(re.findall(open_tag,s))
print(*sorted(list(set(ans))), sep=";")
