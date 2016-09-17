program macro;
const MaxN=200000; MaxM=200000;
var
  X, R  : array [0..MaxN] of integer;
  N, M  : integer;

procedure qsort (a, b : integer);
var i, j, h, hx, t : integer;
begin
  if a >= b then exit;
  h := R[(a+b) shr 1];  hx := X[h];
  i := a;  j := b;
  repeat
    while (X[R[i]] < hx) or ((X[R[i]] = hx) and (R[i] > h)) do inc (i);
    while (X[R[j]] > hx) or ((X[R[j]] = hx) and (R[j] < h)) do dec (j);
    if i <= j then begin t:=R[i]; R[i]:=R[j]; R[j]:=t; inc(i); dec(j) end
  until i > j;
  qsort (a, j);
  qsort (i, b)
end;

var i, j, p, W : integer;
begin
  assign (input, 'key.in');  reset (input);
  assign (output, 'key.out');  rewrite (output);
  read (N, M);  if (N <= 0) or (N > MaxN) then runerror (239);
  if (M <= 0) or (M > MaxM) then runerror (239);
  for i := 1 to N do begin
    read (X[i]);  R[i] := i;
    if (X[i] <= 0) or (X[i] > M) then runerror (239);
  end;
  qsort (1, N);
  W := 0;
  for i := 1 to N do begin
    p := R[i];
    if X[p] <= W then begin inc(W); X[p]:=W end else W := X[p]
  end;
  writeln (W);
  for i := 1 to N do begin
    p := R[i];
    for j := X[R[i-1]] + 1 to X[p] - 1 do write ('0 ');
    write (p);
    if i < N then write (' ') else writeln
  end
end.