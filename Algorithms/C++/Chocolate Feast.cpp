/*
Little Bobby loves chocolate. He frequently goes to his favorite 5 & 10 store, Penny Auntie, to buy them. They are having a promotion at Penny Auntie. If Bobby saves enough wrappers, he can turn them in for a free chocolate.

Function Description
Complete the chocolateFeast function in the editor below.
chocolateFeast has the following parameter(s):
int n: Bobby's initial amount of money
int c: the cost of a chocolate bar
int m: the number of wrappers he can turn in for a free bar
Returns
- int: the number of chocolates Bobby can eat after taking full advantage of the promotion
Note: Little Bobby will always turn in his wrappers if he has enough to get a free chocolate.

Input Format

The first line contains an integer, , the number of test cases to analyze.
Each of the next t lines contains three space-separated integers: n, c, and m. They represent money to spend, cost of a chocolate, and the number of wrappers he can turn in for a free chocolate.

Constraints
1 <= t <= 1000
2 <= n <= 10^5
1 <= c <= n
2 <= m <= n
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'chocolateFeast' function below.
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c
 *  3. INTEGER m
 */

int chocolateFeast(int n, int c, int m) {
    int choc = n / c;
    int wrap = choc;
    int ans = choc;
    while(wrap >= m)
    {
        int free = wrap / m;
        wrap = wrap % m + free;
        ans = ans + free;
    }    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int c = stoi(first_multiple_input[1]);

        int m = stoi(first_multiple_input[2]);

        int result = chocolateFeast(n, c, m);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
