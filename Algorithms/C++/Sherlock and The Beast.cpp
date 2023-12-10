/*
Sherlock Holmes suspects his archenemy Professor Moriarty is once again plotting something diabolical. Sherlock's companion, Dr. Watson, suggests Moriarty may be responsible for MI6's recent issues with their supercomputer, The Beast.
Shortly after resolving to investigate, Sherlock receives a note from Moriarty boasting about infecting The Beast with a virus. He also gives him a clue: an integer. Sherlock determines the key to removing the virus is to find the largest Decent Number having that number of digits.
A Decent Number has the following properties:
Its digits can only be 3's and/or 5's.
The number of 3's it contains is divisible by 5.
The number of 5's it contains is divisible by 3.
It is the largest such number for its length.
Moriarty's virus shows a clock counting down to The Beast's destruction, and time is running out fast. Your task is to help Sherlock find the key before The Beast is destroyed!

Function Description
Complete the decentNumber function in the editor below.
decentNumber has the following parameter(s):
int n: the length of the decent number to create
Prints
Print the decent number for the given length, or -1 if a decent number of that length cannot be formed. No return value is expected.

Input Format
The first line is an integer, t, the number of test cases.
The next t lines each contain an integer n, the number of digits in the number to create.

Constraints
1 <= t <= 20
1 <= n <= 100000
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'decentNumber' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void decentNumber(int n) 
{
    int temp = n;
    while (temp % 3 != 0 || (n - temp) % 5 != 0)
    {
        temp -= 5;
        if (temp < 0)
        {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < temp; i++)
    {
        cout << "5";
    }
    
    for (int i = 0; i < (n - temp); i++)
    {
        cout << "3";
    }
    cout << "\n";
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        decentNumber(n);
    }

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
