/*
Happy Ladybugs is a board game having the following properties:
The board is represented by a string, b, of length . The ith character of the string, b[i], denotes the  cell of the board.
If b[i] is an underscore (i.e., _), it means the  cell of the board is empty.
If b[i] is an uppercase English alphabetic letter (ascii[A-Z]), it means the ith cell contains a ladybug of color b[i].
String b will not contain any other characters.
A ladybug is happy only when its left or right adjacent cell (i.e., b[i±1]) is occupied by another ladybug having the same color.
In a single move, you can move a ladybug from its current position to any empty cell.
Given the values of n and b for g games of Happy Ladybugs, determine if it's possible to make all the ladybugs happy. For each game, return YES if all the ladybugs can be made happy through some number of moves. Otherwise, return NO.

Function Description
Complete the happyLadybugs function in the editor below.
happyLadybugs has the following parameters:
string b: the initial positions and colors of the ladybugs
Returns
- string: either YES or NO

Input Format
The first line contains an integer g, the number of games.
The next g pairs of lines are in the following format:
The first line contains an integer n, the number of cells on the board.
The second line contains a string b that describes the n cells of the board.

Constraints
1 <= g,n <= 100
b[i] ∈ {_,ascii[A - Z]}
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'happyLadybugs' function below.
 * The function is expected to return a STRING.
 * The function accepts STRING b as parameter.
 */

string happyLadybugs(string b) {
    vector<int> count(26,0);
    bool empty = false;
    for(int i=0;i<b.size();i++)
    {
        char c = b[i];
        if(c != '_')
        {
            count[c-'A'] = count[c-'A'] + 1;
        }
        else
        {
            empty = true;
        }
    }
    bool happy = true;
    for(int i=0;i<b.size();i++)
    {
        if(b[i]!='_' && (i==0 || b[i] != b[i-1]) && (i == b.size() - 1 || b[i] != b[i + 1]))
        {
            happy = false;
            break;
        }
    }
    if(happy)
    {
        return "YES";
    }
    for(int i=0;i<26;i++)
    {
        if(count[i]==1)
        {
            return "NO";
        }
    }
    if(empty)
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

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

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
