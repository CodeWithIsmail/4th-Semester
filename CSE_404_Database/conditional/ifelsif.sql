set serveroutput on;
declare
   a number:=&a;

begin
   if a<0
   then 
      dbms_output.put_line(' negative ');
    elsif a>0 
    then 
      dbms_output.put_line(' positive ');
    else 
      dbms_output.put_line(' zero ');
    end if;
end;
/