/*
Given a string of lowercase letters in the range ascii[a-z], determine the index of a character that can be removed to make the string a palindrome. There may be more than one solution, but any will do. If the word is already a palindrome or there is no solution, return -1. Otherwise, return the index of a character to remove.

Function Description
Complete the palindromeIndex function in the editor below.
palindromeIndex has the following parameter(s):
string s: a string to analyze
Returns
- int: the index of the character to remove or 

Input Format
The first line contains an integer q, the number of queries.
Each of the next q lines contains a query string s.

Constraints
1 <= q <= 20
1 <= length of s <= 10^5 + 5
All characters are in the range ascii[a-z].
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'palindromeIndex' function below.
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int palindromeIndex(string s) 
{
    if (s == std::string(s.rbegin(), s.rend())) 
    {
        return -1;
    }

    for (int x = 0; x < s.length() / 2; ++x) 
    {
        if (s[x] != s[s.length() - 1 - x]) 
        {
            std::string new_string1 = s.substr(0, x) + s.substr(x + 1);
            std::string new_string2 = s.substr(0, s.length() - 1 - x) + s.substr(s.length() - x);

            if (new_string1 == std::string(new_string1.rbegin(), new_string1.rend())) 
            {
                return x;
            } else if (new_string2 == std::string(new_string2.rbegin(), new_string2.rend())) 
            {
                return s.length() - 1 - x;
            }
        }
    }
    return -1;
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

        int result = palindromeIndex(s);

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
