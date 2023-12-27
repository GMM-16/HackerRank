/*
To sort a given array of strings into lexicographically increasing order or into an order in which the string with the lowest length appears first, a sorting function with a flag indicating the type of comparison strategy can be written. The disadvantage with doing so is having to rewrite the function for every new comparison strategy.
A better implementation would be to write a sorting function that accepts a pointer to the function that compares each pair of strings. Doing this will mean only passing a pointer to the sorting function with every new comparison strategy.
Given an array of strings, you need to implement a string_sort function which sorts the strings according to a comparison function, i.e, you need to implement the function :

void string_sort(const char **arr,const int cnt, int (*cmp_func)(const char* a, const char* b))
{
    
}

The arguments passed to this function are:
an array of strings: arr
length of string array: count
pointer to the string comparison function: cmp_func

You also need to implement the following four string comparison functions:
int lexicographic_sort(char*, char*) to sort the strings in lexicographically non-decreasing order.
int_lexicographic_sort_reverse(char*, char*) to sort the strings in lexicographically non-increasing order.
int sort_by_number_of_distinct_characters(char*, char*) to sort the strings in non-decreasing order of the number of distinct characters present in them. If two strings have the same number of distinct characters present in them, then the lexicographically smaller string should appear first.
int sort_by_length(char*, char*) to sort the strings in non-decreasing order of their lengths. If two strings have the same length, then the lexicographically smaller string should appear first.

Input Format
You just need to complete the function string\_sort and implement the four string comparison functions.

Constraints
1 <= No. of Strings <= 50
1 <= Total Length of all the strings <= 2500 
You have to write your own sorting function and you cannot use the inbuilt qsort function
The strings consists of lower-case English Alphabets only.

Output Format
The locked code-stub will check the logic of your code. The output consists of the strings sorted according to the four comparsion functions in the order mentioned in the problem statement.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) 
{
    int check  = 0  ;
    for (int i = 0 ; a[i]||b[i] ; i++)
    {
        if (a[i] !=b[i])
        {
            if (a[i] < b[i])
            {
                check = 0 ;
            }else {

            check = 1 ;
            }

            break;
        }
    }
    return check;
}

int lexicographic_sort_reverse(const char* a, const char* b) 
{
    int check  = 0  ;
    for (int i = 0 ; a[i]||b[i] ; i++ )
    {
        if (a[i] !=b[i])
        {
            if (a[i]< b[i])
            {
                check = 1 ;
            }else {

            check = 0 ;
            }

            break;
        }
    }
    return check;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) 
{
    int freq1 [26] = {0} ;
    int freq2 [26] = {0};
    int len1 = 0 ;
    int len2 = 0 ;
    for (int i = 0 ; a[i]; i++)
    {
        freq1[a[i]-'a'] ++ ;
    }
    for (int i = 0 ; b[i]; i++)
    {
        freq2[b[i]-'a'] ++ ;
    }
    for (int i = 0 ; i<26; i++)
    {
        if (freq1[i]!=0 )
            len1 ++ ;
    }
    for (int i = 0 ; i<26; i++)
    {
        if (freq2[i]!=0 )
            len2 ++ ;
    }
    if (len1 > len2)
    {
        return 1 ;
    }
    else if (len1 < len2)
    {
        return 0 ;
    }
    else
    {
        return lexicographic_sort(a,b);
    }
}

int sort_by_length(const char* a, const char* b) 
{
    int len1 = strlen(a);
    int len2 = strlen(b) ;
    if (len1 > len2)
    {
        return 1 ;
    }
    else if (len1 < len2)
    {
        return 0 ;
    }
    else
    {
        return lexicographic_sort(a,b);
    }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b))
{
    int i,j;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if(cmp_func(arr[j],arr[j+1])==1)        
            {
                char* temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
