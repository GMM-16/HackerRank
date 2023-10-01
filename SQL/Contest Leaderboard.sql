/*
You did such a great job helping Julia with her last coding contest challenge that she wants you to work on this one, too!
The total score of a hacker is the sum of their maximum scores for all of the challenges. Write a query to print the hacker_id, name, and total score of the hackers ordered by the descending score. If more than one hacker achieved the same total score, then sort the result by ascending hacker_id. Exclude all hackers with a total score of 0 from your result.
The following tables contain contest data:

Hackers: The hacker_id is the id of the hacker, and name is the name of the hacker.

Column      |    Type
            |
HACKER_ID   |    INTEGER
NAME        |    STRING

Submissions: The submission_id is the id of the submission, hacker_id is the id of the hacker who made the submission, challenge_id is the id of the challenge for which the submission belongs to, and score is the score of the submission.

Column          |    Type
                |
SUBMISSION_ID   |    INTEGER
HACKER_ID       |    INTEGER
CHALLENGE_ID    |    INTEGER
SCORE           |    INTEGER
*/

SELECT HACKER_ID, NAME, SUM(MAX_SCORE) TOTAL_SCORE FROM (SELECT SUBMISSIONS.HACKER_ID, NAME, CHALLENGE_ID, MAX(SCORE) MAX_SCORE FROM SUBMISSIONS JOIN HACKERS ON SUBMISSIONS.HACKER_ID = HACKERS.HACKER_ID GROUP BY HACKER_ID, NAME, CHALLENGE_ID)TEMP GROUP BY HACKER_ID, NAME HAVING TOTAL_SCORE > 0 ORDER BY TOTAL_SCORE DESC, HACKER_ID;
