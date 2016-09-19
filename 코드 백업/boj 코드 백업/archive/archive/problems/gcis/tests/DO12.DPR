uses dorand;
var i:integer;
const minlongint=-maxlongint-1;
begin
  regint (71);
  writeln (500);
  for i:=1 to 500 do writeln (maxlongint-longrandd (0, 16384, gaussmod));
  writeln (500);
  for i:=1 to 500 do writeln (maxlongint-longrandd (0, 16384, gaussmod));
end.