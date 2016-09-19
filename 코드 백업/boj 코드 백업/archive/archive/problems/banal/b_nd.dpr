{$Q+,R+,O-}
program macro;
const MaxN=18;  MultiTest=true;  Base=10000;
type num=comp;  vect=array[1..4] of integer;  lnum=array[0..4] of integer;
const p : vect = (2, 3, 5, 7);  sz : vect = (3, 2, 1, 1);
var
  A  : array [0..MaxN, -3..MaxN*3, -2..MaxN*2] of num;
  C  : array [0..MaxN, -1..MaxN] of num;
  P9, P10 : array [0..MaxN] of num;
  R  : array [0..9] of int64;

procedure incv (var v : vect; x : integer);
var i : integer;  
begin
  if x = 0 then v[1] := -1000 else 
  for i := 1 to 4 do
    while (x mod p[i]) = 0 do begin x := x div p[i];  inc(v[i]) end
end;

function zeros (c : integer; const v : vect) : num;
begin 
  if v[1] < 0 then zeros := P10[c] else zeros := P10[c] - P9[c]
end;

procedure decomp (u : extended; var A : lnum);
var i : integer;  t : extended;
begin
  for i := 0 to 4 do begin
    t := int (u * (1/Base) + 0.5);
    A[i] := round (u - t * Base);
    u := t
  end;
end;

procedure incr (u, v : num);
var i, j : integer;  A, B : lnum;
begin
  if (u = 0) or (v = 0) then exit;
  decomp (u, A);  decomp (v, B);
  for i := 0 to 4 do
    for j := 0 to 4 do inc (R[i+j], A[i]*B[j])
end;

procedure printr;
var i : integer;  t, c : int64;  S : string;
begin
  c := 0;
  for i := 0 to 9 do 
    begin t := c + R[i];  c := t div Base;  R[i] := t - Base * c;
          if R[i] < 0 then begin inc (R[i], Base);  dec (c) end end;
  if c <> 0 then runerror (239);
  i := 9;  while (i > 0) and (R[i] = 0) do dec (i);
  write (R[i]);
  while i > 0 do begin
    dec (i);  str (R[i], S);
    while length(S) < 4 do S := '0' + S;
    write (S)
  end;
  writeln
end;

var i, j, k, N, c1, c2, m, q1, q2, t, u, x1, x2, x3, x4 : integer;
    S : string;  v1, v2, w : vect;
begin
  assign (input, 'banal.in');  reset (input);
  assign (output, 'banal.out');  rewrite (output);
  P9[0] := 1;  P10[0] := 1;  A[0,0,0] := 1;  C[0,0] := 1;
  for i := 1 to MaxN do begin P9[i] := 9*P9[i-1];  P10[i] := 10*P10[i-1] end;
  for i := 1 to MaxN do
    for j := 0 to i do C[i,j] := C[i-1,j-1] + C[i-1,j];
  for i := 0 to MaxN-1 do
    for j := 0 to MaxN*3 do
      for k := 0 to MaxN*2 do
	A[i+1,j,k] := A[i,j,k]+A[i,j-1,k]+A[i,j,k-1]+A[i,j-2,k]+
	  A[i,j-1,k-1]+A[i,j-3,k]+A[i,j,k-2];
  repeat
    read (N);  if (N <= 0) or (N > MaxN) or not seekeoln then runerror (239);
    readln;  readln (S);  if length(S) <> N*2 then runerror (239);
    for i := 1 to N*2 do
      if not (S[i] in ['0'..'9', '?']) then runerror (239);
    c1 := 0;  c2 := 0;  for i := 1 to 4 do begin v1[i]:=0; v2[i]:=0 end;
    for i := 1 to N do begin
      if S[i] = '?' then inc(c1) else incv (v1, ord(S[i])-48);
      if S[N+i] = '?' then inc(c2) else incv (v2, ord(S[N+i])-48)
    end;
    fillchar (R, sizeof(R), 0);
    incr (zeros (c1, v1), zeros (c2, v2));
    if v1[1] + v2[1] >= 0 then begin
      for i := 1 to 4 do begin
        if v1[i] < v2[i] then m := v1[i] else m := v2[i];
        dec (v1[i], m);  dec (v2[i], m);
        w[i] := c1 * sz[i] - v2[i];  m := c2 * sz[i] - v1[i];
        if w[i] > m then w[i] := m
      end;
      q1 := c1 - v2[3] - v2[4];  q2 := c2 - v1[3] - v1[4];
      for x1 := 0 to w[1] do
	for x2 := 0 to w[2] do
	  for x3 := 0 to w[3] do
	    for x4 := 0 to w[4] do if (x3 + x4 <= q1) and (x3 + x4 <= q2) then
	      begin t := x3+x4+v2[3]+v2[4];  u := x3+x4+v1[3]+v1[4];
		incr (C[t, x3+v2[3]]*C[c1, t]*A[c1-t, x1+v2[1], x2+v2[2]], 
		      C[u, x3+v1[3]]*C[c2, u]*A[c2-u, x1+v1[1], x2+v1[2]]) end
    end;
    printr;  for i := 0 to 9 do R[i] := -R[i];
    incr (P10[c1], P10[c2]);
    printr
  until not MultiTest or seekeof
end.
