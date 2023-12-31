'''
We are trying to hack together a smart programming IDE. Help us build a feature which auto-detects the programming language, given the source code. There are only three languages which we are interested in "auto-detecting": Java, C and Python.
We will provide you with links to a few short or medium size programs for Java, C and Python. In case you aren't familiar with some of these languages, these samples will help you make observations about the lexical structure and syntax of these programming languages. These sample programs are only for your manual inspection. You cannot read or access these sample-programs from the code you submit.
After this, you will be provided with tests, where you are provided the source code for programs - or partial code snippets, but you do not know which language they are in. For each test, try to detect which language the source code is in.
You might benefit from using regular expressions in trying to detect the lexical structure and syntax of the programs provided

INPUT FORMAT
Source code of a program, or a code snippet, which might be in C, Java or Python.

OUTPUT FORMAT
Just one line containing the name of the Programming language which you have detected: This might be either C or Java or Python.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
import sys
S = sys.stdin.read()
if re.search(r"#include",S):
    print("C")
elif re.search(r"import java",S):
    print("Java")
else:
    print("Python")
