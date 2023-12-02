/*
Louise joined a social networking site to stay in touch with her friends. The signup page required her to input a name and a password. However, the password must be strong. The website considers a password to be strong if it satisfies the following criteria:
Its length is at least 6.
It contains at least one digit.
It contains at least one lowercase English character.
It contains at least one uppercase English character.
It contains at least one special character. The special characters are: !@#$%^&*()-+
She typed a random string of length  in the password field but wasn't sure if it was strong. Given the string she typed, can you find the minimum number of characters she must add to make her password strong?
Note: Here's the set of types of characters in a form you can paste in your solution:
numbers = "0123456789"
lower_case = "abcdefghijklmnopqrstuvwxyz"
upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
special_characters = "!@#$%^&*()-+"

Function Description
Complete the minimumNumber function in the editor below.
minimumNumber has the following parameters:
int n: the length of the password
string password: the password to test
Returns
- int: the minimum number of characters to add

Input Format
The first line contains an integer n, the length of the password.
The second line contains the password string. Each character is either a lowercase/uppercase English alphabet, a digit, or a special character.

Constraints
1 <= n <= 100
All characters in password are in [a-z], [A-Z], [0-9], or [!@#$%^&*()-+ ].
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) 
{
    const string numbers = "0123456789";
    const string lower_case = "abcdefghijklmnopqrstuvwxyz";
    const string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string special_characters = "!@#$%^&*()-+";
    bool hasNumbers = false;
    bool hasLowerCase = false;
    bool hasUpperCase = false;
    bool hasSpecialChar = false;

    for (int i = 0; i < password.length(); ++i) 
    {
        char ch = password[i];
        for (int j = 0; j < numbers.length(); ++j) 
        {
            if (ch == numbers[j]) 
            {
                hasNumbers = true;
                break;
            }
        }
        for (int j = 0; j < lower_case.length(); ++j) 
        {
            if (ch == lower_case[j]) 
            {
                hasLowerCase = true;
                break;
            }
        }
        for (int j = 0; j < upper_case.length(); ++j) 
        {
            if (ch == upper_case[j]) 
            {
                hasUpperCase = true;
                break;
            }
        }
        for (int j = 0; j < special_characters.length(); ++j) 
        {
            if (ch == special_characters[j]) 
            {
                hasSpecialChar = true;
                break;
            }
        }
    }
    int count = 0;
    count += !hasNumbers;
    count += !hasLowerCase;
    count += !hasUpperCase;
    count += !hasSpecialChar;
    int ans = max(6 - static_cast<int>(password.length()), count);
    return ans;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
