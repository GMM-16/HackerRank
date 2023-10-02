/*
You are given a table, Functions, containing two columns: X and Y.

Column    |    Type
          |
X         |    INTEGER
Y         |    INTEGER

Two pairs (X1, Y1) and (X2, Y2) are said to be symmetric pairs if X1 = Y2 and X2 = Y1.
Write a query to output all such symmetric pairs in ascending order by the value of X. List the rows such that X1 <= Y1.
*/

SELECT A.X,A.Y FROM FUNCTIONS A INNER JOIN FUNCTIONS B ON A.X=B.Y AND A.Y=B.X WHERE A.X<=A.Y GROUP BY A.X,A.Y HAVING COUNT(*)>1 OR A.X!=A.Y ORDER BY A.X
