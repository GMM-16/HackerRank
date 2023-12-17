/*
A space explorer's ship crashed on Mars! They send a series of SOS messages to Earth for help.
Letters in some of the SOS messages are altered by cosmic radiation during transmission. Given the signal received by Earth as a string, s, determine how many letters of the SOS message have been changed by radiation.

Function Description
Complete the marsExploration function in the editor below.
marsExploration has the following parameter(s):
string s: the string as received on Earth
Returns
- int: the number of letters changed during transmission

Input Format
There is one line of input: a single string, s.

Constraints
1 <= length of s <= 99
length of s modulo 3 = 0
s will contain only uppercase English letters, ascii[A-Z].
*/

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'marsExploration' function below.
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s) 
{
    int ans = 0;
    for(int i=0;i<s.length();i++)
    {
        if (i % 3 == 0 || i % 3 == 2)
        {
            if(s[i] != 'S')
            {
                ans = ans + 1;
            }
        }
        if(i % 3 == 1)
        {
            if(s[i] != 'O')
            {
                ans = ans + 1;
            }
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
