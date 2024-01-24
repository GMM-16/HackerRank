'''
You are given an integer, N. Your task is to print an alphabet rangoli of size N. (Rangoli is a form of Indian folk art based on creation of patterns.)
Different sizes of alphabet rangoli are shown below:
The center of the rangoli has the first alphabet letter a, and the boundary has the Nth alphabet letter (in alphabetical order).

Function Description
Complete the rangoli function in the editor below.
rangoli has the following parameters:
int size: the size of the rangoli
Returns
string: a single string made up of each of the lines of the rangoli separated by a newline character (\n)
Input Format
Only one line of input containing size, the size of the rangoli.

Constraints
0 < size < 27
'''

def print_rangoli(size):
    # your code goes here
    str=''
    for i in range(size,0,-1):
        str+=chr(i+64).lower()
        if(len(str))==1:
            print(str.center(size*4-3,'-'))
        else:
            a='-'.join(str)
            b=a+a[len(a)-2::-1]
            pattern=b.center(size*4-3,'-')
            print(pattern)
    for i in range(size,1,-1):
        str=str[0:len(str)-1]
        if(len(str))==1:
            print(str.center(size*4-3,'-'))
        else:
            a='-'.join(str)
            b=a+a[len(a)-2::-1]
            pattern=b.center(size*4-3,'-')
            print(pattern)

if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)
