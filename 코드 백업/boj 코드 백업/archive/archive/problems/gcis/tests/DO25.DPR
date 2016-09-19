uses dorand;
function std:extended;
begin
  std:=fvd*fvd;
end;
var i:integer;
const minlongint=-maxlongint-1;
begin
  regint (84);
  writeln (500);
  for i:=1 to 500 do writeln (minlongint+longrandd (0, 1024, std));
  writeln (500);
  for i:=1 to 500 do writeln (minlongint+longrandd (0, 1024, std));
end.