{$O-}
{$APPTYPE CONSOLE}
uses dorand, dogen, sysutils;
begin
  regint (502);
  writeln (1);
  genrandom (50, 0, 1000, 0, 1000, 502);
end.