uses dorand;
type integer=longint;
var i, x:integer;
const minlongint=-maxlongint-1;
begin
  regint (68);
  writeln (500);
  x:=0;
  for i:=1 to 500 do begin
    x:=x+poisson (sqrt (2), 0, 10);
    writeln (x);
  end;
  x:=0;
  writeln (500);
  for i:=1 to 500 do begin
    x:=x+poisson (sqrt (3), 0, 10);
    writeln (x);
  end;
end.