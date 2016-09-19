uses sysutils;
var i:integer;
    s, t:string;
    lcnt:integer;
begin
  write ('A:={1,');
  for i:=100 to 160 do write (i, ',');
  write (161);
  writeln ('}');
  write ('A:=A+{');
  for i:=162 to 222 do write (i, ',');
  write (223);
  writeln ('}');
  write ('A:=A+{');
  for i:=224 to 284 do write (i, ',');
  write (285);
  writeln ('}');
  write ('A:=A+{');
  for i:=286 to 346 do write (i, ',');
  write (347);
  writeln ('}');
  write ('A:=A+{');
  for i:=348 to 408 do write (i, ',');
  write (409);
  writeln ('}');
  s:='B:=B+{'; i:=1;
  repeat
    t:='{A+{{1},'+inttostr (i)+'}}';
    if length (s)+1+length (t)>253 then 
      begin writeln (s,'}'); s:='B:=B+{' end
    else if length (s)<7 then s:=s+t else s:=s+','+t;
    inc (i);
  until i>512;
  writeln (s, '}');
  s:='C:=C+{'; lcnt:=0;
  repeat
    t:='B+{A+{'+inttostr (random (512))+'}}';
    if length (s)+1+length (t)>253 then 
      begin writeln (s,'}'); s:='C:=C+{'; inc (lcnt); end
    else if length (s)<7 then s:=s+t else s:=s+','+t;
    inc (i);
  until lcnt=1;
  writeln (s, '}');
  writeln ('!C');
end.