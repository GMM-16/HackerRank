/*
Samantha was tasked with calculating the average monthly salaries for all employees in the EMPLOYEES table, but did not realize her keyboard's 0 key was broken until after completing the calculation. She wants your help finding the difference between her miscalculation (using salaries with any zeros removed), and the actual average salary.
Write a query calculating the amount of error (i.e.: actual - miscalculated average monthly salaries), and round it up to the next integer.
The Employee table containing employee data for a company is described as follows:

TABLE EMPLOYEE

Column        |    Type
              |
EMPLOYEE_ID   |    INTEGER
NAME          |    STRING
MONTHS        |    INTEGER
SALARY        |    INTEGER

where employee_id is an employee's ID number, name is their name, months is the total number of months they've been working for the company, and salary is their monthly salary.
Note: Salary is per month.

Constraints
1000 < SALARY < 10^5
*/

SELECT CEIL(AVG(SALARY)-AVG(REPLACE(SALARY,'0',''))) FROM EMPLOYEES
