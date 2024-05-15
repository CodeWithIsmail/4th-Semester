-- declare 
--     cursor c_zip is
--         select * from employees;
--     vr_zip c_zip%rowtype;
-- begin
--     open c_zip;
--     fetch c_zip into vr_zip;
--     while c_zip%found loop
--         dbms_output.put_line(vr_zip.employee_id);
--         fetch c_zip into vr_zip;
--     end loop;
-- end;
-- /


create table Employee 
{
    employee_id VARCHAR2 not null;
    
}