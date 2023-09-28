/*
Query the greatest value of the Northern Latitudes (LAT_N) from STATION that is less than 137.2345. Truncate your answer to 4 decimal places.
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

SELECT ROUND(MAX(LAT_N),4) FROM STATION WHERE LAT_N < 137.2345