/*
We define an employee's total earnings to be their monthly salary*months worked, and the maximum total earnings to be the maximum total earnings for any employee in the Employee table. Write a query to find the maximum total earnings for all employees as well as the total number of employees who have maximum total earnings. Then print these values as 2 space-separated integers.
The Employee table containing employee data for a company is described as follows:

TABLE EMPLOYEE

Column        |    Type
              |
EMPLOYEE_ID   |    INTEGER
NAME          |    STRING
MONTHS        |    INTEGER
SALARY        |    INTEGER

where employee_id is an employee's ID number, name is their name, months is the total number of months they've been working for the company, and salary is their monthly salary.
*/

SELECT MAX(SALARY*MONTHS),COUNT(SALARY*MONTHS) FROM EMPLOYEE GROUP BY SALARY*MONTHS DESC LIMIT 1
