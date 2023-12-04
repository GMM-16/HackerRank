/*
Given a string, remove characters until the string is made up of any two alternating characters. When you choose a character to remove, all instances of that character must be removed. Determine the longest string possible that contains just two alternating letters.

Function Description
Complete the alternate function in the editor below.
alternate has the following parameter(s):
string s: a string
Returns.
- int: the length of the longest valid string, or  if there are none

Input Format
The first line contains a single integer that denotes the length of s.
The second line contains string s.

Constraints
1 <= length of s <= 1000
s[i] ∈ ascii[a-z]
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int alternate(string s) 
{
    int count = 0;
    for (int i = 0; i < 26; i++) 
    {
        for (int j = i + 1; j < 26; j++) 
        {
            char a = 'a' + i;
            char b = 'a' + j;
            char last_char = '\0';
            int str_count = 0;
            bool flag = true;
            for (char &c : s) 
            {
                if (c == a || c == b) 
                {
                    if (last_char == '\0' || c != last_char) 
                    {
                        last_char = c;
                        str_count++;
                    } 
                    else 
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag && str_count > 1) 
            {
                count = max(count, str_count);
            }
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

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
