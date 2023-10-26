'''
You will be provided with a chunk of HTML markup. Your task is to identify the unique domain names from the links or Urls which are present in the markup fragment.
In case there are second level or higher level domains present in the markup, all of them need to be treated as unique.
Prefixes like "www." and "ww2.", if present, should be scrubbed out from the domain name.

Input Format
An Integer N. This is equal to the number of lines in the HTML Fragment which follows. A chunk of HTML Markup with embedded links, the length of which is N lines.

Output Format
One line, containing the list of detected domains, separated by semi-colons, in lexicographical order. Do not leave any leading or trailing spaces either at the ends of the line, or before and after the individual domain names.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
import sys
string = sys.stdin.read()
matches = re.findall(r'https?:\/\/(?:www\.|ww2\.)?([^\/\.\s]*\.[^\/\\\?_"\'\s]*)', string)
print(';'.join(sorted(set(matches))))
