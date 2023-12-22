/*
Objective
In this challenge, you will learn the usage of the for loop, which is a programming language statement which allows code to be executed until a terminal condition is met. They can even repeat forever if the terminal condition is never met.
The syntax for the for loop is:
for ( <expression_1> ; <expression_2> ; <expression_3> )
    <statement>
expression_1 is used for intializing variables which are generally used for controlling the terminating flag for the loop.
expression_2 is used to check for the terminating condition. If this evaluates to false, then the loop is terminated.
expression_3 is generally used to update the flags/variables.

Task
For each integer n in the interval [a,b] (given as input) :
If 1 <= n <= 9, then print the English representation of it in lowercase. That is "one" for 1, "two" for 2, and so on.
Else if n > 9 and it is an even number, then print "even".
Else if n > 9 and it is an odd number, then print "odd".

Input Format
The first line contains an integer, a.
The seond line contains an integer, b.

Constraints
1 <= a <= b <= 10^6

Output Format
Print the appropriate English representation,even, or odd, based on the conditions described in the 'task' section.

Note: [a,b] = {x ∈ Z | a <= x <= b} = {a,a+1,.....,b}
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    for(int n = a; n<=b; n++) 
    {
        if(1<=n && n<=9)
        {
            if(n==1)
            {
                printf("one\n");
            }
            else if(n==2)
            {
                printf("two\n");
            }
            else if(n==3)
            {
                printf("three\n");
            }
            else if(n==4)
            {
                printf("four\n");
            }
            else if(n==5)
            {
                printf("five\n");
            }
            else if(n==6)
            {
                printf("six\n");
            }
            else if(n==7)
            {
                printf("seven\n");
            }
            else if(n==8)
            {
                printf("eight\n");     
            }
            else if(n==9)
            {
                printf("nine\n");
            }
        }
        else if(n>9 && n%2==0)
        {
            printf("even\n");
        }
        else if(n>9 && n%2!=0)
        {
            printf("odd\n");
        }
    }
    return 0;
}
