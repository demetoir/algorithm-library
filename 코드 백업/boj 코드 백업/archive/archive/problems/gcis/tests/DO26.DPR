uses dorand;
function std:extended;
begin
  std:=fvd*sqd;
end;
var i:integer;
const minlongint=-maxlongint-1;
begin
  regint (85);
  writeln (500);
  for i:=1 to 500 do writeln (minlongint+longrandd (0, 188, std));
  writeln (500);
  for i:=1 to 500 do writeln (minlongint+longrandd (0, 188, std));
end.