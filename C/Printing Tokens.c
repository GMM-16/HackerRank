/*
Given a sentence, s, print each word of the sentence in a new line.

Input Format
The first and only line contains a sentence, s.

Constraints
1 <= len(s) <= 1000

Output Format
Print each word of the sentence in a new line.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.
    int n=strlen(s);
    for(int i=0;i<n;i++)
    {
        printf("%c",s[i]);
        if(s[i]==' ')
        {
            printf("\n");
        }
        continue;
    }
    return 0;
}
