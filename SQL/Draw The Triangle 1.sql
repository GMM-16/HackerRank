/*
P(R) represents a pattern drawn by Julia in R rows. The following pattern represents P(5):
* * * * * 
* * * * 
* * * 
* * 
*
Write a query to print the pattern P(20).
*/

DELIMITER @@
CREATE PROCEDURE TEMP(R INT)
BEGIN
    DECLARE I INT DEFAULT R;
    WHILE I > 0 DO
        SELECT IF(I = 1,"*",REPEAT('* ',I));
        SET I = I - 1;
    END WHILE;
END @@
DELIMITER ;
CALL TEMP(20)
