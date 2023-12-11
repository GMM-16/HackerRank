/*
Priyanka works for an international toy company that ships by container. Her task is to the determine the lowest cost way to combine her orders for shipping. She has a list of item weights. The shipping company has a requirement that all items loaded in a container must weigh less than or equal to 4 units plus the weight of the minimum weight item. All items meeting that requirement will be shipped in one container.
What is the smallest number of containers that can be contracted to ship the items based on the given list of weights?

Function Description
Complete the toys function in the editor below. It should return the minimum number of containers required to ship.
toys has the following parameter(s):
w: an array of integers that represent the weights of each order to ship

Input Format
The first line contains an integer n, the number of orders to ship.
The next line contains n space-separated integers, w[1],w[2],.....,w[n], representing the orders in a weight array.

Constraints
1 <= n <= 10^5
0 <= w[i] <= 10^4, where i ∈ [1,n]

Output Format
Return the integer value of the number of containers Priyanka must contract to ship all of the toys.
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'toys' function below.
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY w as parameter.
 */

int toys(vector<int> w) 
{
    int i = 0;
    int ans = 1;
    int temp = 0;
    int start = w[0];
    int end = start + 4;
    sort(w.begin(),w.end());
    while(i<w.size())
    {
        if(start <= w[i] && w[i] <= end)
        {
            i = i + 1;
            temp = temp + 1;
        }
        else
        {
            if(temp > 0)
            {
                ans = ans + 1;
            }
            temp = 0;
            start = w[i];
            end = start + 4;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string w_temp_temp;
    getline(cin, w_temp_temp);

    vector<string> w_temp = split(rtrim(w_temp_temp));

    vector<int> w(n);

    for (int i = 0; i < n; i++) {
        int w_item = stoi(w_temp[i]);

        w[i] = w_item;
    }

    int result = toys(w);

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
