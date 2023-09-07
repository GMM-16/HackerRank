/*
You have two strings of lowercase English letters. You can perform two types of operations on the first string:
Append a lowercase English letter to the end of the string.
Delete the last character of the string. Performing this operation on an empty string results in an empty string.
Given an integer, k, and two strings, s and t, determine whether or not you can convert s to t by performing exactly k of the above operations on s. If it's possible, print Yes. Otherwise, print No.

Function Description
Complete the appendAndDelete function in the editor below. It should return a string, either Yes or No.
appendAndDelete has the following parameter(s):
string s: the initial string
string t: the desired string
int k: the exact number of operations that must be performed
Returns
- string: either Yes or No

The first line contains a string s, the initial string.
The second line contains a string t, the desired final string.
The third line contains an integer k, the number of operations.

Constraints
1 <= |s| <= 100
1 <= |t| <= 100
1 <= k <= 100
s and t consist of lowercase English letter, ascii[a-z];
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'appendAndDelete' function below.
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 *  3. INTEGER k
 */

string appendAndDelete(string s, string t, int k) {
    int common = 0;
    string ans;
    while(common < s.length() && common < t.length() && s[common] == t[common])
    {
        common++;
    }
    int total = s.length()+t.length()-2*common;
    if(k >= s.length()+t.length() || k>=total && (k-total)%2==0 || k>=s.length()+t.length() && (k%2==0))
    {
        ans = "Yes";
    }
    else
    {
        ans = "No";
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = appendAndDelete(s, t, k);

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
