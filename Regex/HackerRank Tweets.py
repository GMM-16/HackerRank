'''
Increasing popularity of hackerrank can be seen in tweets like
I love #hackerrank
I just scored 27 points in the Picking Cards challenge on #HackerRank
I just signed up for summer cup @hackerrank
Given a set of most popular tweets, your task is to find out how many of those tweets has the string hackerrank in it.

Input Format
First line is an integer N. N lines follow. Each line is a valid tweet.

Constraints
1 <= N <= 10
Each character of the tweet is a valid ASCII character.

Output format
Print the total number of tweets that has hackerrank (case insensitive) in it
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
N = int(input())
count = 0
for _ in range(N):
    S = input()
    if re.search(r"(?i)hackerrank",S):
        count += 1
print(count)
