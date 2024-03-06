/*
CREATE TABLE TAKEN(
     STUDENT VARCHAR2(15) NOT NULL,
     COURSE  VARCHAR2(30) NOT NULL
);

INSERT INTO TAKEN (STUDENT,COURSE) VALUES ('Robert','Databases');
INSERT INTO TAKEN (STUDENT,COURSE) VALUES ('Robert','Programming Languages');
INSERT INTO TAKEN (STUDENT,COURSE) VALUES ('Susie','Databases');
INSERT INTO TAKEN (STUDENT,COURSE) VALUES ('Susie','Operating Systems');
INSERT INTO TAKEN (STUDENT,COURSE) VALUES ('Julie','Programming Languages');
INSERT INTO TAKEN (STUDENT,COURSE) VALUES ('Julie','Machine Learning');
INSERT INTO TAKEN (STUDENT,COURSE) VALUES ('Emilie','Operating Systems');


CREATE TABLE REQUIRED(
     COURSE VARCHAR2(30) NOT NULL
);

INSERT INTO REQUIRED (COURSE) VALUES ('Databases');
INSERT INTO REQUIRED (COURSE) VALUES ('Programming Languages');

*/
--SELECT DISTINCT STUDENT FROM TAKEN WHERE COURSE IN (SELECT COURSE FROM REQUIRED);
/*
SELECT STUDENT FROM TAKEN
MINUS 
SELECT STUDENT FROM(
SELECT STUDENT, COURSE
FROM (SELECT STUDENT FROM TAKEN),REQUIRED
MINUS
SELECT STUDENT,COURSE FROM TAKEN);
*/

--select customer_name,branch_name from depositor,account where account.account_number=depositor.account_number and branch_name in(select branch_name from branch where branch_city='Brooklyn') group by customer_name,branch_name;