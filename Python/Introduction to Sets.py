'''
A set is an unordered collection of elements without duplicate entries.
When printed, iterated or converted into a sequence, its elements will appear in an arbitrary order.

Task
Now, let's use our knowledge of sets and help Mickey.
Ms. Gabriel Williams is a botany professor at District College. One day, she asked her student Mickey to compute the average of all the plants with distinct heights in her greenhouse.
Formula used:

Average = Sum of Distinct Heights / Total Number of Distinct Heights

Function Description
Complete the average function in the editor below.
average has the following parameters:
int arr: an array of integers
Returns
float: the resulting float value rounded to 3 places after the decimal

Input Format
The first line contains the integer, N, the size of arr.
The second line contains the N space-separated integers, arr[i].

Constraints
0 < N <= 100
'''

def average(array):
    # your code goes here
    sum=0
    for i in set(array):
        sum = sum + i
    return sum/len(set(array))

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)
