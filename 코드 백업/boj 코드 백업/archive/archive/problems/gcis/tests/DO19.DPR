uses dorand;
type integer=longint;
const NS=56;
var i:integer;
    N1, N2:integer;
    nums:array [1..NS] of integer;
const minlongint=-maxlongint-1;
begin
  regint (78);
  N1:=500-lr (1, 20);
  N2:=N1-lr (1, 20);
  writeln (N1);
  for i:=1 to NS do begin
    nums[i]:=longrandfixd (0, 1000, cbd);
  end;
  for i:=1 to N1 do writeln (-nums [lr (1, NS)]);
  writeln (N2+1);
  for i:=1 to N2 do writeln (-nums [lr (1, NS)]);
  writeln (0);
end.