{$APPTYPE CONSOLE}
uses dogen, dorand, sysutils;
var x:pnode;
    i:integer;
    tmp:string;
begin
  regint (32);
  for i:=1 to 100 do begin
    repeat
      x:=randomtree2full (8, 1, 1, 1, 512, 2, 20, 0, 50, 0, 500, 100, 15, 10, 40, 500, 10);
      tmp:=displaytree2 (x, false, false);
    until length (tmp)=253;
    writeln ('!', tmp);
  end;
end.