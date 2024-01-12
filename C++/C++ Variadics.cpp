/*
A template parameter pack is a template parameter that accepts zero or more template arguments (non-types, types, or templates). To read more about parameter pack, click here.
Create a template function named reversed_binary_value. It must take an arbitrary number of bool values as template parameters. These booleans represent binary digits in reverse order. Your function must return an integer corresponding to the binary value of the digits represented by the booleans.

Input Format
The first line contains an integer, t, the number of test cases. Each of the t subsequent lines contains a test case. A test case is described as 2 space-separated integers, x and y, respectively.
x is the value to compare against.
y represents the range to compare: 64 * y to 64 * y + 63.

Constraints
0 <= x <= 65535
0 <= y <= 1023
The number of template parameters passed to reversed_binary_value will be <= 16.

Output Format
Each line of output contains 64 binary characters (i.e., 0's and 1's). Each character represents one value in the range. The first character corresponds to the first value in the range. The last character corresponds to the last value in the range. The character is 1 if the value in the range matches X; otherwise, the character is 0.
*/

#include <iostream>
using namespace std;

#include <vector>
#include <cmath>

template <bool... digits> int reversed_binary_value() 
{  
    vector<bool> digs = {digits...};
    int sum{};
    for (int i{}; i < (int)digs.size(); ++i) {
        
        if (digs[i]){
            sum += pow(2, i);
        }
    }
    return sum;
}

// Enter your code for reversed_binary_value<bool...>()


template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}
