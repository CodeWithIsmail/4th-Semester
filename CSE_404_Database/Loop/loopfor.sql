begin
for i in 1..10
loop
dbms_output.put_line(i);
end loop;
end;
/

begin
for i in reverse 1..10
loop 
dbms_output.put_line(i);
end loop;
end;
/

begin
for i in 1..5
loop 
  for j in reverse 1..10
  loop
  dbms_output.put_line(' i : ' || i || ' j: '|| j);
  end loop;
end loop;
end;
/

