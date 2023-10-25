'''
We define a word as a non-empty maximum sequence of characters that can contain only lowercase letters, uppercase letters, digits and underscores '_' (ASCII value 95). Maximum sequence means that the word has to be immediately preceeded by a character not allowed to occur in a word or by the left boundary of the sentence, and it has to be immediately followed by a character not allowed to occur in a word or by the right boundary of the sentence.
Given N sentences and T words, for each of these words, find the number of its occurences in all the N sentences.

Input Format
In the first line there is a single integer N. Each of the next N lines contains a single sentence. After that, in the next line, there is a single integer T denoting the number of words. In the i-th of the next T lines, there is a single word denoting the i-th word for which, you have to find the number of its occurences in the sentences.

Constraints
1 <= N <= 100
1 <= T <= 10

Output format
For every word, print the number of occurrences of the word in all the N sentences listed.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
sentence = '\n'.join([input() for _ in range(int(input()))])
for _ in range(int(input())):
    print(len(re.findall(f'\\b({input()})\\b', sentence)))
