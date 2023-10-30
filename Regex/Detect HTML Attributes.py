'''
Charlie's second assignment was given by the Professor as soon as he submitted the first one. Professor asked Charlie to create a list of all the attributes of every tag found in HTML pages.
<p>This is a paragraph</p>  
The above HTML string has p as its tag but no attributes.
<a href="http://www.quackit.com/html/tutorial/html_links.cfm">Example Link</a>
This string has a as a tag and href as an attribute.

Input Format
The first line contains N, the number of lines in the HTML fragment. This is followed by lines from a valid HTML document or fragment.

Constraints
Number of characters in the test fragments <= 10000 characters. Characters will be restricted to ASCII. Fragments for the tests will be picked up from Wikipedia.
Attributes are all lowercase alphabets.

Output Format
Each tag must be separated by a newline arranged in lexicographic order
Each attribute noted for a given tag must be arranged next to a tag in lexicographic order.
The output will be of the format
tag-1:attribute-1,attribute-2,attribute-3....
tag-2:attribute-1,attribute-2,attribute-3....
tag-3:attribute-1,attribute-2,attribute-3....
...
tag-n:attribute-1,attribute-2,attribute-3....
Where tag-1 is lexicographically smaller than tag-2 and attribute-1 is lexicographically smaller than attribute-2
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
N = int(input())
Dict = {}
for _ in range(N) :
    S = input().split(">")
    for i in S:           
        Pattern = re.findall(r"(?<=<)\w+|(?<=\s)\w+(?==)",i)
        if Pattern:
            try :
                Dict[Pattern[0]].extend(Pattern[1:])
            except :
                Dict[Pattern[0]] = Pattern[1:]

for i in sorted(Dict):
    print(f"{i}:{','.join(sorted(set(Dict[i])))}")
