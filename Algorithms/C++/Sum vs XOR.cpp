/*
Given an integer n, find each x such that:
0 <= x <= n
n + x = n ⊕ x
where ⊕ denotes the bitwise XOR operator. Return the number of x's satisfying the criteria.

Function Description
Complete the sumXor function in the editor below.
sumXor has the following parameter(s):
- int n: an integer
Returns
- int: the number of values found

Input Format
A single integer, n.

Constraints
0 <= n <= 10^15

Subtasks
0 <= n <= 100 for 60% of the maximum score.
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sumXor' function below.
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

long sumXor(long n) 
{
    long ans = 0;
    while(n>0)
    {
        if(n%2==0)
        {
            ans = ans + 1;
        }
        n = floor(n/2);
    }
    return pow(2,ans);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = sumXor(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
