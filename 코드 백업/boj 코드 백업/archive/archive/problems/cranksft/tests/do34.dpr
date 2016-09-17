uses dorand;
type integer=longint;
const N=100;
      V=200;
      MaxC=10000;  Half = MaxC shr 1;
var i, j, k, R, x0, y0, a, cnt :integer;  b : extended;
    x, y:array [0..V+1] of integer;
begin
  regint (34);
  writeln (N);
  for k:=1 to N do begin
    x0 := randr (MaxC-MaxC shr 3, MaxC-MaxC shr 4);
    y0 := randr (MaxC-MaxC shr 3, MaxC-MaxC shr 4);
    R  := randr (MaxC shr 5, MaxC shr 4);
    a := 0;
    for j:=1 to V do begin
      a := a + poisson (3500 div V, 0, maxlongint);
      b := a * Pi / 1800;
      x[j] := round (x0 + R * cos(b));
      y[j] := round (y0 - R * sin(b));
    end;
    x[0]:=x[V]; y[0]:=y[V]; x[V+1]:=x[1]; y[V+1]:=y[1];
    cnt:=0;
    for i:=1 to V do
      if (x[i]-x[i-1])*(y[i+1]-y[i])-(x[i+1]-x[i])*(y[i]-y[i-1])<>0 then
        inc (cnt);
    write (cnt);
    for i:=1 to V do
      if (x[i]-x[i-1])*(y[i+1]-y[i])-(x[i+1]-x[i])*(y[i]-y[i-1])<>0 then
        write (' ', x[i], ' ', y[i]);
    writeln;
    assert (a < 3600);
  end;
end.
