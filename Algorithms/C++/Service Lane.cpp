/*
A driver is driving on the freeway. The check engine light of his vehicle is on, and the driver wants to get service immediately. Luckily, a service lane runs parallel to the highway. It varies in width along its length.
You will be given an array of widths at points along the road (indices), then a list of the indices of entry and exit points. Considering each entry and exit point pair, calculate the maximum size vehicle that can travel that segment of the service lane safely.

Function Description
Complete the serviceLane function in the editor below.
serviceLane has the following parameter(s):
int n: the size of the width array
int cases[t][2]: each element contains the starting and ending indices for a segment to consider, inclusive
Returns
- int[t]: the maximum width vehicle that can pass through each segment of the service lane described

Input Format
The first line of input contains two integers, n and t, where n denotes the number of width measurements and t, the number of test cases. The next line has n space-separated integers which represent the array width.
The next t lines contain two integers, i and j, where i is the start index and j is the end index of the segment to check.

Constraints
2 <= n <= 100000
1 <= t <= 1000
0 <= i < j < n
2 <= j - i + 1 <= min(n,1000)
1 <= width(k) <= 3, where 0 <= k < n
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'serviceLane' function below.
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY cases
 */

vector<int> serviceLane(int n, vector<vector<int>> cases,vector<int> width) {
    vector<int> results;

    for (int i = 0; i < cases.size(); i++) {
        int entry = cases[i][0];
        int exit = cases[i][1];

        int min_width = INT_MAX;

        for (int j = entry; j <= exit; j++) {
            min_width = min(min_width, width[j]);
        }

        results.push_back(min_width);
    }

    return results;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int t = stoi(first_multiple_input[1]);

    string width_temp_temp;
    getline(cin, width_temp_temp);

    vector<string> width_temp = split(rtrim(width_temp_temp));

    vector<int> width(n);

    for (int i = 0; i < n; i++) {
        int width_item = stoi(width_temp[i]);

        width[i] = width_item;
    }

    vector<vector<int>> cases(t);

    for (int i = 0; i < t; i++) {
        cases[i].resize(2);

        string cases_row_temp_temp;
        getline(cin, cases_row_temp_temp);

        vector<string> cases_row_temp = split(rtrim(cases_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int cases_row_item = stoi(cases_row_temp[j]);

            cases[i][j] = cases_row_item;
        }
    }

    vector<int> result = serviceLane(n, cases, width);

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
