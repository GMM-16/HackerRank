/*
NOTE - Branch reset group is supported by Perl, PHP, Delphi and R.
(?|regex)
A branch reset group consists of alternations and capturing groups. (?|(regex1)|(regex2))
Alternatives in branch reset group share same capturing group.

Task
You have a test string S.
Your task is to write a regex which will match S, with following condition(s):
S consists of 8 digits.
S must have "---", "-", "." or ":" separator such that string  gets divided in 4 parts, with each part having exactly two digits.
S string must have exactly one kind of separator.
Separators must have integers on both sides.

Valid S
12-34-56-78
12:34:56:78
12---34---56---78
12.34.56.78
Invalid S
1-234-56-78
12-45.78:10

Note
This is a regex only challenge. You are not required to write any code.
You only have to fill the regex pattern in the blank (_________).
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string input;
    regex pattern("^(\\d{2}---){3}\\d{2}$|^(\\d{2}-){3}\\d{2}$|^(\\d{2}:){3}\\d{2}$|^(\\d{2}\\.){3}\\d{2}$");
    cin >> input;
    if(regex_match(input,pattern))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }   
    return 0;
}
