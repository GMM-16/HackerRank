/*
Lexicographical order is often known as alphabetical order when dealing with strings. A string is greater than another string if it comes later in a lexicographically sorted list.
Given a word, create a new word by swapping some or all of its characters. This new word must meet two criteria:
It must be greater than the original word
It must be the smallest word that meets the first condition

Function Description
Complete the biggerIsGreater function in the editor below.
biggerIsGreater has the following parameter(s):
string w: a word
Returns
- string: the smallest lexicographically higher string possible or no answer

Input Format
The first line of input contains T, the number of test cases.
Each of the next T lines contains w.

Constraints
1 <= T <= 10^5
1 <= lengthofw <= 100
w will contain only letters in the range ascii[a...z]
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'biggerIsGreater' function below.
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */

string biggerIsGreater(string w) {
    int i = w.length() - 2;
    while (i >= 0 && w[i] >= w[i + 1]) {
        i--;
    }
    if (i == -1) {
        return "no answer";
    }
    int j = w.length() - 1;
    while (w[j] <= w[i]) {
        j--;
    }
    std::swap(w[i], w[j]);
    std::reverse(w.begin() + i + 1, w.end());
    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

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
