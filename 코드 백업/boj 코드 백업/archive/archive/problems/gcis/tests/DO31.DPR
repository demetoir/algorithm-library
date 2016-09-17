uses dorand;
var i:integer;
const minlongint=-maxlongint-1;
begin
  regint (90);
  writeln (500);
  for i:=1 to 500 do writeln (minlongint+longrandd (0, 2, sqd));
  writeln (500);
  for i:=1 to 500 do writeln (minlongint+longrandd (0, 2, sqd));
end.