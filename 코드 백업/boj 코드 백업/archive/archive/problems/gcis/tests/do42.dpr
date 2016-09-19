uses dorand;
var i:integer;
const minlongint=-maxlongint-1;
var
    a: array [1..500] of longint;
    s: longint;
begin
  regint (42);
  writeln (500);
  s := 0;
  for i:=1 to 500 do 
  begin
    s := s + lr (1, 10);
    if random(239) = 0 then
        s := s - lr(1, 20);
    a[i] := s;
    writeln(s);
  end;
  writeln (500);
  for i:=1 to 500 do 
  begin
    if random(239) = 0 then
        writeln(a[i] - 1)
    else
        writeln(a[i]);
  end;
end.