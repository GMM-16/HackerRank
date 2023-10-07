/*
An English text needs to be encrypted using the following encryption scheme.
First, the spaces are removed from the text. Let L be the length of this text.
Then, characters are written into a grid, whose rows and columns have the following constraints:
[√L] <= row <= column <= [√L], where [x] is floor function and [x] is ceil function

Function Description
Complete the encryption function in the editor below.
encryption has the following parameter(s):
string s: a string to encrypt
Returns
- string: the encrypted string

Input Format
One line of text, the string s

Constraints
1 <= length of s <= 81
s contains characters in the range ascii[a-z] and space, ascii(32)
*/

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'encryption' function below.
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    int size = s.length();
    int n = ceil(sqrt(size));
    string ans = "";
    for (int i = 0; i < n; ++i) {
        ans += ' ';
        int j = i;
        while (j < size) {
            ans += s[j];
            j += n;
        }
    }
    ans = ans.substr(1);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
