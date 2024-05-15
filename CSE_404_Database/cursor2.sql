set serveroutput on;

declare
  cursor em is select * from employees;
  em2 em%rowtype;

begin
  open em;
  loop
    fetch em into em2;
    exit when em%notfound;
    dbms_output.put_line(em2.employee_id);
  end loop;
end;
/