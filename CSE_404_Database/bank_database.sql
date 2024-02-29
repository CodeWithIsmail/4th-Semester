/*
drop table borrower;
drop table depositor;
drop table loan;
drop table account;
drop table customer;
drop table branch;


CREATE TABLE BRANCH(
   BRANCH_NAME VARCHAR2(20) NOT NULL,
   BRANCH_CITY VARCHAR2(20) NOT NULL,
   ASSETS NUMBER NOT NULL,
   CONSTRAINT BRANCH_PK PRIMARY KEY (BRANCH_NAME)
);

CREATE TABLE CUSTOMER(
    CUSTOMER_NAME VARCHAR2(20) NOT NULL,
    CUSTOMER_STREET VARCHAR2(20) NOT NULL,
    CUSTOMER_CITY VARCHAR2(20) NOT NULL,
    CONSTRAINT CUSTOMER_PK PRIMARY KEY (CUSTOMER_NAME)
);

CREATE TABLE ACCOUNT(
    ACCOUNT_NUMBER VARCHAR2(10) NOT NULL,
    BRANCH_NAME VARCHAR2(20) NOT NULL,
    BALANCE NUMBER NOT NULL,
    CONSTRAINT ACCOUNT_PK PRIMARY KEY (ACCOUNT_NUMBER),
    CONSTRAINT ACCOUNT_FK FOREIGN KEY (BRANCH_NAME) REFERENCES BRANCH (BRANCH_NAME)
);

CREATE TABLE LOAN(
     LOAN_NUMBER VARCHAR2(10) NOT NULL,
     BRANCH_NAME VARCHAR2(30) NOT NULL, 
     AMOUNT NUMBER NOT NULL,
     CONSTRAINT LOAN_PK PRIMARY KEY(LOAN_NUMBER),
     CONSTRAINT LOAN_FK FOREIGN KEY(BRANCH_NAME) REFERENCES BRANCH(BRANCH_NAME)
);

CREATE TABLE DEPOSITOR(
     CUSTOMER_NAME VARCHAR2(20) NOT NULL,
     ACCOUNT_NUMBER VARCHAR2(10) NOT NULL,
     CONSTRAINT DEPOSITOR_PK PRIMARY KEY (CUSTOMER_NAME,ACCOUNT_NUMBER),
     CONSTRAINT DEPOSITOR_FK1 FOREIGN KEY(CUSTOMER_NAME) REFERENCES CUSTOMER(CUSTOMER_NAME),
     CONSTRAINT DEPOSITOR_FK2 FOREIGN KEY(ACCOUNT_NUMBER) REFERENCES ACCOUNT(ACCOUNT_NUMBER)
);

CREATE TABLE BORROWER(
      CUSTOMER_NAME VARCHAR2(20) NOT NULL,
      LOAN_NUMBER VARCHAR2(10) NOT NULL,
      CONSTRAINT BORROWER_PK PRIMARY KEY(CUSTOMER_NAME, LOAN_NUMBER),
      CONSTRAINT BORROWER_FK1 FOREIGN KEY(CUSTOMER_NAME) REFERENCES CUSTOMER(CUSTOMER_NAME),
      CONSTRAINT BORROWER_FK2 FOREIGN KEY(LOAN_NUMBER) REFERENCES LOAN(LOAN_NUMBER)
);

INSERT INTO BRANCH (BRANCH_NAME, BRANCH_CITY, ASSETS) VALUES ('Brighton', 'Brooklyn', 7100000); 
INSERT INTO BRANCH (BRANCH_NAME, BRANCH_CITY, ASSETS) VALUES ('Downtown', 'Brooklyn', 9000000);
INSERT INTO BRANCH (BRANCH_NAME, BRANCH_CITY, ASSETS) VALUES ('Mianus', 'Horseneck', 400000);
INSERT INTO BRANCH (BRANCH_NAME, BRANCH_CITY, ASSETS) VALUES ('North Town', 'Rye', 3700000);
INSERT INTO BRANCH (BRANCH_NAME, BRANCH_CITY, ASSETS) VALUES ('Perryridge', 'Horseneck', 1700000);
INSERT INTO BRANCH (BRANCH_NAME, BRANCH_CITY, ASSETS) VALUES ('Pownal', 'Bennington', 300000);
INSERT INTO BRANCH (BRANCH_NAME, BRANCH_CITY, ASSETS) VALUES ('Redwood', 'Palo Alto', 2100000);
INSERT INTO BRANCH (BRANCH_NAME, BRANCH_CITY, ASSETS) VALUES ('Round Hill', 'Horseneck', 8000000);

INSERT INTO CUSTOMER (CUSTOMER_NAME, CUSTOMER_STREET, CUSTOMER_CITY) VALUES ('Adams', 'Spring', 'Pittsfield');
INSERT INTO CUSTOMER (CUSTOMER_NAME, CUSTOMER_STREET, CUSTOMER_CITY) VALUES ('Brooks', 'Senator', 'Brooklyn');
INSERT INTO CUSTOMER (CUSTOMER_NAME, CUSTOMER_STREET, CUSTOMER_CITY) VALUES ('Curry', 'North', 'Rye');
INSERT INTO CUSTOMER (CUSTOMER_NAME, CUSTOMER_STREET, CUSTOMER_CITY) VALUES ('Glenn', 'Sand Hill', 'Woodside');
INSERT INTO CUSTOMER (CUSTOMER_NAME, CUSTOMER_STREET, CUSTOMER_CITY) VALUES ('Green', 'Walnut', 'Stamford');
INSERT INTO CUSTOMER (CUSTOMER_NAME, CUSTOMER_STREET, CUSTOMER_CITY) VALUES ('Hayes', 'Main', 'Harrison');
INSERT INTO CUSTOMER (CUSTOMER_NAME, CUSTOMER_STREET, CUSTOMER_CITY) VALUES ('Johnson', 'Alma', 'Palo Alto');
INSERT INTO CUSTOMER (CUSTOMER_NAME, CUSTOMER_STREET, CUSTOMER_CITY) VALUES ('Jones', 'Main', 'Harrison');
INSERT INTO CUSTOMER (CUSTOMER_NAME, CUSTOMER_STREET, CUSTOMER_CITY) VALUES ('Lindsay', 'Park', 'Pittsfield');
INSERT INTO CUSTOMER (CUSTOMER_NAME, CUSTOMER_STREET, CUSTOMER_CITY) VALUES ('Smith', 'North', 'Rye');
INSERT INTO CUSTOMER (CUSTOMER_NAME, CUSTOMER_STREET, CUSTOMER_CITY) VALUES ('Turner', 'Putnam', 'Stampford');
INSERT INTO CUSTOMER (CUSTOMER_NAME, CUSTOMER_STREET, CUSTOMER_CITY) VALUES ('Williams', 'Nassau', 'Princeton');

INSERT INTO ACCOUNT (ACCOUNT_NUMBER, BRANCH_NAME, BALANCE) VALUES ('A-101', 'Downtown', 500);
INSERT INTO ACCOUNT (ACCOUNT_NUMBER, BRANCH_NAME, BALANCE) VALUES ('A-102', 'Perryridge', 400);
INSERT INTO ACCOUNT (ACCOUNT_NUMBER, BRANCH_NAME, BALANCE) VALUES ('A-201', 'Brighton', 900);
INSERT INTO ACCOUNT (ACCOUNT_NUMBER, BRANCH_NAME, BALANCE) VALUES ('A-215', 'Mianus', 700);
INSERT INTO ACCOUNT (ACCOUNT_NUMBER, BRANCH_NAME, BALANCE) VALUES ('A-217', 'Brighton', 750);
INSERT INTO ACCOUNT (ACCOUNT_NUMBER, BRANCH_NAME, BALANCE) VALUES ('A-222', 'Redwood', 700);
INSERT INTO ACCOUNT (ACCOUNT_NUMBER, BRANCH_NAME, BALANCE) VALUES ('A-305', 'Round Hill', 350);
INSERT INTO ACCOUNT (ACCOUNT_NUMBER, BRANCH_NAME, BALANCE) VALUES ('A-322', 'Perryridge', 500);

INSERT INTO LOAN (LOAN_NUMBER, BRANCH_NAME, AMOUNT) VALUES ('L-11', 'Round Hill', 900);
INSERT INTO LOAN (LOAN_NUMBER, BRANCH_NAME, AMOUNT) VALUES ('L-14', 'Downtown', 1500);
INSERT INTO LOAN (LOAN_NUMBER, BRANCH_NAME, AMOUNT) VALUES ('L-15', 'Perryridge', 1500);
INSERT INTO LOAN (LOAN_NUMBER, BRANCH_NAME, AMOUNT) VALUES ('L-16', 'Perryridge', 1300);
INSERT INTO LOAN (LOAN_NUMBER, BRANCH_NAME, AMOUNT) VALUES ('L-17', 'Downtown', 1000);
INSERT INTO LOAN (LOAN_NUMBER, BRANCH_NAME, AMOUNT) VALUES ('L-23', 'Redwood', 2000);
INSERT INTO LOAN (LOAN_NUMBER, BRANCH_NAME, AMOUNT) VALUES ('L-93', 'Mianus', 500);

INSERT INTO DEPOSITOR (CUSTOMER_NAME, ACCOUNT_NUMBER) VALUES ('Hayes', 'A-102');
INSERT INTO DEPOSITOR (CUSTOMER_NAME, ACCOUNT_NUMBER) VALUES ('Johnson', 'A-101');
INSERT INTO DEPOSITOR (CUSTOMER_NAME, ACCOUNT_NUMBER) VALUES ('Johnson', 'A-201');
INSERT INTO DEPOSITOR (CUSTOMER_NAME, ACCOUNT_NUMBER) VALUES ('Jones', 'A-217');
INSERT INTO DEPOSITOR (CUSTOMER_NAME, ACCOUNT_NUMBER) VALUES ('Adams', 'A-322');
INSERT INTO DEPOSITOR (CUSTOMER_NAME, ACCOUNT_NUMBER) VALUES ('Smith', 'A-215');
INSERT INTO DEPOSITOR (CUSTOMER_NAME, ACCOUNT_NUMBER) VALUES ('Turner', 'A-305');

INSERT INTO BORROWER (CUSTOMER_NAME, LOAN_NUMBER) VALUES ('Adams', 'L-16');
INSERT INTO BORROWER (CUSTOMER_NAME, LOAN_NUMBER) VALUES ('Curry', 'L-93');
INSERT INTO BORROWER (CUSTOMER_NAME, LOAN_NUMBER) VALUES ('Hayes', 'L-15');
INSERT INTO BORROWER (CUSTOMER_NAME, LOAN_NUMBER) VALUES ('Glenn', 'L-14');
INSERT INTO BORROWER (CUSTOMER_NAME, LOAN_NUMBER) VALUES ('Jones', 'L-17');
INSERT INTO BORROWER (CUSTOMER_NAME, LOAN_NUMBER) VALUES ('Smith', 'L-11');
INSERT INTO BORROWER (CUSTOMER_NAME, LOAN_NUMBER) VALUES ('Smith', 'L-23');
INSERT INTO BORROWER (CUSTOMER_NAME, LOAN_NUMBER) VALUES ('Williams', 'L-17');

commit;
select * from tab;

DESCRIBE BRANCH;
SELECT * FROM BRANCH;
DESCRIBE CUSTOMER;
SELECT * FROM CUSTOMER;
DESCRIBE ACCOUNT;
SELECT * FROM ACCOUNT;
DESCRIBE LOAN;
SELECT * FROM LOAN;
DESCRIBE DEPOSITOR;
SELECT * FROM DEPOSITOR;
DESCRIBE BORROWER;
SELECT * FROM BORROWER;

*/
--select branch_name Branch , count(distinct customer_name) "Number of borrower" from loan, borrower where loan.loan_number=borrower.loan_number group by branch_name;

--select loan.loan_number "Loan Number" , count(distinct customer_name) "Number of borrower" from loan,borrower where loan.loan_number=borrower.loan_number group by loan.loan_number; 

--select customer_name Name , count(distinct loan.loan_number) from loan,borrower where loan.loan_number=borrower.loan_number group by customer_name;

--select branch_name Branch , avg(balance) Average from account group by branch_name having avg(balance) > 500;

--select branch_name Branch, count(distinct customer_name) from account,depositor where account.account_number = depositor.account_number group by branch_name having count(distinct customer_name) > 1;

--(select distinct customer_name from depositor) intersect (select distinct customer_name from borrower);

--select distinct customer_name from depositor where customer_name in (select customer_name from borrower);

--select distinct customer_name from borrower where customer_name not in (select customer_name from depositor);

--select distinct customer_name from borrower minus select distinct customer_name from depositor;

--select distinct customer_name from borrower intersect select distinct customer_name from depositor intersect select distinct customer_name from borrower , loan where loan.loan_number=borrower.loan_number and branch_name='Perryridge';

--select distinct customer_name from loan, borrower where loan.loan_number=borrower.loan_number and branch_name='Perryridge' and customer_name in (select customer_name from account,depositor where account.account_number=depositor.account_number and branch_name='Perryridge');
/*
select distinct customer_name 
    from borrower,loan
       where borrower.loan_number=loan.loan_number 
         and branch_name='Perryridge' 
         and customer_name 
            in (select customer_name 
                from depositor,account
                 where depositor.account_number=account.account_number  
                   and branch_name='Perryridge');


select count(distinct customer_name) 
   from depositor,account
    where depositor.account_number=account.account_number
      and branch_name='Perryridge' 
      and (customer_name,branch_name) in
        (select customer_name, branch_name 
           from borrower, loan 
           where borrower.loan_number=loan.loan_number);
*/

--select distinct T.branch_name Branch from branch T , branch Z where T.assets>Z.assets and Z.branch_city='Brooklyn';

--select branch_name from branch where assets > some (select assets from branch where branch_city='Brooklyn');

--select branch_name from branch where assets > all (select assets from branch where branch_city='Rye');

--select branch_name from branch where assets > (select max  (assets) from branch where branch_city='Rye');

--select max  (assets) from branch where branch_city='Rye';
--select * from branch;


--select * from tab;
--alter table branch rename column name to branch_name;
--alter table branch rename column branch_name to name;
--alter table branch drop column branch_type;
--describe branch;
--alter table branch add branch_type varchar2(20);

--(select customer_name from borrower) union all (select customer_name from depositor);
--select customer_name from depositor intersect select customer_name from borrower;

--select avg(balance) Average , min(balance) Min_Balance, max(balance) Max_Balance, sum(balance) Sum , count(*) "Number of account" from account;

--select branch_name Branch , count(distinct customer_name) "Number of depositor" from depositor D, account A where D.account_number=A.account_number group by branch_name;

--select branch_name ,sum(balance), count(*), avg (balance) from account group by branch_name; 

--select max(avg (balance)) from account group by branch_name;

--select distinct customer_name from depositor where customer_name in (select customer_name from borrower); 

--select distinct customer_name from borrower where customer_name not in (select customer_name from depositor);

--select distinct customer_name from borrower,loan where borrower.loan_number=loan.loan_number and branch_name='Perryridge' and (customer_name,branch_name) in (select customer_name,branch_name from depositor,account where depositor.account_number=account.account_number);

SELECT BRANCH_NAME , COUNT(*) FROM ACCOUNT A WHERE A.BALANCE=(SELECT MAX(BALANCE) FROM ACCOUNT B GROUP BY BRANCH_NAME and A.BRANCH_NAME=B.BRANCH_NAME) GROUP BY BRANCH_NAME;

