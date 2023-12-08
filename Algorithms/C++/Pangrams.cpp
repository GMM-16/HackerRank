/*
A pangram is a string that contains every letter of the alphabet. Given a sentence determine whether it is a pangram in the English alphabet. Ignore case. Return either pangram or not pangram as appropriate.

Function Description
Complete the function pangrams in the editor below. It should return the string pangram if the input string is a pangram. Otherwise, it should return not pangram.
pangrams has the following parameter(s):
string s: a string to test
Returns
- string: either pangram or not pangram

Input Format
A single line with string s.

Constraints
0 < length of s <= 10^3
Each character of s, s[i] ∈ {a-z,A-Z,space}
*/

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'pangrams' function below.
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) 
{
    string ans = "pangram";
    vector<int> temp(26,0);
    for(int i =0;i <s.size();i++)
    {
        if(s[i] != ' ')
        {
            temp[tolower(s[i]) - 'a']++;
        }
    }
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i] == 0)
        {
            ans = "not pangram";
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
