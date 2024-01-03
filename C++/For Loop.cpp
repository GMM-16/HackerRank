/*
A for loop is a programming language statement which allows code to be repeatedly executed.

The syntax is

for ( <expression_1> ; <expression_2> ; <expression_3> )
{
    <statement>
}

expression_1 is used for intializing variables which are generally used for controlling the terminating flag for the loop.
expression_2 is used to check for the terminating condition. If this evaluates to false, then the loop is terminated.
expression_3 is generally used to update the flags/variables.

In this challenge, you will use a for loop to increment a variable through a range.

Input Format
You will be given two positive integers, a and b (a <= b), separated by a newline.

Output Format
For each integer n in the inclusive interval [a,b]:
If 1 <= n <= 9, then print the English representation of it in lowercase. That is "one" for 1, "two" for 2, and so on.
Else if n > 9 and it is an even number, then print "even".
Else if n > 9 and it is an odd number, then print "odd".
Note: [a,b] = {x ∈ Z | a <= x <= b} = {a, a+1 ,....., b}
*/

#include <iostream>
#include <cstdio>
using namespace std;

int main() 
{
    // Complete the code.
    int a,b;
    cin >> a;
    cin >> b;
    for(int i = a; i<=b ; i++)
    {
        if(i>=1 && i<=9)
        {
            if(i == 1)
            {
                cout << "one" << endl;
            }
            else if(i == 2)
            {
                cout << "two" << endl;
            }
            if(i == 3)
            {
                cout << "three" << endl;
            }
            else if(i == 4)
            {
                cout << "four" << endl;
            }
            else if(i == 5)
            {
                cout << "five" << endl;
            }
            else if(i == 6)
            {
                cout << "six" << endl;
            }
            else if(i == 7)
            {
                cout << "seven" << endl;
            }
            else if(i == 8)
            {
                cout << "eight" << endl;
            }
            else if(i == 9)
            {
                cout << "nine" << endl;
            }
        }
        else if(i>9 && i%2 == 0)
        {
            cout << "even" << endl;
        }
        else
        {
            cout << "odd" << endl;
        }
    }
    return 0;
}
