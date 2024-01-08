/*
You are given N integers in sorted order. Also, you are given Q queries. In each query, you will be given an integer and you have to tell whether that integer is present in the array. If so, you have to tell at which index it is present and if it is not present, you have to tell the index at which the smallest integer that is just greater than the given number is present.
Lower bound is a function that can be used with a sorted vector. Learn how to use lower bound to solve this problem by clicking here.

Input Format
The first line of the input contains the number of integers N. The next line contains N integers in sorted order. The next line contains Q, the number of queries. Then Q lines follow each containing a single integer Y.
Note: If the same number is present multiple times, you have to print the first index at which it occurs. Also, the input is such that you always have an answer for each query.

Constraints
1 <= N <= 10^5
1 <= Xi <= 10^9, wherre Xi is ith element in the array
1 <= Q <= 10^5
1 <= Y <= 10^9

Output Format
For each query you have to print "Yes" (without the quotes) if the number is present and at which index(1-based) it is present separated by a space.
If the number is not present you have to print "No" (without the quotes) followed by the index of the next smallest number just greater than that number.
You have to output each query in a new line.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int temp;
    int arraySize = 0;
    cin >> arraySize;
    vector<int> arr (arraySize);
    for(int i = 0; i < arraySize; i++)
    {
        cin >> arr[i];
    }
    int queryCount = 0;
    cin >> queryCount;
    vector<int>::iterator low;
    for(int i = 0; i < queryCount; i++) 
    {
        cin >> temp;
        low=lower_bound (arr.begin(), arr.end(), temp);
        int a = low - arr.begin();
        if (arr[a] == temp)
        {
            cout << "Yes " << a + 1 << endl;
        }
        else  
        {
            cout << "No " << a + 1 << endl;    
        }
    }
    return 0;
}
