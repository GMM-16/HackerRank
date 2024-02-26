'''
In this challenge, the task is to debug the existing code to successfully execute all provided test files.
Python supports a useful concept of default argument values. For each keyword argument of a function, we can assign a default value which is going to be used as the value of said argument if the function is called without it. For example, consider the following increment function:

def increment_by(n, increment=1):
    return n + increment
The functions works like this:

>>> increment_by(5, 2)
7
>>> increment_by(4)
5
>>>

Debug the given function print_from_stream using the default value of one of its arguments.
The function has the following signature:

def print_from_stream(n, stream)

This function should print the first n values returned by get_next() method of stream object provided as an argument. Each of these values should be printed in a separate line.
Whenever the function is called without the stream argument, it should use an instance of EvenStream class defined in the code stubs below as the value of stream.
Your function will be tested on several cases by the locked template code.

Input Format
The input is read by the provided locked code template. In the first line, there is a single integer q denoting the number of queries. Each of the following q lines contains a stream_name followed by integer n, and it corresponds to a single test for your function.

Constraints
1 <= q <= 100
1 <= n <= 10

Output Format
The output is produced by the provided and locked code template. For each of the queries (stream_name, n), if the stream_name is even then print_from_stream(n) is called. Otherwise, if the stream_name is odd, then print_from_stream(n, OddStream()) is called.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
def OddStream(i):
    mylist = list(range(1,102,2))
    return mylist[i]
def print_from_stream(number,flag=0):
    for i in range(number):
        print(OddStream(i)-flag)
a = int(input())
for i in range(a):
    b = input().split()
    b[1] = int(b[1])
    if(b[0] == "odd"):
        print_from_stream(b[1])
    else:
        print_from_stream(b[1],1)
