/*
David has several containers, each with a number of balls in it. He has just enough containers to sort each type of ball he has into its own container. David wants to sort the balls using his sort method.
David wants to perform some number of swap operations such that:
Each container contains only balls of the same type.
No two balls of the same type are located in different containers.

Function Description
Complete the organizingContainers function in the editor below.
organizingContainers has the following parameter(s):
int containter[n][m]: a two dimensional array of integers that represent the number of balls of each color in each container
Returns
- string: either Possible or Impossible

Input Format
The first line contains an integer q, the number of queries.
Each of the next q sets of lines is as follows:
The first line contains an integer n, the number of containers (rows) and ball types (columns).
Each of the next n lines contains n space-separated integers describing row containers[i].

Constraints
1 <= q <= 10
1 <= n <= 100
0 <= containers[i][j] <= 10^9

Scoring
For 33% of score, 1 <= n <= 10
For 100% of the score, 1 <= n <= 100

Output Format
For each query, print Possible on a new line if David can satisfy the conditions above for the given matrix. Otherwise, print Impossible.
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'organizingContainers' function below.
 * The function is expected to return a STRING.
 * The function accepts 2D_INTEGER_ARRAY container as parameter.
 */

string organizingContainers(vector<vector<int>> container) {
    int n = container.size();
    vector<int> container_sums(n, 0);
    vector<int> ball_counts(n, 0);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            container_sums[i] += container[i][j];
            ball_counts[j] += container[i][j];
        }
    }
    sort(container_sums.begin(), container_sums.end());
    sort(ball_counts.begin(), ball_counts.end());
    if(container_sums == ball_counts) 
    {
        return "Possible";
    } 
    else 
    {
        return "Impossible";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> container(n);

        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            string container_row_temp_temp;
            getline(cin, container_row_temp_temp);

            vector<string> container_row_temp = split(rtrim(container_row_temp_temp));

            for (int j = 0; j < n; j++) {
                int container_row_item = stoi(container_row_temp[j]);

                container[i][j] = container_row_item;
            }
        }

        string result = organizingContainers(container);

        fout << result << "\n";
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
