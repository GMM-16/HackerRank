/*
Amber's conglomerate corporation just acquired some new companies. Each of the companies follows this hierarchy:
Founder -> Lead Manager -> Senior Manager -> Manager -> Employee
Given the table schemas below, write a query to print the company_code, founder name, total number of lead managers, total number of senior managers, total number of managers, and total number of employees. Order your output by ascending company_code.
Note:
The tables may contain duplicate records.
The company_code is string, so the sorting should not be numeric. For example, if the company_codes are C_1, C_2, and C_10, then the ascending company_codes will be C_1, C_10, and C_2.
The following tables contain company data:

Company: The company_code is the code of the company and founder is the founder of the company.

TABLE COMPANY

Column        |    Type
              |
COMPANY_CODE  |    STRING
FOUNDER       |    STRING

Lead_Manager: The lead_manager_code is the code of the lead manager, and the company_code is the code of the working company.

TABLE LEAD_MANAGER

Column             |    Type
                   |
LEAD_MANAGER_CODE  |    STRING
COMPANY_CODE       |    STRING

Senior_Manager: The senior_manager_code is the code of the senior manager, the lead_manager_code is the code of its lead manager, and the company_code is the code of the working company.

TABLE SENIOR_MANAGER

Column               |    Type
                     |
SENIOR_MANAGER_CODE  |    STRING  
LEAD_MANAGER_CODE    |    STRING
COMPANY_CODE         |    STRING

Manager: The manager_code is the code of the manager, the senior_manager_code is the code of its senior manager, the lead_manager_code is the code of its lead manager, and the company_code is the code of the working company.

TABLE EMPLOYEE

Column               |    Type
                     |
MANAGER_CODE         |    STRING
SENIOR_MANAGER_CODE  |    STRING  
LEAD_MANAGER_CODE    |    STRING
COMPANY_CODE         |    STRING

Employee: The employee_code is the code of the employee, the manager_code is the code of its manager, the senior_manager_code is the code of its senior manager, the lead_manager_code is the code of its lead manager, and the company_code is the code of the working company.

TABLE EMPLOYEE

Column               |    Type
                     |
EMPLOYEE_CODE        |    STRING
MANAGER_CODE         |    STRING
SENIOR_MANAGER_CODE  |    STRING  
LEAD_MANAGER_CODE    |    STRING
COMPANY_CODE         |    STRING
*/

SELECT c.COMPANY_CODE, c.FOUNDER,COUNT(DISTINCT l.LEAD_MANAGER_CODE),COUNT(DISTINCT s.SENIOR_MANAGER_CODE),COUNT(DISTINCT m.MANAGER_CODE),COUNT(DISTINCT e.EMPLOYEE_CODE) FROM COMPANY AS c
INNER JOIN LEAD_MANAGER AS l ON l.COMPANY_CODE = c.COMPANY_CODE
INNER JOIN SENIOR_MANAGER AS s ON s.COMPANY_CODE = c.COMPANY_CODE
INNER JOIN MANAGER AS m ON m.COMPANY_CODE = c.COMPANY_CODE
INNER JOIN EMPLOYEE AS e ON e.COMPANY_CODE = c.COMPANY_CODE
GROUP BY c.COMPANY_CODE, c.FOUNDER ORDER BY c.COMPANY_CODE ASC;
