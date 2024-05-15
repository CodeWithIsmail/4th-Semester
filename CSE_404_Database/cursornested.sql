declare 
v_zip zipcode%type;

cursor c_zip is
select zip,city,state
from zipcode where state='CT';

cursor c_student is 
select first_name,last_name 
from student where zip=v_zip;

begin
for r_zip in c_zip
loop
 v_zip:=r_zip.zip;
 dbms_output.put_line(chr(10));
 dbms_output.put_line('students living in ' || r_zip.city);

 for r_student in c_student
 loop
 dbms_output.put_line(r_student.first_name || ' ' || r_student.last_name);
 end loop;
end loop;
end;
/