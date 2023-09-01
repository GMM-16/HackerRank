/*
Staircase detail
This is a staircase of size n=4
        #
      # #
    # # #
  # # # #
Its base and height are both equal to . It is drawn using # symbols and spaces. The last line is not preceded by any spaces.
Write a program that prints a staircase of size .

Function Description

Complete the staircase function in the editor below.
staircase has the following parameter(s):
int n: an integer
Print
- Print a staircase as described above.

Input Format
A single integer, n, denoting the size of the staircase.

Constraints
0 <= n <= 100
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void staircase(int n) {
    for(int i=1;i<n+1;i++)
    {
        cout<<string(n-i,' ');
        cout<<string(i,'#')<<endl;
        
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    staircase(n);

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
