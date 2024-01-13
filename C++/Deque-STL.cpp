/*
Double ended queue or Deque(part of C++ STL) are sequence containers with dynamic sizes that can be expanded or contracted on both ends (either its front or its back). The member functions of deque that are mainly used are:

Deque Template:
std::deque<value_type>

Declaration:
deque<int> mydeque; //Creates a double ended queue of deque of int type

Size
int length = mydeque.size(); //Gives the size of the deque

Push
mydeque.push_back(1); //Pushes element at the end
mydeque.push_front(2); //Pushes element at the beginning

Pop
mydeque.pop_back(); //Pops element from the end
mydeque.pop_front(); //Pops element from the beginning

Empty
mydeque.empty() //Returns a boolean value which tells whether the deque is empty or not
To know more about deque, click here

Given a set of arrays of size N and an integer K, you have to find the maximum integer for each and every contiguous subarray of size K for each of the given arrays.

Input Format
First line of input will contain the number of test cases T. For each test case, you will be given the size of array N and the size of subarray to be used K. This will be followed by the elements of the array Ai.

Constraints
1 <= T <= 1000
1 <= N <= 10000
1 <= K <= N
1 <= Ai <= 10000, where Ai is the ith element in the array

Output Format
For each of the contiguous subarrays of size K of each array, you have to print the maximum integer.
*/

#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k)
{
	//Write your code here.
    bool nomax=true;
    int idex=0, max;
    for(int i=0; i<=n-k; ++i)
    {
        if(nomax)
        {
            max=arr[i];
            for(int j=1; j<k; ++j)
            {
                if (max<arr[i+j])
                {
                    max=arr[i+j];
                    idex=j;
                }
            }
            cout<<max<<" ";
            nomax=false;
        }
        else
        {
            if(max<arr[k+i-1])
            {
                max=arr[k+i-1];
                idex=k-1;
                cout<<max<<" ";
            }
            else
            {
                --idex;
                if(idex<0)
                {
                    nomax=true;
                    --i;
                }
                else cout<<max<<" ";
            }            
        }
    }
    cout<<endl;
}

int main()
{
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
