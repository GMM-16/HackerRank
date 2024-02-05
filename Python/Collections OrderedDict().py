'''
collections.OrderedDict
An OrderedDict is a dictionary that remembers the order of the keys that were inserted first. If a new entry overwrites an existing entry, the original insertion position is left unchanged.

Task
You are the manager of a supermarket.
You have a list of N items together with their prices that consumers bought on a particular day.
Your task is to print each item_name and net_price in order of its first occurrence.
item_name = Name of the item.
net_price = Quantity of the item sold multiplied by the price of each item.

Input Format
The first line contains the number of items, N.
The next N lines contains the item's name and price, separated by a space.

Constraints
0 < N <= 100

Output Format
Print the item_name and net_price in order of its first occurrence.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import OrderedDict
n=int(input())
od = OrderedDict()
for _ in range(n):
    lst=input().rsplit(' ', 1)
    if lst[0] in od:
        od[lst[0]] += int(lst[1])
    else:
        od[lst[0]] =int(lst[1])
for key, value in od.items():
    print(key, value)
