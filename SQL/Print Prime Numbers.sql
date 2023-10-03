/*
Write a query to print all prime numbers less than or equal to 1000. Print your result on a single line, and use the ampersand (&) character as your separator (instead of a space).
*/

DELIMITER @@
CREATE PROCEDURE PRIME()
BEGIN
    DECLARE I INT DEFAULT 2;
    DECLARE J INT;
    DECLARE STR VARCHAR(10000);
    DECLARE FLAG BOOLEAN;
    SET STR="";
    WHILE I<1001 DO
    SET FLAG=TRUE;
    SET J=2;
    WHILE J<=SQRT(I) DO
    IF I%J=0
    THEN SET FLAG=FALSE;
    END IF;
    SET J=J+1;
    END WHILE;
    IF FLAG=TRUE
    THEN SET STR=CONCAT(STR,I,"&");
    END IF;
    SET I=I+1;
    END WHILE;
    SET STR = SUBSTRING(STR, 1, LENGTH(STR) - 1);
    SELECT STR;
END @@
DELIMITER ;
CALL PRIME()
