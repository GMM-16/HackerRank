/*
Given a string, s, consisting of alphabets and digits, find the frequency of each digit in the given string.

Input Format
The first line contains a string, num which is the given number.

Constraints
1 <= len(num) <= 1000
All the elements of num are made of english alphabets and digits.

Output Format
Print ten space-separated integers in a single line denoting the frequency of each digit from 0 to 9.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char num[1000];
    scanf("%s",num);
    int arr[10]={0};
    for(int i=0;i<strlen(num);i++)
    {
        if(!isalpha(num[i]))
        {
            arr[num[i]-48]++;
        }
    }
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
