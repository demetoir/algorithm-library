{$Q+,R+,O+}
program macro;
uses sysutils;
const MaxN={100}50;  MaxP=MaxN*(MaxN+10);  MaxX=10000;  MinV=1;  MaxV=100;  MaxT=10;
      eps=1e-6;   infty=1e1000;  hinfty = 0.5e1000;
type float = extended;
  point = record x, y : float end;
  line = record no : integer;  A, B, C, T1, T2 : float;  p0, v : point end;
  PNode = ^Node;
  Node = record
	   no, hi     : integer;
           x, y, t    : float;
           d          : float;
           NX, PR, NR, NP : PNode;
         end;
var
  N   : integer;
  L   : array [1..MaxN] of line;
  QH  : array [-1..MaxN] of PNode;
  H   : array [1..MaxP] of PNode;
  HS  : integer;
  v1, v2     : float;
  Q0, Q1, w  : point;

procedure readp (var P : point);
begin
  read (P.x, P.y);
  if (abs(P.x) > MaxX) or (abs(P.y) > MaxX) then runerror (239)
end;

function dist (P, Q : PNode) : float;
begin Result := sqrt(sqr(P.x-Q.x)+sqr(P.y-Q.y)) end;

function makenode (_no : integer;  _x, _y, _d : float) : PNode;
begin
  new (Result);  
  with Result^ do begin
    no := _no;  hi := 0;  x := _x;  y := _y;  t := 0;  d := _d;
    NX := Result;  NR := NX;  NP := nil;  PR := nil;
    inc (HS);  H[HS] := Result;  hi := HS;
{writeln ('new node at ', _no, '  (',_x:6:6,',',_y:6:6,')');}
    if QH[_no] = nil then QH[_no] := Result else begin
      NX := QH[_no].NX;  QH[_no].NX := Result
    end
  end;
end;

procedure mknd2 (no, nl : integer;  t : float);
var x, y : float;  P, Q : PNode;
begin
  with L[nl] do begin x := p0.x + v.x * t;  y := p0.y + v.y * t end;
  P := makenode (no, x, y, infty);
  Q := makenode (nl, x, y, infty);
  P.NR := Q;  Q.NR := P;  Q.t := t
end;

procedure mknd1 (_no : integer;  const Q : point);
var x, y, t, A1, B1 : float;  i : integer;
begin
  x := QH[_no].x;  y := QH[_no].y;
  for i := 1 to N do with L[i] do begin
    A1 := v.x - v.y * w.y;
    B1 := v.y + v.x * w.y;
    t  := A1 * (x - p0.x) + B1 * (y - p0.y);
    mknd2 (_no, i, t);
    A1 := v.x + v.y * w.y;
    B1 := v.y - v.x * w.y;
    t  := A1 * (x - p0.x) + B1 * (y - p0.y);
    mknd2 (_no, i, t)
  end
end;

function mknd3 (i, j : integer) : PNode;
var t, u : float;
begin
  Result := nil;
  with L[i] do begin
    t := L[j].A * p0.x + L[j].B * p0.y - L[j].C;
    u := L[j].A * v.x + L[j].B * v.y;
    if (abs(t) < eps) and (abs(u) < eps) then runerror (239);
    if abs(u) < eps then exit;
    t := -t/u;
    if abs(t) > 10*MaxX*MaxV/MinV then exit;
    Result := makenode (i, p0.x+t*v.x, p0.y+t*v.y, infty);
    Result.t := t
  end
end;

var
  A  : array [1..2*MaxN+4] of PNode;

procedure qsort (u, v : integer);
var i, j : integer;  h : float;  t : PNode;
begin
  if u >= v then exit;
  h := A[(u + v) shr 1].t;
  i := u;  j := v;
  repeat
    while A[i].t < h do inc(i);
    while A[j].t > h do dec(j);
    if i <= j then begin t:=A[i]; A[i]:=A[j]; A[j]:=t; inc(i); dec(j) end
  until i > j;
  qsort (u, j);
  qsort (i, v)
end;

procedure sortnodes (no : integer);
var P, Q : PNode;  i, M : integer;
begin
  P := QH[no];  Q := P;  M := 0;
  repeat
    inc (M);  A[M] := P;  P := P.NX
  until P = Q;
  qsort (1, M);
  A[M+1] := A[1];
  QH[no] := A[1];
  for i := 1 to M do begin A[i].NX:=A[i+1];  A[i+1].PR:=A[i] end;
end;

procedure relax (P, Q : PNode;  di : float);
var i, j : integer;
begin
{writeln ('  relax ((',P.x:6:6,',',P.y:6:6,';',P.no,'), (',Q.x:6:6,',',Q.y:6:6,';',Q.no,'), ', di:6:6,')');}
  if (P = Q) or (Q.hi = 0) or (Q.d <= P.d + di) then exit;
  Q.d := P.d + di;  i := Q.hi;  Q.NP := P;
{writeln ('    relaxed: (', Q.x:6:6, ',', Q.y:6:6,';',Q.no,'), dist=', Q.d:6:6);}
  while i > 1 do begin
    j := i shr 1;
    if H[j].d <= Q.d then break;
    H[i] := H[j];  H[i].hi := i;  i := j
  end;
  H[i] := Q;  Q.hi := i
end;

var i, j, k : integer;  d, t : float;  P0, P1 : PNode;
begin
  assign (input, 'jogging.in');  reset (input);
  assign (output, 'jogging.out');  rewrite (output);
  read (N);  if (N < 0) or (N > MaxN) then runerror (239);
  readp (Q1);  readp (Q0);  read (v1, v2);
  if abs(Q0.x-Q1.x) + abs(Q0.y-Q1.y) < 2*eps then runerror (239);
  if (v1 < MinV) or (v2 < MinV) or (v1 > MaxV) or (v2 > MaxV) then runerror (239);
  v1 := v1 + v2;  w.x := 1;  w.y := v2/sqrt(sqr(v1)-sqr(v2));  
  v1 := 1/v1;  v2 := 1/v2;
  for i := 1 to N do with L[i] do begin
    no := i;
    readp (p0);  readp (v);  v.x := v.x - p0.x;  v.y := v.y - p0.y;
    if abs(v.x) + abs(v.y) < eps then runerror (239);
    read (T1, T2);
    if (T1 < 0) or (T2 < 0) or (T1 > MaxT) or (T2 > MaxT) then runerror (239);
    T1 := T1 + T2;  T2 := 0;  if T1 = 0 then T1 := 1e-10;
    d := 1/sqrt (sqr(v.x) + sqr(v.y));
    v.x := v.x * d;  v.y := v.y * d;
    A := v.y;  B := -v.x;  C := A * p0.x + B * p0.y;
    d := v.x*p0.x + v.y*p0.y;
    p0.x := p0.x - d*v.x;  p0.y := p0.y - d*v.y;
    if (abs(A*Q0.x+B*Q0.y-C)<eps) or (abs(A*Q1.x+B*Q1.y-C)<eps) then runerror (239);
  end;
  QH[-1]:= makenode (-1, Q0.x, Q0.y, 0); 
  QH[0] := makenode (0,  Q1.x, Q1.y, v2*sqrt(sqr(Q1.x-Q0.x)+sqr(Q1.y-Q0.y)));
  QH[0].NP := QH[-1];
  mknd1 (-1, Q0);
  mknd1 (0, Q1);
  for i := 1 to N do
    for j := i+1 to N do begin
      P0 := mknd3 (i, j);  P1 := mknd3 (j, i);
      if (P0 <> nil) or (P1 <> nil) then
        begin P0.NR := P1;  P1.NR := P0 end;
    end;
  for i := 1 to N do sortnodes (i);
  repeat
    if HS = 0 then runerror (239);
    P0 := H[1];  P1 := H[HS];  P0.hi := 0;  dec (HS);
{    writeln ('Now: (',P0.x:6:6,',',P0.y:6:6,') at ', P0.no,', dist=', P0.d:6:6);}
    i := 1;
    repeat
      j := i shl 1;
      if (j < HS) and (H[j+1].d < H[j].d) then inc (j);
      if (j > HS) or (H[j].d >= P1.d) then break;
      H[i] := H[j];  H[i].hi := i;  i := j
    until false;
    if HS >= 1 then begin H[i] := P1;  P1.hi := i end;
    if P0 = QH[0] then break;
    P1 := P0.NR;
    i := P1.no;  t := 0;  if i > 0 then t := L[i].T1;
    relax (P0, P1, t);
    if P0.no <= 0 then begin
      P1 := P0;
      repeat
        P1 := P1.NX;  if P1 = P0 then break;
        relax (P0, P1, v2*dist (P0, P1))
      until false
    end else begin
      P1 := P0.NX;
      relax (P0, P1, v1*abs(P0.t-P1.t));
      P1 := P0.PR;
      relax (P0, P1, v1*abs(P0.t-P1.t))
    end
  until false;
  writeln (P0.d:6:6);
  k := 1;  A[1] := P0;
  repeat
    P0 := P0.NP;
{    writeln ('(',P0.x:6:6, ',', P0.y:6:6, ') at ', P0.no);}
    if (k >= 2) and (A[k].no = P0.no) and (A[k-1].no = P0.no) then 
      begin A[k] := P0;  continue end;
    if (k >= 2) and (dist(A[k],P0)<eps) and (dist(A[k],A[k-1])<eps) then
      begin A[k] := P0;  continue end;
    inc (k);  A[k] := P0
  until P0 = QH[-1];
  assert (not odd(k));
  writeln (k shr 1);
  for i := 1 to k shr 1 do with A[2*i]^ do begin
    assert ((i = 1) or (dist (A[2*i-2], A[2*i-1]) < eps));
    j := A[2*i-1].no;
    assert ((j = no) or (k = 2));
    if j < 0 then j := 0;
    if abs(x) < 0.5e-6 then x := 0;
    if abs(y) < 0.5e-6 then y := 0;
    writeln (j, ' ', x:6:6, ' ', y:6:6)
  end;
end.
