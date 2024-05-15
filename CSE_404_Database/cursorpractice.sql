declare 
nam employees.first_name%rowtype;
salary employees.salary%rowtype;
cursor em is
select first_name , salary from employees;
begin
open em;
loop
  fetch em into nam,salary;
  exit when em%notfound;
end loop;
close em;
end;
/