/*
Given two integers, l and r, find the maximal value of a xor b, written a ⊕ b, where a and b satisfy the following condition:
l <= a <= b <= r

Function Description
Complete the maximizingXor function in the editor below. It must return an integer representing the maximum value calculated.
maximizingXor has the following parameter(s):
l: an integer, the lower bound, inclusive
r: an integer, the upper bound, inclusive

Input Format
The first line contains the integer l.
The second line contains the integer r.

Constraints
1 <= l <= r <= 10^3

Output Format
Return the maximal value of the xor operations for all permutations of the integers from l to r, inclusive.
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'maximizingXor' function below.
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */

int maximizingXor(int l, int r) 
{
    vector<int> ans;
    for(int i=l;i<=r;i++)
    {
        for(int j=i;j<=r;j++)
        {
            ans.push_back(i ^ j);
        }
    }
    return *max_element(ans.begin(),ans.end());
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string r_temp;
    getline(cin, r_temp);

    int r = stoi(ltrim(rtrim(r_temp)));

    int result = maximizingXor(l, r);

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
