const N=50; MaxX=10000;  V1=3.0;  V2=5.0;  MinT = 0;  MaxT = 10;

function rr(a, b:extended) : extended; begin rr:=a+(b-a)*random end;
function rx : extended; begin rx:=rr(-MaxX,MaxX) end;

var i : integer;
begin
  randseed := 99;
  writeln (N, ' ', -MaxX, ' ', -MaxX, ' ', MaxX, ' ', MaxX, ' ', V1:6:6, ' ', V2:6:6);
  for i := 1 to N do
    writeln (rx:6:6, ' ', rx:6:6, ' ', rx:6:6, ' ', rx:6:6, ' ', 
    rr(MinT,MaxT):6:6, ' ', rr(MinT,MaxT):6:6);
end.