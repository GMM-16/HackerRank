/*
You are given n triangles, specifically, their sides ai, bi and ci. Print them in the same style but sorted by their areas from the smallest one to the largest one. It is guaranteed that all the areas are different.
The best way to calculate a area of a triangle with sides a, b and c is Heron's formula:
S = √(p * (p - a) * (p - b) * (p - c)) where p = (a + b + c) / 2

Input Format
The first line of each test file contains a single integer n. n lines follow with three space-separated integers, ai, bi and ci.

Constraints
1 <= n <= 100
1 <= ai,bi,ci <= 70
ai + bi > ci and ai + ci > bi and bi + ci > ai

Output Format
Print exactly n lines. On each line print 3 space-separated integers, the ai, bi and ci of the corresponding triangle.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    double arr[n],temp;
    double p;
    triangle temp1;
    for (int i=0; i<n; i++) 
    {
        p = (tr[i].a+tr[i].b+tr[i].c)/2.0;
        arr[i] = sqrt(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));
    }
    for (int i =0; i<n; i++) 
    {
        for (int j = i+1; j<n; j++) 
        {
            if (arr[i]>arr[j])
            {
                temp = arr[j];
                arr[j]= arr[i];
                arr[i] = temp;
                temp1 = tr[j];
                tr[j] = tr[i];
                tr[i] = temp1;  
            } 
        }
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
