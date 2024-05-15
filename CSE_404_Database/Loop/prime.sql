-- declare 
-- n number:=&n;
-- c number:=0;
-- begin 
-- for i in 1..n
-- loop
-- if mod(n,i)=0 
-- then c:=c+1;
-- end if;
-- end loop;

-- if c=2 
-- then dbms_output.put_line('prime');
-- else dbms_output.put_line('not prime');
-- end if;
-- end;
-- /

-- declare 
--   n number:=&n;
--   c number:=0;
--   i number:=2;
-- begin
--   loop
--       if mod(n,i)=0
--       then c:=c+1;
--       end if;
--       i:=i+1;
--       exit when i=n;
--   end loop;
--   if c=0 
--   then dbms_output.put_line('prime');
--   else dbms_output.put_line('not prime');
--   end if;
-- end;
-- /

declare
  n number:=&n;
  c number:=0;
  i number:=n-1;

begin
  while i>1
  loop
     if mod(n,i)=0
     then
      c:=1;
      exit;
     end if;
     i:=i-1;
  end loop;
  if c=0 
  then
  dbms_output.put_line('prime');
  else dbms_output.put_line('not prime');
  end if;
end;
/
  