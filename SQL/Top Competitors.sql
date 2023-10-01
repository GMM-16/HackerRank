/*
Julia just finished conducting a coding contest, and she needs your help assembling the leaderboard! Write a query to print the respective hacker_id and name of hackers who achieved full scores for more than one challenge. Order your output in descending order by the total number of challenges in which the hacker earned a full score. If more than one hacker received full scores in same number of challenges, then sort them by ascending hacker_id.
The following tables contain contest data:

Hackers: The hacker_id is the id of the hacker, and name is the name of the hacker.

Column      |    Type
            |
HACKER_ID   |    INTEGER
NAME        |    STRING

Difficulty: The difficult_level is the level of difficulty of the challenge, and score is the score of the challenge for the difficulty level.

Column            |    Type
                  |
DIFFICULTY_LEVEL  |    INTEGER
SCORE             |    INTEGER

Challenges: The challenge_id is the id of the challenge, the hacker_id is the id of the hacker who created the challenge, and difficulty_level is the level of difficulty of the challenge.

Column            |    Type
                  |
CHALLENGE_ID      |    INTEGER
HACKER_ID         |    INTEGER
DIFFICULTY_LEVEL  |    INTEGER

Submissions: The submission_id is the id of the submission, hacker_id is the id of the hacker who made the submission, challenge_id is the id of the challenge that the submission belongs to, and score is the score of the submission.

Column          |    Type
                |
SUBMISSION_ID   |    INTEGER
HACKER_ID       |    INTEGER
CHALLENGE_ID    |    INTEGER
SCORE           |    INTEGER
*/

SELECT SUBMISSIONS.HACKER_ID, HACKERS.NAME FROM HACKERS
INNER JOIN SUBMISSIONS ON SUBMISSIONS.HACKER_ID = HACKERS.HACKER_ID
INNER JOIN CHALLENGES ON SUBMISSIONS.CHALLENGE_ID = CHALLENGES.CHALLENGE_ID
INNER JOIN DIFFICULTY ON DIFFICULTY.DIFFICULTY_LEVEL = CHALLENGES.DIFFICULTY_LEVEL
WHERE SUBMISSIONS.SCORE = DIFFICULTY.SCORE
GROUP BY SUBMISSIONS.HACKER_ID, HACKERS.NAME
HAVING COUNT(CHALLENGES.CHALLENGE_ID) > 1
ORDER BY COUNT(CHALLENGES.CHALLENGE_ID) DESC, HACKERS.HACKER_ID;
