set serveroutput on;

declare 
  a number:=&a;
begin
  if mod(a,2)=1
  then 
      dbms_output.put_line(' ODD ');
  else
      dbms_output.put_line(' EVEN ');
  end if;
end;
/
      