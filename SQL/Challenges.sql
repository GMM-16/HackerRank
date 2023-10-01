/*
Julia asked her students to create some coding challenges. Write a query to print the hacker_id, name, and the total number of challenges created by each student. Sort your results by the total number of challenges in descending order. If more than one student created the same number of challenges, then sort the result by hacker_id. If more than one student created the same number of challenges and the count is less than the maximum number of challenges created, then exclude those students from the result.
The following tables contain challenge data:

Hackers: The hacker_id is the id of the hacker, and name is the name of the hacker.

Column      |    Type
            |    
HACKER_ID   |    INTEGER
NAME        |    STRING

Challenges: The challenge_id is the id of the challenge, and hacker_id is the id of the student who created the challenge.

Column        |    Type
              |  
CHALLENGE_ID  |    INTEGER
HACKER_ID     |    INTEGER
*/

WITH TOTAL_NUMBER AS (SELECT HACKER_ID,COUNT(*) AS TOTAL_CHALLENGE FROM CHALLENGES GROUP BY HACKER_ID) SELECT HACKERS.HACKER_ID,HACKERS.NAME,TN.TOTAL_CHALLENGE FROM HACKERS JOIN TOTAL_NUMBER AS TN ON TN.HACKER_ID = HACKERS.HACKER_ID WHERE
    CASE
        WHEN TN.TOTAL_CHALLENGE = (SELECT MAX(TOTAL_CHALLENGE) FROM TOTAL_NUMBER)
            THEN TRUE
        ELSE
            NOT EXISTS (SELECT 1 FROM TOTAL_NUMBER WHERE TOTAL_CHALLENGE = TN.TOTAL_CHALLENGE AND HACKER_ID != TN.HACKER_ID)
    END    
ORDER BY TN.TOTAL_CHALLENGE DESC, HACKERS.HACKER_ID;
