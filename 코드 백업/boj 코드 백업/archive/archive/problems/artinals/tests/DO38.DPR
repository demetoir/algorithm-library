var i, j:integer;
begin
  write ('A:=');
  for j:=1 to 124 do write ('{');
  write (512);
  for j:=1 to 124 do write ('}');
  writeln;
  for i:=2 to 98 do begin
    write ('A:=');
    for j:=1 to 125 do write ('{');
    write ('A');
    for j:=1 to 125 do write ('}');
    writeln;
  end;
  write ('B:=');
  for j:=1 to 125 do write ('{');
  write ('A');
  for j:=1 to 125 do write ('}');
  writeln;
  writeln ('?B->A');
end.