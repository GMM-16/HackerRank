'''
Complete the function solveMeFirst to compute the sum of two integers.

Function Description

Complete the solveMeFirst function in the editor below.
solveMeFirst has the following parameters:
int a: the first value
int b: the second value
Returns
- int: the sum of a and b 

Constraints
1 <= a,b <= 1000
'''

def solveMeFirst(a,b):
	# Hint: Type return a+b below
    ans = a + b
    return ans

num1 = int(input())
num2 = int(input())
res = solveMeFirst(num1,num2)
print(res)
