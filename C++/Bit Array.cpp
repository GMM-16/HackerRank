/*
You are given four integers: N, S, P, Q. You will use them in order to create the sequence a with the following pseudo-code.

a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31)
    
Your task is to calculate the number of distinct integers in the sequence a.

Input Format
Four space separated integers on a single line, N, S, P, and Q respectively.

Output Format
A single integer that denotes the number of distinct integers in the sequence a.

Constraints
1 <= N <= 10^8
0 <= S, P, Q < 2^31
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
    int n, s, p, q;
    cin >> n >> s >> p >> q;
    int64_t m = 1u << 31;
    int64_t prev = s;
    int64_t tmp;
    int res = 1;

    for(int i = 1; i < n; i++) 
    {
        tmp = (prev * p + q) % m;
        if(tmp == prev) 
        {
            break;
        }
        prev = tmp;
        res++;
    }
    cout << res << endl;
    return 0;
}
