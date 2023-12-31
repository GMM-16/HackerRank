'''
The equivalent of SSN in India is a PAN number, which is unique to each of its citizens. In any of the country's official documents, the PAN number is listed as follows
<char><char><char><char><char><digit><digit><digit><digit><char>
Your task is to figure out if the PAN number is valid or not. A valid PAN number will have all its letters in uppercase and digits in the same order as listed above.

Input Format

First line contains N. N lines follow, each having a PAN number.

Constraints
1 <= N <= 10
Each char is an uppercase letter, i.e., char ∈ ['A','Z'].
Each digit lies between 0 and 9, i.e., digit ∈ [0,9].
The length of the PAN number is always 10, i.e., length(PAN) = 10
Every character in PAN is either char or digit satisfying the above constraints.

Output Format
For every PAN number listed, print YES if it is valid and NO if it isn't.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
N = int(input())
for _ in range(N):
    S = input()
    if re.search(r"^[A-Z]{5}\d{4}[A-Z]$",S) :
        print("YES")
    else :
        print("NO")
