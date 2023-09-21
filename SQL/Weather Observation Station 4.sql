/*
Find the difference between the total number of CITY entries in the table and the number of distinct CITY entries in the table.
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

SELECT COUNT(CITY) - COUNT(DISTINCT CITY) FROM STATION
