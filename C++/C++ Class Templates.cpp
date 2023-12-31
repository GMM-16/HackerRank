/*
A class template provides a specification for generating classes based on parameters. Class templates are generally used to implement containers. A class template is instantiated by passing a given set of types to it as template arguments. Here is an example of a class, MyTemplate, that can store one element of any type and that has just one member function divideBy2, which divides its value by 2.

template <class T>
class MyTemplate {
T element;
public:
MyTemplate (T arg) {element=arg;}
T divideBy2 () {return element/2;}
};
It is also possible to define a different implementation of a template for a specific type. This is called Template Specialization. For the template given above, we find that a different implementation for type char will be more useful, so we write a function printElement to print the char element:

// class template specialization:
template <>
class MyTemplate <char> {
char element;
public:
MyTemplate (char arg) {element=arg;}
char printElement ()
{
return element;
}
};
You are given a main() function which takes a set of inputs. The type of input governs the kind of operation to be performed, i.e. concatenation for strings and addition for int or float. You need to write the class template AddElements which has a function add() for giving the sum of int or float elements. You also need to write a template specialization for the type string with a function concatenate() to concatenate the second string to the first string.

Input Format
The first line contains an integer n. Input will consist of n+1 lines where n is the number given in the first line of the input followed by n lines.
Each of the next n line contains the type of the elements provided and depending on the type, either two strings or two integers or two floating point numbers will be given. The type will be one of int, float or string types only. Out of the following two elements, you have to concatenate or add the second element to the first element.

Constraints
1 <= n <= 5*10^5
1.0 <=valuefloat <= 10.0, where valuefloat is any float value
1 <= valueint <= 10^5, where valueint is any int value
0 <= lenstring <= 10, where lenstring is the length of any string
The time limit for this challenge is 4 seconds.

Output Format
The code provided in the code editor will use your class template to add/append elements and give the output.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*Write the class AddElements here*/

template <class T>
class AddElements
{
    T element;
    public:
    AddElements(T arg) 
    {
        element=arg;
    }
    T add(T element2) 
    {
        return element+element2;
    }
};
template <>
class AddElements<string>
{
    string element;
    public:
    AddElements(string arg) 
    {
        element = arg;
    }
    string concatenate(string element2)
    {
        return element+element2;
    }
}; 

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
