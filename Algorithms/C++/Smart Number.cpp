/*
In this challenge, the task is to debug the existing code to successfully execute all provided test files.
A number is called a smart number if it has an odd number of factors. Given some numbers, find whether they are smart numbers or not.
Debug the given function is_smart_number to correctly check if a given number is a smart number.
Note: You can modify only one line in the given code and you cannot add or remove any new lines.
To restore the original code, click on the icon to the right of the language selector.

Input Format
The first line of the input contains t, the number of test cases.
The next t lines contain one integer each.

Constraints
1 <= t <= 10^3
1 <= ni <= 10^4, where ni is the ith integer

Output Format
The output should consist of t lines. In the ith line print YES if the ith integer has an odd number of factors, else print NO.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_smart_number(int num) {
    int val = (int) sqrt(num);
    if(double(num) / val == val)
        return true;
    return false;
}

int main() {
    
    int test_cases;
    cin >> test_cases;
    int num;
    for(int i = 0; i < test_cases; i++) {
        cin >> num;
        bool ans = is_smart_number(num);
        if(ans) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
