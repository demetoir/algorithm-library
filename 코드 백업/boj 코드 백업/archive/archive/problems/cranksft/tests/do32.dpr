{$O-}
{$APPTYPE CONSOLE}
uses dorand, dogen, sysutils;
var i:integer;
begin
  regint (23951);
  writeln (100);
  for i:=1 to 100 do genrandom (30, -10000, 10000, -10000, 10000, 51);
end.