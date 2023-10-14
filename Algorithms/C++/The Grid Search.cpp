/*
Given an array of strings of digits, try to find the occurrence of a given pattern of digits. In the grid and pattern arrays, each string represents a row in the grid.
The pattern begins at the second row and the third column of the grid and continues in the following two rows. The pattern is said to be present in the grid. The return value should be YES or NO, depending on whether the pattern is found. In this case, return YES.

Function Description
Complete the gridSearch function in the editor below. It should return YES if the pattern exists in the grid, or NO otherwise.
gridSearch has the following parameter(s):
- string G[R]: the grid to search
- string P[r]: the pattern to search for

Input Format
The first line contains an integer t, the number of test cases.
Each of the t test cases is represented as follows:
The first line contains two space-separated integers R and C, the number of rows in the search grid G and the length of each row string.
This is followed by R lines, each with a string of C digits that represent the grid G.
The following line contains two space-separated integers, r and c, the number of rows in the pattern grid P and the length of each pattern row string.
This is followed by r lines, each with a string of c digits that represent the pattern grid P.
Returns
- string: either YES or NO

Constraints
1 <= t <= 5
1 <= R,r,C,c <= 1000
1 <= r <= R
1 <= c <= C
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gridSearch' function below.
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY G
 *  2. STRING_ARRAY P
 */

string gridSearch(vector<string> G, vector<string> P) {
    int rows_G = G.size(); 
    int cols_G = G[0].size(); 
    int rows_P = P.size(); 
    int cols_P = P[0].size();
    for (int i = 0; i <= rows_G - rows_P; i++) 
    {
        for (int j = 0; j <= cols_G - cols_P; j++) 
        {
            bool flag = true;
            for (int k = 0; k < rows_P; k++) 
            {
                for (int l = 0; l < cols_P; l++) 
                {
                    if (G[i + k][j + l] != P[k][l]) 
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag) 
                {
                    break;
                }
            }
            if(flag) 
            {
                return "YES";
            }
        }
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int R = stoi(first_multiple_input[0]);

        int C = stoi(first_multiple_input[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string second_multiple_input_temp;
        getline(cin, second_multiple_input_temp);

        vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

        int r = stoi(second_multiple_input[0]);

        int c = stoi(second_multiple_input[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P);

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
