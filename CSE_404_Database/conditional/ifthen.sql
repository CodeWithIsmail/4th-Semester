-- min find from 3 number
set serveroutput on;

declare
  a number:=&a;
  b number:=&b;
  c number:=&c;
  temp number:=a;

begin
  if a>b 
  then temp:=b;
  end if;

  if temp>c
  then temp:=c;
  end if;

  dbms_output.put_line(' min number is ' || temp);
end;
/

