{$APPTYPE CONSOLE}
uses dogen, dorand, sysutils;
var x:pnode;
    i:integer;
begin
  regint (77);
  for i:=1 to 100 do begin
    x:=randomtree (6, 1, 1, 1, 10, 3, 1, 1, 1, 0, 5, 5, 5, 5);
    writeln ('!', displaytree (x));
  end;
end.