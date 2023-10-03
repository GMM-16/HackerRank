/*
Julia conducted a 15 days of learning SQL contest. The start date of the contest was March 01, 2016 and the end date was March 15, 2016.
Write a query to print total number of unique hackers who made at least 1 submission each day (starting on the first day of the contest), and find the hacker_id and name of the hacker who made maximum number of submissions each day. If more than one such hacker has a maximum number of submissions, print the lowest hacker_id. The query should print this information for each day of the contest, sorted by the date.
The following tables hold contest data:

Hackers: The hacker_id is the id of the hacker, and name is the name of the hacker.

Column      |    Type
            |
HACKER_ID   |    INTEGER
NAME        |    STRING

Submissions: The submission_date is the date of the submission, submission_id is the id of the submission, hacker_id is the id of the hacker who made the submission, and score is the score of the submission.

Column            |    Type
                  |
SUBMISSION_DATE   |    DATE
SUBMISSION_ID     |    INTEGER
HACKER_ID         |    INTEGER
SCORE             |    INTEGER
*/

SELECT A.SUBMISSION_DATE, A.NUM_UNIQUE, A.HACKER_ID, H.NAME FROM ( SELECT S.SUBMISSION_DATE, ( SELECT COUNT(DISTINCT S1.HACKER_ID) FROM SUBMISSIONS AS S1 WHERE S1.SUBMISSION_DATE = S.SUBMISSION_DATE AND ( SELECT COUNT(DISTINCT S2.SUBMISSION_DATE) FROM SUBMISSIONS AS S2 WHERE S2.SUBMISSION_DATE < S1.SUBMISSION_DATE AND S2.HACKER_ID = S1.HACKER_ID ) = DATEDIFF(S.SUBMISSION_DATE, (SELECT MIN(S3.SUBMISSION_DATE) FROM SUBMISSIONS AS S3)) ) AS NUM_UNIQUE, ( SELECT S4.HACKER_ID FROM SUBMISSIONS AS S4 WHERE S4.SUBMISSION_DATE = S.SUBMISSION_DATE GROUP BY S4.HACKER_ID ORDER BY COUNT(*) DESC, S4.HACKER_ID LIMIT 1 ) AS HACKER_ID FROM ( SELECT DISTINCT A.SUBMISSION_DATE FROM SUBMISSIONS AS A ) AS S ) AS A JOIN HACKERS AS H ON A.HACKER_ID = H.HACKER_ID ORDER BY A.SUBMISSION_DATE; 
