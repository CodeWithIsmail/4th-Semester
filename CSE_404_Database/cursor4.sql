create table employee(
    name varchar2(20) not null,
    salary number not null
);

declare 
  cursor em is 
  select * from employees;

begin 
  for i in em
  loop 
    insert into employee 
    values (i.first_name,i.salary);
  end loop;
end;
/