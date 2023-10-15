/*
There is a strange counter. At the first second, it displays the number 3. Each second, the number displayed by decrements by 1 until it reaches 1. In next second, the timer resets to 2 * the initial number for the prior cycle and continues counting down.
Find and print the value displayed by the counter at time t.

Function Description
Complete the strangeCounter function in the editor below.
strangeCounter has the following parameter(s):
int t: an integer
Returns
- int: the value displayed at time t

Input Format
A single integer, the value of t.

Constraints
1 <= t <= 10^12
Subtask
1 <= t <= 10^5 for 60% of the maximum score
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'strangeCounter' function below.
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER t as parameter.
 */

long strangeCounter(long t) {
    long ans = 3;
    long start = 3;
    while(t > ans)
    {
        start = start * 2;
        ans = ans + start;
    }
    ans = ans - t + 1;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    long t = stol(ltrim(rtrim(t_temp)));

    long result = strangeCounter(t);

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
