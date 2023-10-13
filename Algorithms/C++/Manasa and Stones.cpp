/*
Manasa is out on a hike with friends. She finds a trail of stones with numbers on them. She starts following the trail and notices that any two consecutive stones' numbers differ by one of two values. Legend has it that there is a treasure trove at the end of the trail. If Manasa can guess the value of the last stone, the treasure will be hers.

Function Description
Complete the stones function in the editor below.
stones has the following parameter(s):
int n: the number of non-zero stones
int a: one possible integer difference
int b: another possible integer difference
Returns
- int[]: all possible values of the last stone, sorted ascending

Input Format
The first line contains an integer T, the number of test cases.
Each test case contains 3 lines:
- The first line contains n, the number of non-zero stones found.
- The second line contains a, one possible difference
- The third line contains b, the other possible difference.

Constraints
1 <= T <= 10
1 <= n,a,b <= 10^3
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'stones' function below.
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER a
 *  3. INTEGER b
 */

vector<int> stones(int n, int a, int b) {
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        int stone = i * a + (n - 1 - i) * b;
        ans.push_back(stone);
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string a_temp;
        getline(cin, a_temp);

        int a = stoi(ltrim(rtrim(a_temp)));

        string b_temp;
        getline(cin, b_temp);

        int b = stoi(ltrim(rtrim(b_temp)));

        vector<int> result = stones(n, a, b);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
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
