/*
Strings are usually ordered in lexicographical order. That means they are ordered by comparing their leftmost different characters.
Given an array of strings sorted in lexicographical order, print all of its permutations in strict lexicographical order. If two permutations look the same, only print one of them.
Complete the function next_permutation which generates the permutations in the described order.
Note: There may be two or more of the same string as elements of s.

Input Format
The first line of each test file contains a single integer n, the length of the string array s.
Each of the next n lines contains a string s[i].

Constraints
2 <= n <= 9
1 <= |s[i]| <= 10
s[i] contains only lowercase English letters.

Output Format
Print each permutation as a list of space-separated strings on a single line.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    for (int i=n-2; i>=0; i--)
    {
        if (strcmp(s[i], s[i+1]) < 0)
        {
            for (int j=n-1; j>i; j--)
            {
                if (strcmp(s[j], s[i]) > 0)
                {
                    char *temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    
                    for (int t=i+1, k=n-1; t<k; t++, k--)
                    {
                        char *temp = s[t];
                        s[t] = s[k];
                        s[k] = temp;
                    }

                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
