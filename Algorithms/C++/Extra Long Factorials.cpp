/*
The factorial of the integer n, written n! is defined as:
n! = n * (n-1) * (n-2) * ..... * 3 * 2 * 1
Calculate and print the factorial of a given integer.

Function Description
Complete the extraLongFactorials function in the editor below. It should print the result and return.
extraLongFactorials has the following parameter(s):
- n: an integer
Note: Factorials of n>20 can't be stored even in a 64-bit long long variable. Big integers must be used for such calculations. Languages like Java, Python, Ruby etc. can handle big integers, but we need to write additional code in C/C++ to handle huge values.
We recommend solving this challenge using BigIntegers.

Input Format
Input consists of a single integer n

Constraints
1 <= n <= 100

Output Format
Print the factorial of n.
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 * The function accepts INTEGER n as parameter.
 */

void extraLongFactorials(int n) {
    vector<int> result(1, 1);
    for (int i = 2; i <= n; ++i) {
        int carry = 0;
        for (int j = 0; j < result.size(); ++j) {
            int product = result[j] * i + carry;
            result[j] = product % 10;
            carry = product / 10;
        }
        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    for (int i = result.size() - 1; i >= 0; --i) {
        cout << result[i];
    }
    cout << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

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
