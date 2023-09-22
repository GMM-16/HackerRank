/*
Query the list of CITY names ending with vowels (a, e, i, o, u) from STATION. Your result cannot contain duplicates.
The STATION table is described as follows:

TABLE STATION

Field    |    Type

ID       |    NUMBER
CITY     |    VARCHAR2(21)
STATE    |    VARCHAR2(2)
LAT_N    |    NUMBER
LONG_W   |    NUMBER

where LAT_N is the northern latitude and LONG_W is the western longitude.
*/

SELECT DISTINCT CITY FROM STATION WHERE CITY LIKE '%A' OR CITY LIKE '%E' OR CITY LIKE '%I' OR CITY LIKE '%O' OR CITY LIKE '%U'
