/*
There is a string, s, of lowercase English letters that is repeated infinitely many times. Given an integer, n, find and print the number of letter a's in the first n letters of the infinite string.

Function Description
Complete the repeatedString function in the editor below.
repeatedString has the following parameter(s):
s: a string to repeat
n: the number of characters to consider
Returns
- int: the frequency of a in the substring

Input Format
The first line contains a single string, s.
The second line contains an integer, n.

Constraints
1 <= |s| <= 100
1 <= n <= 10^12
For 25% of test cases, n <= 10^6
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long repeatedString(string s, long n) {
    long count = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='a')
        {
            count++;
        }
    }
    long ans = n / s.length();
    ans = ans * count;
    long temp = n % s.length();
    for(int i=0;i<temp;i++)
    {
        if(s[i]=='a')
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

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
