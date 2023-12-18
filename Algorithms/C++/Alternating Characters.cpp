/*
You are given a string containing characters A and B only. Your task is to change it into a string such that there are no matching adjacent characters. To do this, you are allowed to delete zero or more characters in the string.
Your task is to find the minimum number of required deletions.

Function Description
Complete the alternatingCharacters function in the editor below.
alternatingCharacters has the following parameter(s):
string s: a string
Returns
- int: the minimum number of deletions required

Input Format
The first line contains an integer q, the number of queries.
The next q lines each contain a string s to analyze.

Constraints
1 <= q <= 10
1 <= length of s <= 10^5
Each string s will consist only of characters A and B.
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternatingCharacters' function below.
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int alternatingCharacters(string s) 
{
    int ans = 0;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]==s[i-1])
        {
            ans = ans + 1;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

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
