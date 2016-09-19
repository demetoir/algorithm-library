program macro;
const MaxN=200000; MaxM=200000;  Sh = 19;  Pow=1 shl Sh;
var
  X, Y  : array [1..MaxN] of integer;
  C     : array [1..Pow*2] of integer;
  N, M  : integer;

var i, u, v, W : integer;  F : boolean;
begin
  assign (input, 'key.in');  reset (input);
  assign (output, 'key.out');  rewrite (output);
  read (N, M);  if (N <= 0) or (N > MaxN) then runerror (239);
  if (M <= 0) or (M > MaxM) then runerror (239);
  for i := N downto 1 do begin
    read (X[i]);  Y[i] := i;
    if (X[i] <= 0) or (X[i] > M) or (Y[i] <= 0) then runerror (239);
  end;
  for i := 1 to N do begin
    u := Pow + X[i] - 1;
    if C[u] <> 0 then begin
      v := 1;
      repeat
        F := odd(u);  u := u shr 1;  v := v shl 1
      until not F and (C[u] < v);
      u := succ (u shl 1);  v := v shr 1;
      while u < Pow do begin
        u := u shl 1;  v := v shr 1;
        if C[u] >= v then inc (u)
      end
    end;
    C[u] := Y[i];
    repeat u := u shr 1;  inc(C[u]) until u = 1;
  end;
  W := 1;
  repeat
    W := W shl 1;  if C[W+1] > 0 then inc (W)
  until W >= Pow;
  writeln (W - Pow + 1);
  for i := Pow to W - 1 do write (C[i], ' ');
  writeln (C[W])
end.
