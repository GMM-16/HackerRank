'''
We define a word character to be any of the following:
An English alphabetic letter (i.e., a-z and A-Z).
A decimal digit (i.e., 0-9).
An underscore (i.e., _, which corresponds to ASCII value 95).
We define a word to be a contiguous sequence of one or more word characters that is preceded and succeeded by one or more occurrences of non-word-characters or line terminators. For example, in the string I l0ve-cheese_?, the words are I, l0ve, and cheese_.
We define a sub-word as follows:
A sequence of word characters (i.e., English alphabetic letters, digits, and/or underscores) that occur in the same exact order (i.e., as a contiguous sequence) inside another word.
It is preceded and succeeded by word characters only.
Given n sentences consisting of one or more words separated by non-word characters, process q queries where each query consists of a single string, s. To process each query, count the number of occurrences of s as a sub-word in all n sentences, then print the number of occurrences on a new line.

Input Format
The first line contains an integer, n, denoting the number of sentences.
Each of the n subsequent lines contains a sentence consisting of words separated by non-word characters.
The next line contains an integer, q, denoting the number of queries.
Each line i of the q subsequent lines contains a string, si, to check.

Constraints
1 <= n <= 100
1 <= q <= 10

Output Format
For each query string, si, print the total number of times it occurs as a sub-word within all words in all n sentences.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
n = int(input().strip())
sentences = ' '.join(input().strip() for _ in range(n))
q = int(input().strip())
queries = [input().strip() for _ in range(q)]
for query in queries:
    pattern = r'\B({})\B'.format(query)
    matches = re.findall(pattern, sentences)
    print(len(matches))
