/*
You are the benevolent ruler of Rankhacker Castle, and today you're distributing bread. Your subjects are in a line, and some of them already have some loaves. Times are hard and your castle's food stocks are dwindling, so you must distribute as few loaves as possible according to the following rules:
Every time you give a loaf of bread to some person i, you must also give a loaf of bread to the person immediately in front of or behind them in the line (i.e., persons i+1 or i-1).
After all the bread is distributed, each person must have an even number of loaves.
Given the number of loaves already held by each citizen, find and print the minimum number of loaves you must distribute to satisfy the two rules above. If this is not possible, print NO.

Function Description
Complete the fairRations function in the editor below.
fairRations has the following parameter(s):
int B[N]: the numbers of loaves each persons starts with
Returns
- string: the minimum number of loaves required, cast as a string, or 'NO'

Input Format
The first line contains an integer N, the number of subjects in the bread line.
The second line contains N space-separated integers B[i].

Constraints
2 <= N <= 1000
1 <= B[i] <= 10, where 1 <= i <= n
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'fairRations' function below.
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY B as parameter.
 */

string fairRations(vector<int> B) {
    string ans;
    int temp = 0;
    for(int i=0;i<B.size()-1;i++)
    {
        if(B[i]%2!=0)
        {
            temp = temp + 2;
            B[i] = B[i] + 1;
            B[i+1] = B[i+1] + 1;
        }
    }
    if(B[B.size()-1]%2!=0)
    {
        ans = "NO";
    }
    else
    {
        ans = to_string(temp);   
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    string B_temp_temp;
    getline(cin, B_temp_temp);

    vector<string> B_temp = split(rtrim(B_temp_temp));

    vector<int> B(N);

    for (int i = 0; i < N; i++) {
        int B_item = stoi(B_temp[i]);

        B[i] = B_item;
    }

    string result = fairRations(B);

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
