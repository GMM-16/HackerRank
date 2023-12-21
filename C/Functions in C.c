/*
Objective
In this challenge, you will learn simple usage of functions in C. Functions are a bunch of statements grouped together. A function is provided with zero or more arguments, and it executes the statements on it. Based on the return type, it either returns nothing (void) or something.

Task
Write a function int max_of_four(int a, int b, int c, int d) which reads four arguments and returns the greatest of them.

Note
There is not built in max function in C. Code that will be reused is often put in a separate function, e.g. int max(x, y) that returns the greater of the two values.

Input Format
Input will contain four integers - a, b, c, d, one on each line.

Output Format
Print the greatest of the four integers.
Note: I/O will be automatically handled.
*/

#include <stdio.h>
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/

int max_of_four(int a, int b, int c, int d)
{
    int res = 0;
    if (a > res)
    {
        res = a;
    }
    if (b > res)
    {    
        res = b;
    }
    if (c > res)
    {    
        res = c;
    }
    if(d > res)
    {
        res = d;
    }
    return res;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    return 0;
}
