uses sysutils;
var i:integer;
    s, t:string;
begin
  write ('A:={');
  for i:=100 to 160 do write (random (401), ',');
  write (161);
  writeln ('}');
  write ('A:=A+{');
  for i:=162 to 222 do write (random (401), ',');
  write (223);
  writeln ('}');
  write ('A:=A+{');
  for i:=224 to 284 do write (random (401), ',');
  write (285);
  writeln ('}');
  write ('A:=A+{');
  for i:=286 to 346 do write (random (401), ',');
  write (347);
  writeln ('}');
  write ('A:=A+{');
  for i:=348 to 408 do write (random (401), ',');
  write (random (401));
  writeln ('}');
  s:='B:=B+{'; i:=1;
  repeat
    t:='{A+{'+inttostr (random (112)+401)+'}}';
    if length (s)+1+length (t)>253 then 
      begin writeln (s,'}'); s:='B:=B+{' end
    else if length (s)<7 then s:=s+t else s:=s+','+t;
    inc (i);
  until i>2048;
  writeln (s, '}');
  writeln ('!B');
end.