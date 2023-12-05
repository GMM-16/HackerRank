/*
Reduce a string of lowercase characters in range ascii[‘a’..’z’]by doing a series of operations. In each operation, select a pair of adjacent letters that match, and delete them.
Delete as many characters as possible using this method and return the resulting string. If the final string is empty, return Empty String

Function Description
Complete the superReducedString function in the editor below.
superReducedString has the following parameter(s):
string s: a string to reduce
Returns
- string: the reduced string or Empty String

Input Format
A single string, s.

Constraints
1 <= length of s <= 100
*/

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'superReducedString' function below.
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) 
{
    for(int i=1;i<s.size();i=i)
    {
        if(s[i] == s[i-1])
        {
            s.erase(i-1,2);
            i = 1;
        }
        else
        {
            i++;
        }
    }
    if(s.empty())
    {
        return "Empty String";
    }
    else
    {
        return s;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
