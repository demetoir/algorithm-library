uses sysutils;
const MaxN=20;
      MaxV=1000;
var i, n:integer;
    a:array [0..MaxN] of integer;
begin
  assign (input, 'factor.in'); reset (input);
  assign (output, 'factor.out'); rewrite (output);
  assert (not seekeoln); read (n); assert (seekeoln); readln;
  assert ((n>=0) and (n<=MaxN));
  for i:=n downto 0 do begin
    assert (not seekeoln); read (a[i]); assert ((a[i]>=-MaxV) and (a[i]<=MaxV));
  end; assert (seekeof);
  assert (a[n]<>0);
  if n<2 then writeln ('YES') else
  if n>2 then writeln ('NO') else
  if a[1]*a[1]-a[2]*a[0]*4<0 then writeln ('YES')
  else writeln ('NO');
end.