/*
We define a magic square to be an n * n matrix of distinct positive integers from 1 to n^2 where the sum of any row, column, or diagonal of length n is always equal to the same number: the magic constant.
You will be given a 3 * 3 matrix s integers in the inclusive range [1,9]. We can convert any digit  to any other digit b in the range [1,9] at a cost of |a - b|. Given s, convert it into a magic square at minimal cost. Print this cost on a new line.
Note: The resulting magic square must contain distinct integers in the inclusive range [1,9].

Function Description
Complete the formingMagicSquare function in the editor below.
formingMagicSquare has the following parameter(s):
int s[3][3]: a 3 * 3 array of integers
Returns
- int: the minimal total cost of converting the input square to a magic square

Input Format
Each of the 3 lines contains three space-separated integers of row s[i].

Constraints
s[i][j] ∈ |1,9|
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

int formingMagicSquare(vector<vector<int>> s) {
    vector<vector<vector<int>>> magic_squares = 
    {
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}
    };
    int min_cost = INT_MAX;
    for(int id=0;id<magic_squares.size();id++)
    {
        int cost = 0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cost = cost + abs(s[i][j] - magic_squares[id][i][j]);
            }
        }
        min_cost = min(min_cost,cost);
    }
    return min_cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

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
