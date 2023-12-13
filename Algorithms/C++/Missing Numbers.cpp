/*
Given two arrays of integers, find which elements in the second array are missing from the first array.

Notes
If a number occurs multiple times in the lists, you must ensure that the frequency of that number in both lists is the same. If that is not the case, then it is also a missing number.
Return the missing numbers sorted ascending.
Only include a missing number once, even if it is missing multiple times.
The difference between the maximum and minimum numbers in the original list is less than or equal to 100.

Function Description
Complete the missingNumbers function in the editor below. It should return a sorted array of missing numbers.
missingNumbers has the following parameter(s):
int arr[n]: the array with missing numbers
int brr[m]: the original array of numbers
Returns
- int[]: an array of integers

Input Format
There will be four lines of input:
n - the size of the first list, arr
The next line contains n space-separated integers arr[i]
m - the size of the second list, brr
The next line contains m space-separated integers brr[i]

Constraints
1 <= n,m <= 2*10^5
n <= m
1 <= brr[i] <= 10^4
max(brr) - min(brr) <= 100
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'missingNumbers' function below.
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY brr
 */

vector<int> missingNumbers(vector<int> arr, vector<int> brr) 
{
    int i = 0, j = 0;
    vector<int> ans;
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    while (i < arr.size() && j < brr.size()) 
    {
        if (arr[i] == brr[j]) 
        {
            i++;
            j++;
        } 
        else 
        {
            if (find(ans.begin(), ans.end(), brr[j]) == ans.end()) 
            {
                ans.push_back(brr[j]);
            }
            j++;
        }
    }
    while (j < brr.size()) 
    {
        if (find(ans.begin(), ans.end(), brr[j]) == ans.end()) 
        {
            ans.push_back(brr[j]);
        }
        j++;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    vector<int> result = missingNumbers(arr, brr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
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
