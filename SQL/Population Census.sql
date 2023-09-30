/*
Given the CITY and COUNTRY tables, query the sum of the populations of all cities where the CONTINENT is 'Asia'.
Note: CITY.CountryCode and COUNTRY.Code are matching key columns.
The CITY and COUNTRY tables are described as follows:

TABLE CITY

Field           |    Type
                |
ID              |    NUMBER
NAME            |    VARCHAR2(17)
COUNTRYCODE     |    VARCHAR2(3)
DISTRICT        |    VARCHAR2(20)
POPULATION      |    NUMBER

TABLE COUNTRY

Field           |    Type
                |
CODE            |    VARCHAR2(3)
NAME            |    VARCHAR2(44)
CONTINENT       |    VARCHAR2(13)
REGION          |    VARCHAR2(25)
SURFACEAREA     |    NUMBER
INDEPYEAR       |    VARCHAR2(25)
POPULATION      |    NUMBER
LIFEEXPECTANCY  |    VARCHAR2(4)
GNP             |    NUMBER
GNPOLD          |    VARCHAR2(9)
LOCALNAME       |    VARCHAR2(44)
GOVERNMENTFROM  |    VARCHAR2(44)
HEADOFSTATE     |    VARCHAR2(32)
CAPITAL         |    VARCHAR2(4)
CODE2           |    VARCHAR2(2)

*/

SELECT SUM(CITY.POPULATION) FROM CITY JOIN COUNTRY ON CITY.COUNTRYCODE = COUNTRY.CODE WHERE CONTINENT = 'ASIA' 
