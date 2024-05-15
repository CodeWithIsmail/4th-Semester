set serveroutput on;

declare 
  a number:=&a;
  b number:=&b;
  total number;
begin
  if a>b
  then total:=a-b;
  else 
    total:=a+b;
    if(total<0)
    then 
      total:=total*-1;
    end if;
  end if;
  dbms_output.put_line(total);
end;
/
