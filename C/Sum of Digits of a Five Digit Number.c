/*
Objective
The modulo operator, %, returns the remainder of a division. For example, 4 % 3 = 1 and 12 % 10 = 2. The ordinary division operator, /, returns a truncated integer value when performed on integers.

Task
Given a five digit integer, print the sum of its digits.

Input Format
The input contains a single five digit number, n.

Constraints
10000 <= n <= 99999

Output Format
Print the sum of the digits of the five digit number.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    int num=n,sum=0,d;
    for (int i=1; i<=5;i++)
    {
        d=n%10;
        sum=sum + d;
        n=n/10; 
    }
    printf("%d",sum);
    return 0;
}
