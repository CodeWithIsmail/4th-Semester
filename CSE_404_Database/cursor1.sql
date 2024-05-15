set serveroutput on;
declare 
employee_cursor employees%rowtype;
begin
select * 
into employee_cursor 
from employees
where employee_id=156;

dbms_output.put_line(employee_cursor.first_name);

exception
when no_data_found
then
raise_application_error(-2001,'no data');
end;
/