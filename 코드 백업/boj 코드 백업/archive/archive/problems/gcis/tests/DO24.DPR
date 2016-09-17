uses dorand;
function std:extended;
begin
  std:=fvd*fvd*fvd;
end;
var i:integer;
const minlongint=-maxlongint-1;
begin
  regint (83);
  writeln (500);
  for i:=1 to 500 do writeln (maxlongint-longrandd (0, 12768, std));
  writeln (500);
  for i:=1 to 500 do writeln (maxlongint-longrandd (0, 12768, std));
end.