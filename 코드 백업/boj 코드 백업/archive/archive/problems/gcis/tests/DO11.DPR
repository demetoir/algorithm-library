uses dorand;
var i:integer;
const minlongint=-maxlongint-1;
begin
  regint (70);
  writeln (500);
  for i:=1 to 500 do writeln (maxlongint-longrandd (0, 1024, gaussmod));
  writeln (500);
  for i:=1 to 500 do writeln (maxlongint-longrandd (0, 2048, gaussmod));
end.