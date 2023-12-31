'''
At HackerRank, we always want to find out how popular we are getting every day and have scraped conversations from popular sites. Each conversation fits in 1 line and there are N such conversations. Each conversation has at most 1 word that says hackerrank (all in lowercase). We would like you to help us figure out whether a conversation:
Starts with hackerrank
Ends with hackerrank
Start and ends with hackerrank

Input Format
First line of the input contains an integer, N. Then N lines follow.
From the second line onwards, each line contains a set of W words separated by a single space

Constraints
1 <= N <= 10
1 <= W <= 100
All the characters in W are lowercase alphabet characters.
If C is the count of the characters in W, then 1 <= C <= 20

Output Format
For every line,
Print 1 if the conversation starts with hackerrank
Print 2 if the conversation ends with hackerrank
Print 0 if the conversation starts and ends with hackerrank
Print -1 if none of the above.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
for _ in range(int(input())) :
    a = input()
    if re.search(r'^hackerrank.*hackerrank$|^hackerrank$',a) :
        print(0)
    elif re.search(r'hackerrank$',a) :
        print(2)
    elif re.search(r'^hackerrank',a) :
        print(1)
    else :
        print(-1)
