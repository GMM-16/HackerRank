/*
A weighted string is a string of lowercase English letters where each letter has a weight. Character weights are 1 to 26 from a to z.
The weight of a string is the sum of the weights of its characters.
A uniform string consists of a single character repeated zero or more times.
Given a string, s, let U be the set of weights for all possible uniform contiguous substrings of string s. There will be n queries to answer where each query consists of a single integer. Create a return array where for each query, the value is Yes if query[i] ∈ U. Otherwise, append No.
Note: The ∈ symbol denotes that x[i] is an element of set U.

Function Description
Complete the weightedUniformStrings function in the editor below.
weightedUniformStrings has the following parameter(s):
- string s: a string
- int queries[n]: an array of integers
Returns
- string[n]: an array of strings that answer the queries

Input Format
The first line contains a string s, the original string.
The second line contains an integer n, the number of queries.
Each of the next n lines contains an integer queries[i], the weight of a uniform subtring of  that may or may not exist.

Constraints
1 <= lenghofs, n <= 10^5
1 <= queries[i] <= 10^7
s will only contain lowercase English letters, ascii[a-z].
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'weightedUniformStrings' function below.
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY queries
 */

vector<string> weightedUniformStrings(string s, vector<int> queries) 
{
    vector<int> temp;
    vector<string> ans;
    for (int i = 0; i < s.length(); i++) 
    {
        int wt = s[i] - 'a' + 1;
        if (i == 0 || s[i] != s[i - 1]) 
        {
            temp.push_back(wt);
        } 
        else 
        {
            temp.push_back(wt + temp[i - 1]);
        }
    }
    unordered_set<int> tempSet(temp.begin(), temp.end());
    for (int q : queries) 
    {
        if (tempSet.count(q) > 0) 
        {
            ans.push_back("Yes");
        } 
        else 
        {
            ans.push_back("No");
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

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
