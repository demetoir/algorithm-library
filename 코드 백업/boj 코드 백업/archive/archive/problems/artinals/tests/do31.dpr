{$APPTYPE CONSOLE}
uses dogen, dorand, sysutils;
var x:pnode;
    i:integer;
    tmp:string;
begin
  regint (31);
  for i:=1 to 100 do begin
    repeat
      x:=randomtree2full (8, 1, 1, 1, 512, 2, 20, 0, 50, 0, 500, 100, 1, 1, 1, 500, 10);
      tmp:=displaytree2 (x, false, false);
    until length (tmp)in [240..253];
    writeln ('!', tmp);
  end;
end.