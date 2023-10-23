/*
We define P to be a permutation of the first n natural numbers in the range [1,n]. Let pos[i] denote the value at position i in permutation P using 1-based indexing.
P is considered to be an absolute permutation if |pos[i] - i| = k holds true for every 1 ∈ [1,n].
Given n and k, print the lexicographically smallest absolute permutation P. If no absolute permutation exists, print -1.

Function Description

Complete the absolutePermutation function in the editor below.

absolutePermutation has the following parameter(s):
int n: the upper bound of natural numbers to consider, inclusive
int k: the absolute difference between each element's value and its index
Returns
- int[n]: the lexicographically smallest permutation, or [-1] if there is none

Input Format
The first line contains an integer t, the number of queries.
Each of the next t lines contains 2 space-separated integers, n and k.

Constraints
1 <= t <= 10
1 <= n <= 10^5
0 <= k < n
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'absolutePermutation' function below.
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 */

vector<int> absolutePermutation(int n, int k) {
    vector<int> ans(n);
    vector<int> used(n+1, false);
    for (int i = 1; i <= n; ++i) 
    {
        if (i - k > 0 && !used[i - k]) 
        {
            ans[i - 1] = i - k;
            used[i - k] = true;
        }
        else if (i + k <= n && !used[i + k])       
        {
            ans[i - 1] = i + k;
            used[i + k] = true;
        }
        else 
        {
            return {-1};
        }
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

        int k = stoi(first_multiple_input[1]);

        vector<int> ans = absolutePermutation(n, k);

        for (size_t i = 0; i < ans.size(); i++) {
            fout << ans[i];

            if (i != ans.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
