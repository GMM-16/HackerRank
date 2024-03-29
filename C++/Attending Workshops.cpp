/*
A student signed up for n workshops and wants to attend the maximum number of workshops where no two workshops overlap. You must do the following:
Implement 2 structures:
struct Workshop having the following members:
The workshop's start time.
The workshop's duration.
The workshop's end time.
struct Available_Workshops having the following members:
An integer, n (the number of workshops the student signed up for).
An array of type Workshop array having size n.

Implement 2 functions:
Available_Workshops* initialize (int start_time[], int duration[], int n)
Creates an Available_Workshops object and initializes its elements using the elements in the start_time[] and duration[] parameters (both are of size n). Here, start_time[i] and duration[i] are the respective start time and duration for the ith workshop. This function must return a pointer to an Available_Workshops object.
int CalculateMaxWorkshops(Available_Workshops* ptr)
Returns the maximum number of workshops the student can attend—without overlap. The next workshop cannot be attended until the previous workshop ends.
Note: An array of unknown size (n) should be declared as follows:
DataType* arrayName = new DataType[n];

Input Format
Input from stdin is handled by the locked code in the editor; you simply need to write your functions to meet the specifications of the problem statement above.

Constraints
1 <= N <= 10^5
0 <= start_timei <= 10^3
0 <= durationi <= 10^3

Output Format
Output to stdout is handled for you.
Your initialize function must return a pointer to an Available_Workshops object.
Your CalculateMaxWorkshops function must return maximum number of non-overlapping workshops the student can attend.
*/

#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    int start_time, duration, end_time;
    Workshop(int start, int d) : start_time(start), duration(d)
    {
        end_time = start_time + duration;
    }
};

struct Available_Workshops
{
    int n;
    multimap<int, Workshop> workshops; //endTime - Workshop
}available_workshops;


Available_Workshops* initialize(int start_time[], int duration[], int n)
{
    available_workshops.n = n;
    for(int i = 0; i < n; ++i)
    {
        Workshop w{start_time[i], duration[i]};
        available_workshops.workshops.insert({w.end_time, w});
    }
    return &available_workshops;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    int max = 0;
    int time = ptr->workshops.begin()->second.start_time;
    for(auto [end_time, workshop] : ptr->workshops)
    {
        if(workshop.start_time >= time)
        {
            time = end_time;
            ++max;
        }
    }
    return max;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
