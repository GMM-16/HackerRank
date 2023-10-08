/*
A modified Kaprekar number is a positive whole number with a special property. If you square it, then split the number into two integers and sum those integers, you have the same value you started with.
Consider a positive whole number n with d digits. We square n to arrive at a number that is either 2 * d digits long or (2 * d) - 1 digits long.Split the string representation of the square into two parts, l and r. The right hand part, r must be d digits long. The left is the remaining substring. Convert those two substrings back to integers, add them and see if you get n.
Note: r may have leading zeros.
Here's an explanation from Wikipedia about the ORIGINAL Kaprekar Number (spot the difference!):
In mathematics, a Kaprekar number for a given base is a non-negative integer, the representation of whose square in that base can be split into two parts that add up to the original number again. For instance, 45 is a Kaprekar number, because 45² = 2025 and 20+25 = 45.
Given two positive integers p and w where p is lower than q, write a program to print the modified Kaprekar numbers in the range between p and q, inclusive. If no modified Kaprekar numbers exist in the given range, print INVALID RANGE.

Function Description
Complete the kaprekarNumbers function in the editor below.
kaprekarNumbers has the following parameter(s):
int p: the lower limit
int q: the upper limit
Prints
It should print the list of modified Kaprekar numbers, space-separated on one line and in ascending order. If no modified Kaprekar numbers exist in the given range, print INVALID RANGE. No return value is required.

Input Format
The first line contains the lower integer limit p.
The second line contains the upper integer limit 1.
Note: Your range should be inclusive of the limits.

Constraints
0 < p < q < 100000
*/

#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

void kaprekarNumbers(int p, int q) {
     bool found = false;

    for (int n = p; n <= q; n++) {
        long long square = static_cast<long long>(n) * n;
        int numDigits = static_cast<int>(log10(square)) + 1;
        long long divisor = static_cast<long long>(pow(10, numDigits / 2));

        long long right = square % divisor;
        long long left = square / divisor;

        if (left + right == n) {
            found = true;
            cout << n << " ";
        }
    }

    if (!found) {
        cout << "INVALID RANGE";
    }

    cout << endl;
}

int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

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
