/*
We say that a string contains the word hackerrank if a subsequence of its characters spell the word hackerrank. Remeber that a subsequence maintains the order of characters selected from a sequence.
More formally, let p[0],p[1]....,p[9] be the respective indices of h, a, c, k, e, r, r, a, n, k in string s if p[0] > p[1] < p[2] < ... < p[9] is true, then s contains hackerrank.
For each query, print YES on a new line if the string contains hackerrank, otherwise, print NO.

Function Description
Complete the hackerrankInString function in the editor below.
hackerrankInString has the following parameter(s):
string s: a string
Returns
- string: YES or NO

Input Format
The first line contains an integer q, the number of queries.
Each of the next q lines contains a single query string s.

Constraints
2 <= q <= 10^2
10 <= length of s <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'hackerrankInString' function below.
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string hackerrankInString(string s) 
{
    string temp = "hackerrank";
    if(s.length() >= temp.length())
    {
        for(int i=0;i<=s.length();i++)
        {
            if(temp.length() == 0)
            {
                break;
            }
            if(s[i] == temp[0])
            {
                temp = temp.substr(1);
            }
        }
    }
    if(temp.length() == 0)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
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

        string result = hackerrankInString(s);

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
