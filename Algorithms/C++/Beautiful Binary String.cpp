/*
Alice has a binary string. She thinks a binary string is beautiful if and only if it doesn't contain the substring "010".
In one step, Alice can change a 0 to a 1 or vice versa. Count and print the minimum number of steps needed to make Alice see the string as beautiful.

Function Description
Complete the beautifulBinaryString function in the editor below.
beautifulBinaryString has the following parameter(s):
string b: a string of binary digits
Returns
- int: the minimum moves required

Input Format
The first line contains an integer n, the length of binary string.
The second line contains a single binary string b.

Constraints
1 <= n <= 100
b[i] ∈ {0,1}

Output Format
Print the minimum number of steps needed to make the string beautiful.
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'beautifulBinaryString' function below.
 * The function is expected to return an INTEGER.
 * The function accepts STRING b as parameter.
 */

int beautifulBinaryString(string b) 
{
    int ans = 0;
    for(int i=0;i<b.length()-2;i++)
    {
        if(b[i] == '0' && b[i+1] == '1' && b[i+2] == '0')
        {
            ans = ans + 1;
            i = i + 2;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

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
