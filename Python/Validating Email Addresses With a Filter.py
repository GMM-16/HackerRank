'''
You are given an integer N followed by N email addresses. Your task is to print a list containing only valid email addresses in lexicographical order.
Valid email addresses must follow these rules:
It must have the username@websitename.extension format type.
The username can only contain letters, digits, dashes and underscores [a-z][A-Z][0-9][_-].
The website name can only have letters and digits [a-z][A-Z][0-9].
The extension can only contain letters [a-z][A-Z].
The maximum length of the extension is 3.

Concept
A filter takes a function returning True or False and applies it to a sequence, returning a list of only those members of the sequence where the function returned True. A Lambda function can be used with filters.

Complete the function fun in the editor below.
fun has the following paramters:
string s: the string to test
Returns
boolean: whether the string is a valid email or not

Input Format
The first line of input is the integer N, the number of email addresses.
N lines follow, each containing a string.

Constraints
Each line is a non-empty string.
'''

def fun(s):
    # return True if s is a valid email, else return False
    import re
    return bool(re.fullmatch("[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\.[a-zA-Z]{,3}", s))
def filter_mail(emails):
    return list(filter(fun, emails))
if __name__ == '__main__':
    n = int(input())
    emails = []
    for _ in range(n):
        emails.append(input())
filtered_emails = filter_mail(emails)
filtered_emails.sort()
print(filtered_emails)
