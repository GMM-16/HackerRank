/*
Dothraki are planning an attack to usurp King Robert's throne. King Robert learns of this conspiracy from Raven and plans to lock the single door through which the enemy can enter his kingdom.
But, to lock the door he needs a key that is an anagram of a palindrome. He starts to go through his box of strings, checking to see if they can be rearranged into a palindrome. Given a string, determine if it can be rearranged into a palindrome. Return the string YES or NO.

Function Description
Complete the gameOfThrones function below.
gameOfThrones has the following parameter(s):
string s: a string to analyze
Returns
- string: either YES or NO

Input Format
A single line which contains s.

Constraints
1 <= |s| <= 10^5
s contains only lowercase letters in the range ascii[a.....z]
*/

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s) 
{
    unordered_set<char> temp;
    int flag = 0;
    for (int i = 0; i < s.length(); ++i) 
    {
        temp.insert(s[i]);
    }
    for (char i : temp) 
    {
        if (count(s.begin(), s.end(), i) % 2 == 1) {
            flag = flag + 1;
        }
    }
    if (flag > 1) 
    {
        return "NO";
    } 
    else 
    {
        return "YES";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
