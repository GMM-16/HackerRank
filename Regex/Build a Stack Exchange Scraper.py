'''
Stack Exchange is an information power-house, which contains libraries of crowdsourced problems (with answers) across a large number of topics which are as diverse as electronics, cooking , programming, etc.
We are greatly interested in crawling and scraping as many questions, as we can, from stack-exchange. This is an example of a question library page from stack-exchange.
Your task will be, to scrape the questions from each library page, in the order in which they are listed. You will be provided with the markup of question listing pages, from which you need to detect:
(1) Identifier (2) Question text (which is on the Hyperlink to the question) (3) How long ago the question was asked.
The Markup in the Test Cases will be similar to the sample fragment shown below. Please note, that since this markup is real markup from the website, it is likely to contain some stray control and escape characters, unexpected whitespaces and newlines.

Output Format
The output file should contain N lines, where N is the number of questions you have identified in the provided fragment.Each line contains the identifier, question text and (relative) time when the question was asked (with no leading or trailing spaces surrounding each section); separated by semi-colons. The information about the questions in the output file should match with the ordering in the original markup.

A Note Regarding the Test Cases
The markup in the test cases will resemble the markup fragment provided above, however, each markup fragment might contain a larger number of questions embedded in it. A markup fragment will have no more than 100 questions embedded in it.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
import sys
text=sys.stdin.read()
number=re.findall(r'(?<=summary-)\d+(?=\">)',text)
question=re.findall(r'(?<=link">).+(?=</a)',text)
time=re.findall(r'(?<=relativetime\">).+(?=</span)',text)

for n,q,t in zip(number,question,time):
   print('{};{};{}'.format(n,q,t))
