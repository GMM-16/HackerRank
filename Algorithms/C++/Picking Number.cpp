/*
Given an array of integers, find the longest subarray where the absolute difference between any two elements is less than or equal to 1.

Function Description
Complete the pickingNumbers function in the editor below.
pickingNumbers has the following parameter(s):
int a[n]: an array of integers
Returns
- int: the length of the longest subarray that meets the criterion

Input Format
The first line contains a single integer n, the size of the array .
The second line contains n space-separated integers, each an a[i].

Constraints
2 <= n <= 100
0 < a[i] < 100
The answer will always be >= 2.
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {
    int size = a.size();
    int ans = 0;
    for(int i=0;i<size;i++)
    {
        int count = 0;
        for(int j=0;j<size;j++)
        {
            if(a[j] == a[i] || a[j] == a[i]+1)
            {
                count++;
            }
        }
        ans = max(ans,count);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = pickingNumbers(a);

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
