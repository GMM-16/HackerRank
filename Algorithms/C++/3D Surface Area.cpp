/*
Madison is a little girl who is fond of toys. Her friend Mason works in a toy manufacturing factory . Mason has a 2D board A of size H * W with H rows and W columns. The board is divided into cells of size 1*1 with each cell indicated by its coordinate (i,j). The cell (i,j) has an integer Aij written on it. To create the toy Mason stacks Aij number of cubes of size 1*1*1 on the cell (i,j)
Given the description of the board showing the values of Aij and that the price of the toy is equal to the 3d surface area find the price of the toy.

Input Format
The first line contains two space-separated integers H and W the height and the width of the board respectively.
The next H lines contains W space separated integers. The jth integer in ith line denotes Aij.

Constraints
1 <= H,W <= 100
1 <= Aij <= 100

Output Format
Print the required answer, i.e the price of the toy, in one line.
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'surfaceArea' function below.
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY A as parameter.
 */

int surfaceArea(vector<vector<int>> A) {
    int x = A.size();
    int y = A[0].size();
    int ans = 2 * x * y;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(i>0)
            {
                ans = ans + abs(A[i][j] - A[i-1][j]);
            }
            else
            {
                ans = ans + A[i][j];
            }
            if(j>0)
            {
                ans = ans + abs(A[i][j] - A[i][j-1]);
            }
            else
            {
                ans = ans + A[i][j];
            }
            if(i == x-1)
            {
                ans = ans + A[i][j];
            }
            if(j == y-1)
            {
                ans = ans + A[i][j];
            }
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int H = stoi(first_multiple_input[0]);

    int W = stoi(first_multiple_input[1]);

    vector<vector<int>> A(H);

    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        string A_row_temp_temp;
        getline(cin, A_row_temp_temp);

        vector<string> A_row_temp = split(rtrim(A_row_temp_temp));

        for (int j = 0; j < W; j++) {
            int A_row_item = stoi(A_row_temp[j]);

            A[i][j] = A_row_item;
        }
    }

    int result = surfaceArea(A);

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
