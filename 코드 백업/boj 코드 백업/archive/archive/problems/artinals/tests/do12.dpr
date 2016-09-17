{$APPTYPE CONSOLE}
uses dogen, dorand, sysutils;
var x:pnode;
    i:integer;
    tmp:string;
begin
  regint (12);
  for i:=1 to 100 do begin
    repeat
      x:=randomtree2full (7, 1, 1, 1, 512, 5, 5, 0, 3, 0, 4, 20, 4, 4, 10, 10, 10);
      tmp:=displaytree2 (x, false, false);
    until length (tmp)<=253;
    writeln ('!', tmp);
  end;
end.