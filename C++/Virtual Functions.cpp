/*
This problem is to get you familiar with virtual functions. Create three classes Person, Professor and Student. The class Person should have data members name and age. The classes Professor and Student should inherit from the class Person.
The class Professor should have two integer members: publications and cur_id. There will be two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age and publications of the professor. The function putdata should print the name, age, publications and the cur_id of the professor.
The class Student should have two data members: marks, which is an array of size 6 and cur_id. It has two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age, and the marks of the student in  subjects. The function putdata should print the name, age, sum of the marks and the cur_id of the student.
For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from 1.
Solve this problem using virtual functions, constructors and static variables. You can create more data members if you want.
Note: Expand the main function to look at how the input is being handled.

Input Format
The first line of input contains the number of objects that are being created. If the first line of input for each object is 2, it means that the object being created is of the Professor class, you will have to input the name, age and publications of the professor.
If the first line of input for each object is , it means that the object is of the Student class, you will have to input the name, age and the marks of the student in 6 subjects.

Constraints
1 <= lenname <= 100, where lenname is the length of the name
1 <= age <= 80
1 <= publications <= 1000
0 <= marks <= 100, where marks is the marks of the student in each subject

Output Format
There are two types of output depending on the object.
If the object is of type Professor, print the space separated name, age, publications and id on a new line.
If the object is of the Student class, print the space separated name, age, the sum of the marks in 6 subjects and id on a new line.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person    
{
    protected:
            int age;
            string name;
        public:
            virtual void getdata() = 0;
            virtual void putdata() = 0;
};
class Professor : public Person 
{
    private:
            int  publications, cur_id;
            static int pp;
    public:
            void getdata()  
            {
                cin>>name>>age>>publications;
                cur_id = ++pp;
            }
            void putdata()  
            {
                    cout<<name<<" "<<age<<" "<<publications<<" "<<cur_id<<endl;
            }
};
int Professor::pp=0;

class Student : public Person   
{
    private:
        int Arr[6];
        static int count;
        int cur_id;
    public:
        void getdata()  
        {
            cin>>name>>age;
            for(int x = 0; x<6; x++)
            {
                cin>>Arr[x];
            }
            cur_id = ++count;
        }
        void putdata()  
        {
            int sum =0;
            for(int x = 0; x<6; sum+=Arr[x], x++);
            cout<<name<<" "<<age<<" "<<sum<<" "<<cur_id<<endl;
        }
};
int Student::count=0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
