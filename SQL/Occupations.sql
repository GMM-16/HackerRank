/*
Pivot the Occupation column in OCCUPATIONS so that each Name is sorted alphabetically and displayed underneath its corresponding Occupation. The output column headers should be Doctor, Professor, Singer, and Actor, respectively.
Note: Print NULL when there are no more names corresponding to an occupation.
The OCCUPATIONS table is described as follows:

TABLE OCCUPATIONS

Column      |    Type
            |
Name        |    STRING
Occupation  |    STRING

Occupation will only contain one of the following values: Doctor, Professor, Singer or Actor.
*/

SELECT MAX(DOCTOR) AS DOCTOR, MAX(PROFESSOR) AS PROFESSOR, MAX(SINGER) AS SINGER, MAX(ACTOR) AS ACTOR
FROM (
    SELECT 
    IF(OCCUPATION='Doctor', NAME, NULL) AS DOCTOR, 
    IF(OCCUPATION='Professor', NAME, NULL) AS PROFESSOR,
    IF(OCCUPATION='Singer', NAME, NULL) AS SINGER, 
    IF(OCCUPATION='Actor', NAME, NULL) AS ACTOR,
    ROW_NUMBER() OVER(PARTITION BY OCCUPATION ORDER BY NAME) AS ROW_NUM
    FROM OCCUPATIONS
) TEMP
GROUP BY ROW_NUM;
