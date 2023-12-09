/*
A numeric string, s, is beautiful if it can be split into a sequence of two or more positive integers, a[1],a[2],.....,a[n], satisfying the following conditions:
a[i] - a[i-1] = 1 for any 1 < i <= n (i.e., each element in the sequence is 1 more than the previous element).
No a[i] contains a leading zero. For example, we can split s = 10203 into the sequence {1,02,03}, but it is not beautiful because 02 and 03 have leading zeroes.
The contents of the sequence cannot be rearranged. For example, we can split s = 312 into the sequence {3,1,2}, but it is not beautiful because it breaks our first constraint (i.e., 1 - 3 != 1).
The diagram below depicts some beautiful strings:
Perform q queries where each query consists of some integer string s. For each query, print whether or not the string is beautiful on a new line. If it is beautiful, print YES x, where x is the first number of the increasing sequence. If there are multiple such values of x, choose the smallest. Otherwise, print NO.

Function Description
Complete the separateNumbers function in the editor below.
separateNumbers has the following parameter:
s: an integer value represented as a string
Prints
- string: Print a string as described above. Return nothing.

Input Format
The first line contains an integer q, the number of strings to evaluate.
Each of the next q lines contains an integer string s to query.

Constraints
1 <= q <= 10
1 <= |s| <= 32
s[i] ∈ [0-9]
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'separateNumbers' function below.
 * The function accepts STRING s as parameter.
 */

void separateNumbers(string s) 
{
    for(int i=1;i<=s.length() / 2;i++)
    {
        string temp_str = s.substr(0,i);
        long long temp_int = stoll(temp_str);
        while(temp_str.length()<s.length())
        {
            temp_int = temp_int + 1;
            temp_str = temp_str + to_string(temp_int);
        }
        if(temp_str == s)
        {
            cout<<"YES "<<s.substr(0,i)<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

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
