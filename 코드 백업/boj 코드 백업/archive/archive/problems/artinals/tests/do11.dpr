{$APPTYPE CONSOLE}
uses dogen, dorand, sysutils;
var x:pnode;
    i:integer;
    tmp, tmp2:string;
begin
  regint (11);
  for i:=1 to 100 do begin
    repeat
      x:=randomtreefull (3, 1, 1, 1, 512, 3, 17, 1, 3, 0, 1, 5, 1, 1);
      tmp:=displaytree (x);
      x:=randomtreefull (7, 1, 1, 1, 512, 3, 17, 1, 3, 0, 1, 5, 1, 1);
      tmp2:=displaytree (x);
    until length (tmp)+length (tmp2)<=251;
    write ('?', tmp);
    case random (10) of
      0:write ('<');
      1:write ('>');
      2:write ('=');
      3:write ('<=');
      4:write ('>=');
      5:write ('<>');
      6:write ('->');
      7:write ('<-');
      8:write ('<<');
      9:write ('>>');
    end;
    writeln (tmp2);
  end;
end.