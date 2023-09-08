/*
There are a number of people who will be attending ACM-ICPC World Finals. Each of them may be well versed in a number of topics. Given a list of topics known by each attendee, presented as binary strings, determine the maximum number of topics a 2-person team can know. Each subject has a column in the binary string, and a '1' means the subject is known while '0' means it is not. Also determine the number of teams that know the maximum number of topics. Return an integer array with two elements. The first is the maximum number of topics known, and the second is the number of teams that know that number of topics.

Function Description
Complete the acmTeam function in the editor below.
acmTeam has the following parameter(s):
string topic: a string of binary digits
Returns
- int[2]: the maximum topics and the number of teams that know that many topics

Input Format
The first line contains two space-separated integers n and m, where n is the number of attendees and m is the number of topics.
Each of the next n lines contains a binary string of length m.

Constraints
2 <= n <= 500
1 <= m <= 500
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'acmTeam' function below.
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY topic as parameter.
 */

vector<int> acmTeam(vector<string> topic) {
    vector<int> ans(2,0);
    int maxtopics = 0;
    int maxteams = 0;
    int n = topic.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int temp = 0;
            for(int k=0;k<topic[i].size();k++)
            {
                if(topic[i][k]=='1' || topic[j][k]=='1')
                {
                    temp++;
                }
            }
            if(temp>maxtopics)
            {
                maxtopics = temp;
                maxteams = 1;
            }
            if(temp==maxtopics)
            {
                maxteams++;
            }
        }
    }
    ans[0] = maxtopics;
    ans[1] = maxteams-1;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
