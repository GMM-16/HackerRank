/*
Query the Name of any student in STUDENTS who scored higher than  Marks. Order your output by the last three characters of each name. If two or more students both have names ending in the same last three characters, secondary sort them by ascending ID.
The STUDENTS table is described as follows:

TABLE STUDENTS

Column      |    Type
            |
ID          |    INTEGER
NAME        |    STRING
MARKS       |    INTEGER

The Name column only contains uppercase (A-Z) and lowercase (a-z) letters.
*/

SELECT NAME FROM STUDENTS WHERE MARKS > 75 ORDER BY RIGHT(NAME,3) ASC , ID ASC
