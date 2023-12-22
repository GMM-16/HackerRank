/*
In this challenge, you will use logical bitwise operators. All data is stored in its binary representation. The logical operators, and C language, use 1 to represent true and 0 to represent false. The logical operators compare bits in two numbers and return true or false, 0 or 1, for each bit compared.
Bitwise AND operator & The output of bitwise AND is 1 if the corresponding bits of two operands is 1. If either bit of an operand is 0, the result of corresponding bit is evaluated to 0. It is denoted by &.
Bitwise OR operator | The output of bitwise OR is 1 if at least one corresponding bit of two operands is 1. It is denoted by |.
Bitwise XOR (exclusive OR) operator ^ The result of bitwise XOR operator is 1 if the corresponding bits of two operands are opposite. It is denoted by ⊕.

Function Description
Complete the calculate_the_maximum function in the editor below.
calculate_the_maximum has the following parameters:
int n: the highest number to consider
int k: the result of a comparison must be lower than this number to be considered
Prints
Print the maximum values for the and, or and xor comparisons, each on a separate line.

Input Format
The only line contains 2 space-separated integers, n and k.

Constraints
2 <= n <= 10^3
2 <= k <= n
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) 
{
    //Write your code here.
    int temp[3] = {0};
    int ans[3] = {0};
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(i <= j)
            {
                continue;
            }
            temp[0] = i & j;
            temp[1] = i | j;
            temp[2] = i ^ j;
            for(int l=0; l<3; l++)
            {
                if(temp[l] < k)
                {
                    if(temp[l] > ans[l])
                    {
                        ans[l] = temp[l];
                    }
                }
            }
        }
    }
    printf("%d\n%d\n%d", ans[0], ans[1], ans[2]);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
