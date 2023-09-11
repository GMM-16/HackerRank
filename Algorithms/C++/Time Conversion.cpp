/*
Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.
Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
      - 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

Function Description
Complete the timeConversion function in the editor below. It should return a new string representing the input time in 24 hour format.
timeConversion has the following parameter(s):
string s: a time in 12 hour format
Returns
- string: the time in 24 hour format

Input Format
A single string s that represents a time in 12-hour clock format (i.e.:hh:mm:ssAM or hh:mm:ssPM).

Constraints
All input times are valid
*/

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'timeConversion' function below.
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string hrs,mins,secs,ampm,ans;
    hrs = s.substr(0,2);
    mins = s.substr(3,2);
    secs = s.substr(6,2);
    ampm = s.substr(8,2);
    int temp = stoi(hrs);
    if(ampm == "PM" && temp != 12)
    {
        temp = temp + 12;
    }
    if(ampm == "AM" && temp == 12)
    {
        temp = 0;
    }
    if(temp<10)
    {
        hrs = "0" + to_string(temp);
    }
    else
    {
        hrs = to_string(temp);    
    }
    ans = hrs + ":" + mins + ":" + secs;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
