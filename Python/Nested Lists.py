'''
Given the names and grades for each student in a class of N students, store them in a nested list and print the name(s) of any student(s) having the second lowest grade.
Note: If there are multiple students with the second lowest grade, order their names alphabetically and print each name on a new line.

Input Format
The first line contains an integer, N, the number of students.
The 2N subsequent lines describe each student over 2 lines.
- The first line contains a student's name.
- The second line contains their grade.

Constraints
2 <= N <= 5
There will always be one or more students having the second lowest grade.

Output Format
Print the name(s) of any student(s) having the second lowest grade in. If there are multiple students, order their names alphabetically and print each one on a new line.
'''

if __name__ == '__main__':
    students_scores = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        students_scores.append([name,score])
    scores = []
    for score in students_scores:
        scores.append(score[1])
    sorted_scores = sorted(set(scores))
    second_low_score = sorted_scores[1]
    students = []
    for student in students_scores:
        if student[1] == second_low_score:
            students.append(student[0])
    sorted_students = sorted(students)
    for name in sorted_students:
        print(name)
