uses dorand;
var i:integer;
const minlongint=-maxlongint-1;
begin
  regint (99);
  writeln (500);
  for i:=1 to 500 do writeln (randr (minlongint, maxlongint));
  writeln (500);
  for i:=1 to 500 do writeln (randr (minlongint, maxlongint));
end.