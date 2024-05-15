set serveroutput on;
declare 
  a varchar2(1):='&a';
begin
  if(a>='a' and a<='z')
  then 
    dbms_output.put_line(' small english letter ');
  elsif(a>='A' and a<='Z')
  then 
    dbms_output.put_line(' capital english letter ');
   elsif(a>='0' and a<='9')
   then 
     dbms_output.put_line(' digit ');
    else 
    dbms_output.put_line(' special char ');
    end if;
end;
/
