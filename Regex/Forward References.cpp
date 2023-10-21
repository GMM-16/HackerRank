/*
NOTE - Forward reference is supported by JGsoft, .NET, Java, Perl, PCRE, PHP, Delphi and Ruby regex flavors.
Forward reference creates a back reference to a regex that would appear later.
Forward references are only useful if they're inside a repeated group.
Then there may arise a case in which the regex engine evaluates the backreference after the group has been matched already.

Task
You have a test string S.
Your task is to write a regex which will match S, with following condition(s):
S consists of tic or tac.
tic should not be immediate neighbour of itself.
The first tic must occur only when tac has appeared at least twice before.

Valid S
tactactic
tactactictactic
Invalid S
tactactictactictictac
tactictac

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

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string input;
    cin >> input;
    regex pattern("^(tac){2,}(tictac|tac)*(tic)?$");
    if (regex_match(input, pattern)) 
    {
        cout << "true" << endl;
    } 
    else 
    {
        cout << "false" << endl;
    }  
    return 0;
}
