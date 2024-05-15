set serveroutput on;
declare
  a number:=5;
begin
loop
dbms_output.put_line(a);
if a=10
then exit;
end if;
a:=a+1;
end loop;
end;
/

declare 
a number:=10;
begin 
loop
dbms_output.put_line(a);
if a=5
then exit;
end if;
a:=a-1;
end loop;
end;
/

declare 
a number:=10;
begin 
loop
dbms_output.put_line(a);
exit when a=5;
a:=a-1;
end loop;
end;
/