/*
Samantha interviews many candidates from different colleges using coding challenges and contests. Write a query to print the contest_id, hacker_id, name, and the sums of total_submissions, total_accepted_submissions, total_views, and total_unique_views for each contest sorted by contest_id. Exclude the contest from the result if all four sums are 0.
Note: A specific contest can be used to screen candidates at more than one college, but each college only holds 1 screening contest.

The following tables hold interview data:

Contests: The contest_id is the id of the contest, hacker_id is the id of the hacker who created the contest, and name is the name of the hacker.

Column      |    Type
            |
CONTEST_ID  |    INTEGER
HACKER_ID   |    INTEGER
NAME        |    STRING

Colleges: The college_id is the id of the college, and contest_id is the id of the contest that Samantha used to screen the candidates.

Column      |    Type
            |
COLLEGE_ID  |    INTEGER
CONTEST_ID  |    INTEGER

Challenges: The challenge_id is the id of the challenge that belongs to one of the contests whose contest_id Samantha forgot, and college_id is the id of the college where the challenge was given to candidates.

Column        |    Type
              |
CHALLENGE_ID  |    INTEGER
COLLEGE_ID    |    INTEGER

View_Stats: The challenge_id is the id of the challenge, total_views is the number of times the challenge was viewed by candidates, and total_unique_views is the number of times the challenge was viewed by unique candidates.

Column              |    Type
                    |
CHALLENGE_ID        |    INTEGER
TOTAL_VIEWS         |    INTEGER
TOTAL_UNIQUE_VIEWS  |    INTEGER

Submission_Stats: The challenge_id is the id of the challenge, total_submissions is the number of submissions for the challenge, and total_accepted_submission is the number of submissions that achieved full scores.

Column                      |    Type
                            |
CHALLENGE_ID                |    INTEGER
TOTAL_SUBMISSIONS           |    INTEGER
TOTAL_ACCEPTED_SUBMISSIONS  |    INTEGER
*/

SELECT CONTESTS.CONTEST_ID, CONTESTS.HACKER_ID, CONTESTS.NAME, SUM(SUBMISSION_STATS.TOTAL_SUBMISSIONS),SUM(SUBMISSION_STATS.TOTAL_ACCEPTED_SUBMISSIONS), SUM(VIEW_STATS.TOTAL_VIEWS), SUM(VIEW_STATS.TOTAL_UNIQUE_VIEWS) FROM CONTESTS JOIN COLLEGES ON CONTESTS.CONTEST_ID = COLLEGES.CONTEST_ID JOIN CHALLENGES ON COLLEGES.COLLEGE_ID = CHALLENGES.COLLEGE_ID LEFT JOIN (SELECT CHALLENGE_ID, SUM(TOTAL_VIEWS) AS TOTAL_VIEWS, SUM(TOTAL_UNIQUE_VIEWS) AS TOTAL_UNIQUE_VIEWS FROM VIEW_STATS GROUP BY CHALLENGE_ID) VIEW_STATS ON CHALLENGES.CHALLENGE_ID = VIEW_STATS.CHALLENGE_ID LEFT JOIN (SELECT CHALLENGE_ID, SUM(TOTAL_SUBMISSIONS) AS TOTAL_SUBMISSIONS, SUM(TOTAL_ACCEPTED_SUBMISSIONS) AS TOTAL_ACCEPTED_SUBMISSIONS FROM SUBMISSION_STATS GROUP BY CHALLENGE_ID) SUBMISSION_STATS ON CHALLENGES.CHALLENGE_ID = SUBMISSION_STATS.CHALLENGE_ID GROUP BY  CONTESTS.CONTEST_ID, CONTESTS.HACKER_ID, CONTESTS.NAME HAVING SUM(SUBMISSION_STATS.TOTAL_SUBMISSIONS) + SUM(SUBMISSION_STATS.TOTAL_ACCEPTED_SUBMISSIONS) + SUM(VIEW_STATS.TOTAL_VIEWS)+ SUM(VIEW_STATS.TOTAL_UNIQUE_VIEWS) > 0 ORDER BY CONTESTS.CONTEST_ID;
