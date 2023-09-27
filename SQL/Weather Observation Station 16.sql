/*
Query the smallest Northern Latitude (LAT_N) from STATION that is greater than 38.7880. Round your answer to 4 decimal places.
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

SELECT ROUND(MIN(LAT_N),4) FROM STATION WHERE LAT_N > 38.7880
