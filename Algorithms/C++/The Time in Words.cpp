/*
Given the time in numerals we may convert it into words.
At minutes = 0, use o' clock. For 1 <= minutes <= 30, use past and for 30 < minutes use to. Note the space between the apostrophe and clock in o' clock. Write a program which prints the time in words for the input given in the format described.

Function Description
Complete the timeInWords function in the editor below.
timeInWords has the following parameter(s):
int h: the hour of the day
int m: the minutes after the hour
Returns
- string: a time string as described

Input Format
The first line contains h, the hours portion The second line contains m, the minutes portion

Constraints
1 <= h <= 12
0 <= m < 60
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string timeInWords(int h, int m) {
    vector<string> words = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "quarter", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine"};
    if (m == 0) 
    {
        return words[h] + " o' clock";
    } 
    else if (m == 1) 
    {
        return "one minute past " + words[h];
    } 
    else if (m == 59) 
    {
        return "one minute to " + words[(h % 12) + 1];
    } 
    else if (m == 15) 
    {
        return "quarter past " + words[h];
    } 
    else if (m == 45) 
    {
        return "quarter to " + words[(h % 12) + 1];
    } 
    else if (m == 30) 
    {
        return "half past " + words[h];
    } 
    else if (m <= 30) 
    {
        return words[m] + " minutes past " + words[h];
    } 
    else 
    {
        return words[60 - m] + " minutes to " + words[(h % 12) + 1];
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

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
