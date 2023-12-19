/*
Jim's Burgers has a line of hungry customers. Orders vary in the time it takes to prepare them. Determine the order the customers receive their orders. Start by numbering each of the customers from 1 to n, front of the line to the back. You will then be given an order number and a preparation time for each customer.
The time of delivery is calculated as the sum of the order number and the preparation time. If two orders are delivered at the same time, assume they are delivered in ascending customer number order.

Function Description
Complete the jimOrders function in the editor below. It should return an array of integers that represent the order that customers' orders are delivered.
jimOrders has the following parameter(s):
orders: a 2D integer array where each orders[i] is in the form [orders[i],prep[i]].

Input Format
The first line contains an integer n, the number of customers.
Each of the next n lines contains two space-separated integers, an order number and prep time for customer[i].

Constraints
1 <= n <= 10^3
1 <= i <= n
1 <= order[i],prep[i] <= 10^6

Output Format
Print a single line of n space-separated customer numbers (recall that customers are numbered from 1 to n) that describes the sequence in which the customers receive their burgers. If two or more customers receive their burgers at the same time, print their numbers in ascending order.
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'jimOrders' function below.
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY orders as parameter.
 */

vector<int> jimOrders(vector<vector<int>> orders) 
{
    vector<int> ans;
    vector<pair<int,int>> temp;
    for(int i=0;i<orders.size();i++)
    {
        temp.push_back({orders[i][0]+orders[i][1],i+1});
    }
    sort(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++)
    {
        ans.push_back(temp[i].second);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> orders(n);

    for (int i = 0; i < n; i++) {
        orders[i].resize(2);

        string orders_row_temp_temp;
        getline(cin, orders_row_temp_temp);

        vector<string> orders_row_temp = split(rtrim(orders_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int orders_row_item = stoi(orders_row_temp[j]);

            orders[i][j] = orders_row_item;
        }
    }

    vector<int> result = jimOrders(orders);

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
