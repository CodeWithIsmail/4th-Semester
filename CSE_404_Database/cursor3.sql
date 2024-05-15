set serveroutput on;
create table employee 
(
    name varchar2(20) not null,
    salary number not null
);
declare 
  cursor em is select * from employees;
  em2 em%rowtype;
begin
  open em;
  fetch em into em2;
  while em%found
  loop
   if em2.salary*12>12000
   then 
    insert into employee values(em2.first_name,em2.salary*12);
   end if;
  fetch em into em2;
  end loop;
  close em;



end;
/