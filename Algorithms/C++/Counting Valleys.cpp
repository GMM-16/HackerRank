/*
An avid hiker keeps meticulous records of their hikes. During the last hike that took exactly  steps, for every step it was noted if it was an uphill, U, or a downhill, D step. Hikes always start and end at sea level, and each step up or down represents a 1 unit change in altitude. We define the following terms:
A mountain is a sequence of consecutive steps above sea level, starting with a step up from sea level and ending with a step down to sea level.
A valley is a sequence of consecutive steps below sea level, starting with a step down from sea level and ending with a step up to sea level.
Given the sequence of up and down steps during a hike, find and print the number of valleys walked through.

Function Description
Complete the countingValleys function in the editor below.
countingValleys has the following parameter(s):
int steps: the number of steps on the hike
string path: a string describing the path
Returns
- int: the number of valleys traversed

Input Format
The first line contains an integer steps, the number of steps in the hike.
The second line contains a single string path, of step characters that describe the path.

Constraints
2 <= steps <= 10^6
path[i] ∈ {U,D}
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countingValleys' function below.
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {
    int size = path.length();
    int ans = 0;
    int temp = 0;
    if(path[0]=='U')
    {
        temp++;
    }
    else
    {
        temp--;
    }
    for(int i=1;i<size;i++)
    {
        if(path[i]=='U')
        {
            if(temp+1==0)
            {
                temp++;
                ans++;
            }
            else
            {
                temp++;
            }
        }
        else
        {
            temp--;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

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
