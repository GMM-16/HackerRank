'''
collections.Counter()
A counter is a container that stores elements as dictionary keys, and their counts are stored as dictionary values.

Task
Raghu is a shoe shop owner. His shop has X number of shoes.
He has a list containing the size of each shoe he has in his shop.
There are N number of customers who are willing to pay xi amount of money only if they get the shoe of their desired size.
Your task is to compute how much money Raghu earned.

Input Format
The first line contains X, the number of shoes.
The second line contains the space separated list of all the shoe sizes in the shop.
The third line contains N, the number of customers.
The next N lines contain the space separated values of the shoe size desired by the customer and xi, the price of the shoe.

Constraints
0 < X < 10^3
0 < N <= 10^3
20 < xi < 100
2 < shoe size < 20

Output Format
Print the amount of money earned by Raghu.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import Counter
x=int(input())
temp = Counter(list(map(int, input().split())))
n=int(input())
ans=0
for i in range(n):
    k,v=map(int,input().split())
    if temp[k]>=1:
        ans=ans+v
        temp[k]=temp[k]-1
print(ans)
