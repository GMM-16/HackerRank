/*
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
*/

#include <bits/stdc++.h>
using namespace std;

int solveMeFirst(int a, int b) {
 // Hint: Type return a+b; below:
  int ans;
  ans = a + b;
  return ans;
}

int main() {
  int num1, num2;
  int sum;
  cin>>num1>>num2;
  sum = solveMeFirst(num1,num2);
  cout<<sum;
  return 0;
}
