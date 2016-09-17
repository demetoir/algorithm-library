{$Q-,R-,O+}
program macro;
const MaxK=30;  MaxS=10000;  MaxM=20;
      Base=1000000000;  Half=Base shr 1;  MaxL=15;
type vect = array [1..{MaxK}32] of integer;
     lnum = array [0..MaxL] of integer;
var
  K, S, M  : integer;
  E        : array [0..MaxM] of vect;
  A        : array [0..MaxS] of lnum;
  V        : vect;
  VS, F	   : integer;

procedure rec (p : integer);
var W : vect; i, WS : integer;
begin
  if VS > S then exit;
  if p > M then begin inc (A[VS,0], f);  exit end;
  rec (p+1);
  W := V;  WS := VS;
  for i := 1 to K do
    if E[p,i] > V[i] then begin inc (VS, E[p,i] - V[i]);  V[i] := E[p,i] end;
  F := -F;
  rec (p+1);
  F := -F;  V := W;  VS := WS
end;

procedure ladd (var A, B : lnum);
var i, t, c : integer;
begin
  c := 0;
  for i := 0 to MaxL do begin
    t := A[i] + B[i] + c;  c := 0;
    if t < -Half then begin inc (t,Base);  dec(c) end else
    if t >= Half then begin dec (t,Base);  inc(c) end;
    A[i] := t
  end;
  if c <> 0 then runerror (239);
end;

procedure print (var A : lnum);
var i, j, t, c : integer;  x : extended;
begin
  c := 0;
  for i := 0 to MaxL do begin
    t := A[i] + c;
    if t < 0 then begin inc (t, Base);  c := -1 end else c := 0;
    A[i] := t
  end;
  if c <> 0 then runerror (239);
  i := MaxL;  while (i > 0) and (A[i] = 0) do dec (i);
  write (A[i]);
  while i > 0 do begin
    dec (i);  x := (A[i] + 0.3) * 1e-9;
    for j := 1 to 9 do begin
      x := x * 10;  c := trunc (x);  x := x - c;
      write (c)
    end
  end;
  writeln
end;

var i, j, S0, t, z  : integer;
begin
  assign (input, 'exp.in');  reset (input);
  assign (output, 'exp.out');  rewrite (output);
  read (K, S, M);
  if (K <= 1) or (S <= 1) or (M < 0) or (K > MaxK) or
     (S > MaxS) or (M > MaxM) then runerror (239);
  for i := 1 to M do begin
    S0 := 0;  t := 0;
    for j := 1 to K do begin
      read (z);
      if (z < 0) or (z > MaxS) then runerror (239);
      inc (S0, z);  if z > 0 then inc (t);
      E[i,j] := z
    end;
    if (S0 > S) or (t < 2) then runerror (239)
  end;
  F := 1;
  A[S,0] := -1 - K*S;
  rec (1);
  for i := 0 to K do
    for j := 1 to S do
      ladd (A[j], A[j-1]);
  print (A[S]);
end.

