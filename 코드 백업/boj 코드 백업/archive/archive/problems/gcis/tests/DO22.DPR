uses dorand;
type integer=longint;
const NS=239;
      N1=500;
      N2=17;
var i:integer;
    nums:array [1..NS] of integer;
const minlongint=-maxlongint-1;
begin
  regint (81);
  writeln (N1);
  for i:=1 to NS do begin
    nums[i]:=randr (minlongint, maxlongint);
  end;
  for i:=1 to N1 do writeln (nums [lr (1, NS)]);
  writeln (N2);
  for i:=1 to N2 do writeln (nums [lr (1, NS)]);
end.