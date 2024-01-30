'''
There is an array of n integers. There are also 2 disjoint sets, A and B, each containing m integers. You like all the integers in set A and dislike all the integers in set B. Your initial happiness is 0. For each i integer in the array, if i ∈ A, you add 1 to your happiness. If i ∈ B, you add -1 to your happiness. Otherwise, your happiness does not change. Output your final happiness at the end.
Note: Since A and B are sets, they have no repeated elements. However, the array might contain duplicate elements.

Constraints
1 <= n <= 10^5
1 <= m <= 10^5
1 <= Any integer in the input <= 10^9

Input Format
The first line contains integers n and m separated by a space.
The second line contains n integers, the elements of the array.
The third and fourth lines contain m integers, A and B, respectively.

Output Format
Output a single integer, your total happiness.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
n, m = input().split()
elemenets = input().split()
set_a = set(input().split())
set_b = set(input().split())
ans = 0


for i in range(len(elemenets)):
    if elemenets[i] in set_a:
        ans += 1
    if elemenets[i] in set_b:
        ans -= 1

print(ans)
