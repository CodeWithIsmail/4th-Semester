set serveroutput on;
declare
i number:=1;
begin
while i<11
loop
dbms_output.put_line(i);
i:=i+1;
end loop;
end;
/