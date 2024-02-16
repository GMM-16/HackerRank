'''
Let's dive into decorators! You are given  mobile numbers. Sort them in ascending order then print them in the standard format shown below:
+91 xxxxx xxxxx
The given mobile numbers may have +91, 91 or 0 written before the actual  digit number. Alternatively, there may not be any prefix at all.

Input Format
The first line of input contains an integer N, the number of mobile phone numbers.
N lines follow each containing a mobile number.

Output Format
Print N mobile numbers on separate lines in the required format.
'''

def wrapper(f):
    def fun(l):
        # complete the function
        for i in range(len(l)):
            last_five_num = l[i][-5:]
            first_five_num = l[i][-10:-5]
            l[i] = '+91 ' + first_five_num + ' ' + last_five_num
        f(l)
    return fun

@wrapper
def sort_phone(l):
    print(*sorted(l), sep='\n')

if __name__ == '__main__':
    l = [input() for _ in range(int(input()))]
    sort_phone(l) 
