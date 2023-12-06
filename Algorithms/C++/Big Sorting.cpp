/*
Consider an array of numeric strings where each string is a positive number with anywhere from 1 to 10^6 digits. Sort the array's elements in non-decreasing, or ascending order of their integer values and return the sorted array.

Function Description
Complete the bigSorting function in the editor below.
bigSorting has the following parameter(s):
string unsorted[n]: an unsorted array of integers as strings
Returns
- string[n]: the array sorted in numerical order

Input Format
The first line contains an integer, n, the number of strings in unsorted.
Each of the n subsequent lines contains an integer string, unsorted[i].

Constraints
1 <= n <= 2*10^5
Each string is guaranteed to represent a positive integer.
There will be no leading zeros.
The total number of digits across all strings in unsorted is between 1 and 10^6 (inclusive).
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'bigSorting' function below.
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY unsorted as parameter.
 */

vector<string> bigSorting(vector<string> unsorted) 
{
     vector<string> ans = unsorted;
    sort(ans.begin(), ans.end(), [](string a, string b) 
    {
        return a.length() < b.length() || (a.length() == b.length() && a < b);
    });
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
