/*
Given a set of distinct integers, print the size of a maximal subset of S where the sum of any 2 numbers in S' is not evenly divisible by k.

Function Description
Complete the nonDivisibleSubset function in the editor below.
nonDivisibleSubset has the following parameter(s):
int S[n]: an array of integers
int k: the divisor
Returns
- int: the length of the longest subset of S meeting the criteria

Input Format
The first line contains 2 space-separated integers, n and k, the number of values in S and the non factor.
The second line contains n space-separated integers, each an S[i], the unique values of the set.

Constraints
1 <= n <= 10^5
1 <= k <= 100
1 <= S[i] <= 10^9
All of the given numbers are distinct.
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

int nonDivisibleSubset(int k, vector<int> s) {
     vector <int> remainder (k, 0);
    for (int i = 0; i < s.size(); i++)
    {
        remainder[s[i]%k] ++;
    }
    int subset_size = 0;
    subset_size = (remainder[0] != 0);
    for (int i = 1; 2*i <= k; i++)
    {
        int j = (k - i);
        if(j == i)
        {
            subset_size += min (1, remainder[j]);
        }
        else
        {
            subset_size += max (remainder[i], remainder[j]);
        } 
    }
    return subset_size;     
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

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
