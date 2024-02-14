'''
zip([iterable, ...])
This function returns a list of tuples. The ith tuple contains the ith element from each of the argument sequences or iterables.
If the argument sequences are of unequal lengths, then the returned list is truncated to the length of the shortest argument sequence.

Task
The National University conducts an examination of N students in X subjects.
Your task is to compute the average scores of each student.

Average Score =  Sum of scored obtained in all subjects by a student / Total number of students

The format for the general mark sheet is:
Student ID → ___1_____2_____3_____4_____5__               
Subject 1   |  89    90    78    93    80
Subject 2   |  90    91    85    88    86  
Subject 3   |  91    92    83    89    90.5
            |______________________________
Average        90    91    82    90    85.5 

Input Format
The first line contains N and X separated by a space.
The next X lines contains the space separated marks obtained by students in a particular subject.

Constraints
0 < N <= 100
0 < X <=100

Output Format
Print the averages of all students on separate lines.
The averages must be correct up to 1 decimal place.
'''

# Enter your code here. Read input from STDIN. Print output to STDOUT
m, n = input().split()
y = []
for i in range(int(n)):
    x = input().split()
    y.append(x)
z = zip(*y)
z = list(z)
for i in range(len(z)):
    lis = list(map(float, z[i]))
    print(sum(lis)/len(z[i]))
