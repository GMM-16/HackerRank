/*
You are given three tables: Students, Friends and Packages. Students contains two columns: ID and Name. Friends contains two columns: ID and Friend_ID (ID of the ONLY best friend). Packages contains two columns: ID and Salary (offered salary in $ thousands per month).

TABLE STUDENTS

Column    |    Type
          |
ID        |    INTEGER
NAME      |    STRING

TABLE FRIENDS

Column    |    Type
          |
ID        |    INTEGER
FRIEND_ID |    INTEGER

TABLE PACKAGES

Column    |    Type
          |
ID        |    INTEGER
SALARY    |    FLOAT

Write a query to output the names of those students whose best friends got offered a higher salary than them. Names must be ordered by the salary amount offered to the best friends. It is guaranteed that no two students got same salary offer.
*/

SELECT NAME FROM STUDENTS JOIN FRIENDS USING (ID) JOIN PACKAGES AS STUDENT_SALARY USING (ID) JOIN PACKAGES AS FRIEND_SALARY ON FRIEND_SALARY.ID = FRIENDS.FRIEND_ID WHERE FRIEND_SALARY.SALARY > STUDENT_SALARY.SALARY ORDER BY FRIEND_SALARY.SALARY
