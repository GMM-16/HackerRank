/*
Given an array, of size n, reverse it.

Input Format
The first line contains an integer, n, denoting the size of the array. The next line contains n space-separated integers denoting the elements of the array.

Constraints
1 <= n <= 1000
1 <= arri <= 1000 where arri is the ith element of the array

Output Format
The output is handled by the code given in the editor, which would print the array.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }
    /* Write the logic to reverse the array. */
    int start=0,temp=0,end=0;
    end = num - 1;
    while(end>start)
    {
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    for(i = 0; i < num; i++)
    {
        printf("%d ", *(arr + i));
    }
    return 0;
}
