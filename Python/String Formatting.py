'''
Given an integer, n, print the following values for each integer i from 1 to n:
Decimal
Octal
Hexadecimal (capitalized)
Binary

Function Description
Complete the print_formatted function in the editor below.
print_formatted has the following parameters:
int number: the maximum value to print
Prints
The four values must be printed on a single line in the order specified above for each i from 1 to number. Each value should be space-padded to match the width of the binary value of number and the values should be separated by a single space.

Input Format
A single integer denoting n.

Constraints
1 <= n <= 99
'''

def print_formatted(number):
    # your code goes here
    temp = len(bin(number)[2:])
    for i in range(number):
        d = str(i+1)
        o = str(oct(i+1)[2:])
        h = str(hex(i+1)[2:]).upper()
        b = str(bin(i+1)[2:])
        
        print(d.rjust(temp), o.rjust(temp), h.rjust(temp), b.rjust(temp))

if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
