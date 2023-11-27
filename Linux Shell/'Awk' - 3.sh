: '
An Introduction to 'awk'
There are a lot of quick tricks which may be accomplished with the 'awk' interpreter. Among other things, awk may be used for a lot of text-munging and data-processing tasks which require some quick scripting work.

Task
You are provided a file with four space-separated columns containing the scores of students in three subjects. The first column, contains a single character (A-Z) - the identifier of the student. The next three columns have three numbers (each between 0 and 100, both inclusive) which are the scores of the students in English, Mathematics and Science respectively.
Your task is to identify the performance grade for each student. If the average of the three scores is 80 or more, the grade is 'A'. If the average is 60 or above, but less than 80, the grade is 'B'. If the average is 50 or above, but less than 60, the grade is 'C'. Otherwise the grade is 'FAIL'.

Input Format
There will be no more than 10 rows of data.
Each line will be in the format:
[Identifier][Score in English][Score in Math][Score in Science]

Output Format
For each row of data, append a space, a colon, followed by another space, and the grade. Observe the format showed in the sample output.
'

awk '{if($2<50 || $3<50 || $4<50){print $0 " : FAIL"} else if( ($2+$3+$4)/3 >= 80){print $0 " : A"} else if( ($2+$3+$4)/3 >= 60){print $0 " : B"} else{print $0 " : C"}}' 
