{$Q+,R+,O-}
program macro;
const MaxN=200000;  MaxM=200000;  MaxW=MaxN+MaxM;
type 
  PNode = ^Node;
  Node = record L, R : PNode;  x, y, n : integer end;
var
  N, M      : integer;
  Root, TMP : PNode;
  G         : array [1..MaxW] of integer;

function sz (P : PNode) : integer;
begin if P = nil then sz := 0 else sz := P.n end;

procedure split (P : PNode; i : integer; var L, R : PNode);
var T : PNode;
begin
  if P = nil then begin
    if i <> 0 then runerror (239);
    L  := nil;  R := nil; exit end;
  if i <= sz(P.L) then begin
    split (P.L, i, L, T);
    P.n := sz(T) + 1 + sz(P.R);
    P.L := T;  R := P
  end else begin
    split (P.R, i - sz(P.L) - 1, T, R);
    P.n := sz(P.L) + 1 + sz(T);
    P.R := T;  L := P
  end
end;

function insert (R, P : PNode; i : integer) : PNode;
var q : integer;
begin
  if R = nil then begin 
    if i <> 1 then runerror (239);
    P.L := nil;  P.R := nil;  insert := P;  P.n := 1;
  end else if P.y > R.y then begin 
    q := R.n;  split (R, i - 1, P.L, P.R);  P.n := q + 1;
    insert := P
  end else if i <= sz(R.L) + 1 then begin
    R.L := insert (R.L, P, i);  inc (R.n);  insert := R
  end else begin
    if R.L <> nil then dec (i, R.L.n);
    R.R  := insert (R.R, P, i - 1);  inc (R.n);  insert := R
  end;
end;

function merge (A, B : PNode) : PNode;
begin
  if A = nil then merge := B else
  if B = nil then merge := A else
  if A.y > B.y then begin
    A.R := merge (A.R, B);  A.n := sz(A.L)+1+sz(A.R);  merge := A
  end else begin
    B.L := merge (A, B.L);  B.n := sz(B.L)+1+sz(B.R);  merge := B
  end
end;

function delete (R : PNode; i : integer) : PNode;
var j : integer;
begin
  delete := R;
  if R = nil then runerror (239);
  j := sz (R.L);  dec (R.n);
  if i <= j then R.L := delete (R.L, i) else
  if i > j + 1 then R.R := delete (R.R, i - j - 1) else
    begin TMP := R;  delete := merge (R.L, R.R) end
end;

procedure print (P : PNode; q : integer);
begin
  if (q <= 0) or (q > P.n) or (P.n <> sz(P.L) + 1 + sz(P.R)) then runerror (239);
  if q <= sz(P.L) then print (P.L, q) else begin
    if P.L <> nil then begin print (P.L, P.L.n);  write (' ');  
      dec (q, P.L.n) end;
    write (P.x);  dec (q);
    if q > 0 then begin write (' ');  print (P.R, q) end
  end
end;

var i, j, x, y, z, W : integer;  P : PNode;
begin
  assign (input, 'key.in');  reset (input);
  assign (output, 'key.out');  rewrite (output);
  read (N, M);  if (N <= 0) or (N > MaxN) then runerror (239);
  if (M <= 0) or (M > MaxM) then runerror (239);
  for i := 1 to MaxW do begin j := random(i) + 1;  G[i] := G[j];  G[j] := i end;
  Root := nil;
  for i := 1 to MaxW do begin
    new(P);  P.x := 0;  P.y := G[i];
    G[i] := i;
    Root := insert (Root, P, i)
  end;
  W := 0;
  for i := 1 to N do begin
    read (x);  y := i;
    if (x <= 0) or (x > M) or (y <= 0) then runerror (239);
    z := x;
    repeat z := G[z] until G[z] = z;
{writeln ('deleting at ', z);
write ('Was: ');  print (Root, 8);  writeln;}
    Root := delete (Root, z);
{write ('Now: ');  print (Root, 8);  writeln;}
    if TMP.x <> 0 then runerror (239);
    TMP.x := y;
    G[z] := z + 1;  inc (z);
    repeat z := G[z] until G[z] = z;
{writeln ('inserting ', y, ' at ', x);}
{write ('Was: ');  print (Root, 8);  writeln;}
    Root := insert (Root, TMP, x);
{write ('Now: ');  print (Root, 8);  writeln;}
    repeat y := G[x];  G[x] := z;  x := y until x = z;
    if x > W then W := x;
  end;
  dec (W);
  writeln (W);
  print (Root, W);
  writeln
end.