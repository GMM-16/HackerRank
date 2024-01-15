/*
You are given a main function which reads the enumeration values for two different types as input, then prints out the corresponding enumeration names. Write a class template that can provide the names of the enumeration values for both types. If the enumeration value is not valid, then print unknown.

Input Format
The first line contains t, the number of test cases.
Each of the t subsequent lines contains two space-separated integers. The first integer is a color value, c, and the second integer is a fruit value, f.

Constraints
1 <= t <= 100
-2*10^9 <= c <= 2*10^9
-2*10^9 <= f <= 2*10^9

Output Format
The locked stub code in your editor prints t lines containing the color name and the fruit name corresponding to the input enumeration index.
*/

#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

// Define specializations for the Traits class template here.

const std::string   fruit_strs[] = {"apple", "orange", "pear"};
const std::string   color_strs[] = {"red", "green", "orange"};

template <class T>
class Traits
{
    public:
        static std::string  name(const int index)
        {
            if (index >= 0 && index < 3)
            {
                if (typeid(T) == typeid(Fruit))
                {
                    return (fruit_strs[index]);
                }    
                if (typeid(T) == typeid(Color))
                {    
                    return (color_strs[index]);
                }    
            }
            return ("unknown");            
        }
};


int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
