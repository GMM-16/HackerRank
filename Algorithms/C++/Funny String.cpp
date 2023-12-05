/*
In this challenge, you will determine whether a string is funny or not. To determine whether a string is funny, create a copy of the string in reverse e.g. abc -> cba. Iterating through each string, compare the absolute difference in the ascii values of the characters at positions 0 and 1, 1 and 2 and so on to the end. If the list of absolute differences is the same for both strings, they are funny.
Determine whether a give string is funny. If it is, return Funny, otherwise return Not Funny.

Function Description
Complete the funnyString function in the editor below.
funnyString has the following parameter(s):
string s: a string to test
Returns
- string: either Funny or Not Funny

Input Format
The first line contains an integer q, the number of queries.
The next q lines each contain a string, s.

Constraints
1 <= q <= 10
2 <= length of s <= 10000
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'funnyString' function below.
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string funnyString(string s) 
{
    string r = s;
    reverse(r.begin(), r.end());
    for(int i = 1; i < s.size(); i++)
    {
        if(abs(s[i]-s[i-1]) != abs(r[i]- r[i-1]))
        {
            return "Not Funny";
        }
    }
    return "Funny";
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

        string result = funnyString(s);

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
