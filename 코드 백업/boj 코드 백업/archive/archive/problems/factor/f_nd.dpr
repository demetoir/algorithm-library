{$Q+,R+,O-}
program macro;
const MaxN=20;  MaxX=1000;
var i, N : integer;  X : array [0..MaxN] of integer;
begin
  assign (input, 'factor.in');  reset (input);
  assign (output, 'factor.out');  rewrite (output);
  read (N);  assert ((N >= 0) and (N <= MaxN));
  for i := 0 to N do begin
    read (X[i]);  assert (abs(X[i]) <= MaxX)
  end;
  assert (X[0] <> 0);
  if (N <= 1) or ((N = 2) and (4*X[0]*X[2] > X[1]*X[1])) then
    writeln ('YES') else writeln ('NO');
end.
