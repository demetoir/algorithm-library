{$APPTYPE CONSOLE}
uses dogen, dorand, sysutils;
var x:pnode;
    i:integer;
    tmp:string;
begin
  regint (8);
  for i:=1 to 100 do begin
    repeat
      x:=randomtreefull (8, 1, 1, 1, 10, 3, 1, 2, 3, 0, 4, 5, 6, 7);
      tmp:=displaytree (x);
    until length (tmp)<=253;
    writeln ('!', tmp);
  end;
end.