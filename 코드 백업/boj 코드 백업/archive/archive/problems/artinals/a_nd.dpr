{$H+,Q-,R-,O+,I+}
program macro;
const
  MaxN = 512;  MaxN1=2048;  MaxL = 254;  MaxV = 1000;  MaxObj=100000;
  MaxCnt = 400;  MaxCnt1 = 100;  MaxDepth=63;
  _Leq=#128; _Geq=#129; _Neq=#130; _In=#131; _Ni=#132;
  _Subset=#133;  _Supset=#134;  _Let=#135;  _Id='Z';  _End=#0;  _Err=#7;
  TokStr1 = '?!#{,}()+-*^<=>';
  TokStr2 = '<=>=<>-><-<<>>:=';

type
  Lex = char;
  PNode = ^Node;
  Node = record
	   v, s, y            : integer;
	   L, R, U, A, B, HN  : PNode
	 end;
  nodearr = array of PNode;
  func = procedure;
const
  HPrime = 65537;
var
  HS     : array [0..HPrime-1] of string;
  HV, OH : array [0..HPrime-1] of PNode;
  FO     : array [0..MaxN1] of PNode;
  Empty, Root  : PNode;

  S      : string;
  P, LNo : integer;
  CL     : Lex;
  CLS    : string;
  CH, TotV, TotO, N1  : integer;

procedure fatal (const T : string);
var i : integer;
begin
  writeln ('Line ', LNo, ':');
  for i := 1 to length(S)-1 do
    if S[i] in [#9,' '..#126] then write (S[i]) else write ('.');
  writeln;
  for i := 1 to P-1 do
    if S[i]=#9 then write(S[i]) else write (' ');
  writeln ('^');
  writeln (T);
  flush (output);
  runerror (239)
end;

procedure expect (const T : string);
begin fatal ('`'+T+''' expected') end;

function inttostr (x : integer) : string;
begin str(x,Result) end;

function hashstr (S : string) : integer;
var h0, h1, i : integer;
begin
  h0 := 0;  h1 := 0;
  for i := 1 to length(S) do begin
    h0 := (h0 * 3 + ord(S[i])) mod HPrime;
    h1 := (h1 * 5 + ord(S[i])) mod (HPrime-1)
  end;
  inc (h1);
  while (HS[h0] <> '') and (HS[h0] <> S) do begin
    inc (h0, h1);  if h0 >= HPrime then dec (h0, HPrime)
  end;
  if HS[h0] = '' then begin HS[h0]:=S;  HV[h0]:=Empty;  inc (TotV);
    if TotV > MaxV then fatal ('Too many variables') end;
  Result := h0
end;

function getlexem : char;
var i : integer;
begin
  while S[P] in [#9,' '] do inc (P);
  CL := S[P];  CLS := CL;  CH := -1;  Result := CL;
  if CL = #0 then exit;
  CLS := CL + S[P+1];
  i := pos (CLS, TokStr2);
  if odd(i) then begin inc(P,2);  CL:=chr(128+(i shr 1));
    Result:=CL;  exit end;
  if pos (CL, TokStr1) > 0 then begin CLS:=CL;  inc(P); exit end;
  CLS := '';
  while S[P] in ['A'..'Z','a'..'z','0'..'9','_'] do begin
    CLS := CLS+S[P];  inc (P)
  end;
  if CLS = '' then fatal ('Unknown char code: '+inttostr(ord(CL)));
  CH := hashstr (CLS);  CL := _Id;  Result := CL;
end;

function allocnode (A, B : PNode; s : integer) : PNode;
begin
  inc (TotO);  if TotO > MaxObj then fatal ('Too many objects');
  new (Result);  fillchar (Result^, sizeof(Node), 0);
  Result.A := A;  Result.B := B;  Result.s := s;  Result.v := -1;
end;

function newnode1 (A, B : PNode; s : integer) : PNode;
var H : PNode;  hs : integer;
begin
  asm
    mov eax, A
    mov ecx, B
    mov edx, s
    imul ecx, 17
    imul edx, 239
    add eax, ecx
    add eax, edx
    mov edx, eax
    and eax, $ffff
    shr edx, 16
    sub eax, edx
    jae @1
    add eax, $10001
  @1:
    mov hs, eax
  end;
  H := OH[hs];
  if H = nil then begin Result:=allocnode(A, B, s);  OH[hs]:=Result;  exit end;
  repeat
    Result := H;
    if (H.A = A) and (H.B = B) then exit;
    if H.HN = nil then begin Result := allocnode(A, B, s);  
      H.HN := Result;  exit end;
    H := H.HN
  until false
end;

function cmpobj (X, Y : PNode) : integer;
var A, B : array [0..MaxDepth] of integer; i, j : integer;
begin
  if X = Y then begin Result := 0; exit end;
  i := 1;  A[0] := 0;  j := 1;  B[0] := 0;
  while (X.U <> nil) do begin
    if X = X.U.L then A[i] := -1 else
    if X = X.U.R then A[i] := 1 else runerror (239);
    X := X.U;  inc (i);  if i > MaxDepth then runerror (239);
  end;
  while (Y.U <> nil) do begin
    if Y = Y.U.L then B[j] := -1 else
    if Y = Y.U.R then B[j] := 1 else runerror (239);
    Y := Y.U;  inc (j);  if j > MaxDepth then runerror (239);
  end;
  repeat
    dec(i);  dec(j);  Result := A[i] - B[j];
  until Result <> 0;
end;

function cmpobj0 (X, Y : PNode) : integer;
var d : integer;
begin
  if X.s = 0 then begin Result := -1;  exit end;  {X = 0}
  if Y.s = 0 then begin Result := 1;   exit end;  {Y = 0}
  d := 0;
  if Y.s = 1 then begin
    while X.s > 1 do begin X := X.A;  d:=1 end;
    Result := cmpobj (X.A, Y.A)
  end else if X.s = 1 then begin
    while Y.s > 1 do begin Y := Y.A;  d:=-1 end;
    Result := cmpobj (X.A, Y.A)
  end else if X.A.s = Y.A.s then begin
    Result := cmpobj (X.A, Y.A);
    if Result = 0 then Result := cmpobj (X.B, Y.B)
  end else if X.s <= Y.A.s then begin
    Result := cmpobj (X, Y.A);  d := -1
  end else if X.A.s >= Y.s then begin
    Result := cmpobj0 (X.A, Y);  d := 1
  end else begin Result := 204; runerror (240) end;
  if Result = 0 then Result := d
end;    

function myrandom : integer;
begin random(2); Result := integer(RandSeed) end;

procedure split (X, Z : PNode; var RA, RB : PNode);
var T : PNode;
begin
  if X = nil then begin RA:=nil; RB:=nil; exit end;
  if cmpobj0 (X, Z) < 0 then begin
    split (X.R, Z, T, RB);  X.R := T;  RA := X end
  else begin
    split (X.L, Z, RA, T);  X.L := T;  RB := X end;
  if T <> nil then T.U := X
end;

function trins (R, N, Up : PNode) : PNode;
begin
  if R = nil then begin Result:=N; N.U:=Up; exit end;
  Result := R;
  if N.y > R.y then begin
    split (R, N, N.L, N.R);
    N.U := Up;
    if N.L <> nil then N.L.U := N;
    if N.R <> nil then N.R.U := N;
    Result := N
  end else if cmpobj0 (R, N) < 0 then R.R := trins (R.R, N, R)
  				 else R.L := trins (R.L, N, R)
end;

function newnode (A, B : PNode; s : integer) : PNode;
begin
  Result := newnode1 (A, B, s);
  if (Result.U <> nil) or (Result = Root) then exit;
  Result.y := myrandom;
  Root := trins (Root, Result, nil);
end;

function list2nodei (const X : array of PNode; u, v : integer) : PNode;
var s : integer;
begin
  if u > v then Result := Empty else
  if u = v then Result := newnode (X[u], nil, 1) else begin
    s := 1;
    while 2*s <= v - u do s := 2*s;
    Result := newnode (list2nodei (X, u, u+s-1), list2nodei (X, u+s, v), v-u+1)
  end;
end;

function list2nodeb (u, v : integer) : PNode;
var s : integer;  P : PNode;
begin
  if (u >= v) or (u >= N1 - 1) then Result := list2nodei (FO, u, v) else 
  if (v < N1 - 1) then begin
    P := FO[N1 - 1];  dec (v, u);
    repeat
      if P.s <= 1 then runerror (239);
      if P.A.s <= u then begin dec (u, P.A.s);  P := P.B end
      else if P.A.s > u + v then P := P.A else break
    until P = nil;
    if (P = nil) or (u <> 0) or (P.s <> v + 1) then runerror (239);
    Result := P
  end else begin
    s := 1;
    while 2*s <= v - u do s := 2*s;
    Result := newnode (list2nodeb (u, u+s-1), list2nodeb (u+s, v), v-u+1)
  end;
end;

procedure node2listi (P : PNode; var A : nodearr; u, v : integer);
var s : integer;
begin
  if P.s <> v-u+1 then runerror (239);
  if u < v then begin
    s := P.A.s;  node2listi (P.A, A, u, u+s-1);  node2listi (P.B, A, u+s, v)
  end else if u = v then A[u] := P.A;
end;

function node2list (P : PNode) : nodearr;
begin
  setlength (Result, P.s);
  node2listi (P, Result, 0, P.s-1)
end;

procedure const_to (N2 : integer);
begin
  if N2 > MaxN1 then N2 := MaxN1;
  while N1 < N2 do begin
    inc (N1);
    FO[N1] := list2nodeb (0, N1-1);
    FO[N1].v := N1;
  end
end;

procedure init_const;
var N : integer;
begin
  Root := nil;
  Empty := newnode (nil, nil, 0);
  FO[0] := Empty;  Empty.v := 0;  N1 := 0;
  const_to (high (FO));
  for N := 0 to MaxN do HV[hashstr(inttostr(N))] := FO[N];
  TotV := 0
end;

function list2nodea (const X : array of PNode; u, v : integer) : PNode;
begin
  const_to (v - u + 1);
  Result := list2nodei (X, u, v);
end;


procedure printobj0 (P : PNode; F, G : boolean);
begin
  if G then begin
    if P = nil then exit;
    if P.A <> nil then printobj0 (P.A, F, P.s > 1);
    if P.B <> nil then begin write(','); printobj0 (P.B, F, true) end
  end else if F and (P.v >= 0) then write (P.v) else begin
    write ('{');  printobj0 (P, F, true);  write ('}') end
end;

procedure printobj1 (P : PNode);
begin printobj0 (P, false, false);  writeln end;

procedure printobj (P : PNode);
begin printobj0 (P, true, false);  writeln end;

var F0, F1, F2  : boolean;

procedure f_union;	begin F0 := F1 or F2 end;
procedure f_inters;	begin F0 := F1 and F2 end;
procedure f_sub;	begin F0 := F1 and not F2 end;
procedure f_xor;	begin F0 := F1 xor F2 end;

function is_elem (Y, X : PNode) : boolean;
var A : nodearr;  i : integer;
begin
  A := node2list (X);  Result := false;
  for i := 0 to high(A) do
    if A[i] = Y then begin Result := true;  break end;
  setlength (A, 0)
end;

function calc_op (Y, Z : PNode;  Op : Lex;  f : func) : PNode;
var A, B, C  : nodearr;  i, j, L, t : integer;
begin
  if (Y.v >= 0) and (Z.v >= 0) and (Op in ['+','*']) then begin
    if (Y.v < Z.v) xor (Op = '+') then Result := Y else Result := Z;
    exit
  end;
  if Y = Z then begin
    F0 := false;
    if op in ['+','*'] then Result := Y else Result := Empty;
    exit
  end;
  if Z.v = 0 then begin 
    F0 := (Y.v <> 0);  
    if op = '*' then Result := Empty else Result := Y;  
    exit 
  end;
  if Y.v = 0 then begin 
    F0 := false;
    if op in ['+','^'] then Result := Z else Result := Empty;
    exit
  end;
  B := node2list (Y);  C := node2list (Z);
  L := Y.s + Z.s;
  if op = '-' then L := Y.s;
  if (op = '*') and (L > Z.s) then L := Z.s;
  if op = '<' then L := 0;
  setlength (A, L);  L := 0;  i := 0;  j := 0;  F0 := false;
  while (i < length(B)) or (j < length(C)) do begin
    F1 := false;  F2 := false;
    if j = length(C) then F1 := true else
    if i = length(B) then F2 := true else begin
      t := cmpobj (B[i], C[j]);
      F1 := (t <= 0);  F2 := (t >= 0)
    end;
    f;
    if F0 then begin
      if op = '<' then break;
      if F1 then A[L] := B[i] else A[L] := C[j];
      inc (L)
    end;
    inc (i, ord(F1));  inc (j, ord(F2))
  end;
  Result := list2nodea (A, 0, L-1);
  setlength (A, 0);  setlength (B, 0);  setlength (C, 0)
end;

function calc_unop (X : PNode;  Op : Lex;  f : func) : PNode;
var A : nodearr;  i : integer;
begin
  if (X.v > 0) then begin
    if Op = '*' then Result := Empty else Result := FO[X.v-1];
    exit
  end;
  A := node2list (X);
  if length (A) = 0 then begin
    Result := Empty;
    if Op = '*' then fatal ('intersection of empty set');
    exit
  end;
  Result := A[0];
  for i := 1 to high(A) do Result := calc_op (Result, A[i], Op, f);
  setlength (A, 0)
end;


procedure qsort (var A : nodearr; u, v : integer);
var h, t : PNode;  i, j : integer;
begin
  if u >= v then exit;
  h := A[(u + v) shr 1];  i := u;  j := v;
  repeat
    while cmpobj (A[i], h) < 0 do inc (i);
    while cmpobj (h, A[j]) < 0 do dec (j);
    if i <= j then begin t:=A[i]; A[i]:=A[j]; A[j]:=t; inc(i); dec(j) end
  until i > j;
  qsort (A, u, j);
  qsort (A, i, v)
end;

function read_expr : PNode; forward;

function read_list : PNode;
var A : nodearr;  i, j, L : integer;
begin
  if CL <> '{' then runerror (239);
  if getlexem = '}' then begin getlexem;  Result := Empty; exit end;
  setlength (A, 16);  L := 0;
  repeat
    if L > high(A) then setlength (A, length(A)*2);
    A[L] := read_expr;  inc (L);
    if CL <> ',' then break;
    getlexem
  until false;
  if CL <> '}' then expect ('}');
  getlexem;
  qsort (A, 0, L-1);  j := 1;
  for i := 1 to L - 1 do 
    if A[i] <> A[i-1] then begin A[j] := A[i];  inc (j) end;
  Result := list2nodea (A, 0, j-1);
  setlength (A, 0)
end;

function read_expr5 : PNode;
begin
  Result := nil;
  case CL of
  '+': begin getlexem;  Result := calc_unop (read_expr5, '+', f_union) end;
  '*': begin getlexem;  Result := calc_unop (read_expr5, '*', f_inters) end;
  _Id: begin Result := HV[CH];  getlexem end;
  '{': Result := read_list;
  '(': begin getlexem;  Result := read_expr;  if CL <> ')' then expect (')');
	 getlexem end
  else fatal ('identifier expected')
  end
end;

function read_expr4 : PNode;
begin
  Result := read_expr5;
  while CL = '*' do begin
    getlexem;  Result := calc_op (Result, read_expr5, '*', f_inters)
  end
end;

function read_expr3 : PNode;
begin
  Result := read_expr4;
  while CL = '+' do begin
    getlexem;  Result := calc_op (Result, read_expr4, '+', f_union)
  end
end;

function read_expr2 : PNode;
begin
  Result := read_expr3;
  while CL = '-' do begin
    getlexem;  Result := calc_op (Result, read_expr3, '-', f_sub)
  end
end;

function read_expr : PNode;
begin
  Result := read_expr2;
  while CL = '^' do begin
    getlexem;  Result := calc_op (Result, read_expr2, '^', f_xor)
  end
end;

function check_cond (A, B : PNode;  Rel : Lex) : boolean;
var o : integer;
begin
  case Rel of
  '<', '=', '>', _Leq, _Geq, _Neq: begin
    o := cmpobj (A, B);
    if o < 0 then Result := Rel in ['<', _Leq, _Neq] else
    if o = 0 then Result := Rel in ['=', _Leq, _Geq] else
		  Result := Rel in ['>', _Geq, _Neq];
  end;
  _In:	Result := is_elem (A, B);
  _Ni:	Result := is_elem (B, A);
  _Subset:  begin calc_op (A, B, '<', f_sub);  Result := not F0 end;
  _Supset:  begin calc_op (B, A, '<', f_sub);  Result := not F0 end
  else begin Result := false; runerror (239) end
  end
end;

var Rel : Lex;  A, B : PNode;  Id : integer;
begin
  assign (input, 'artinals.in');  reset (input);
  assign (output, 'artinals.out');  rewrite (output);
  TotV := 0;  TotO := 0;
  init_const;
  while not eof do begin
    readln (S);  S := S + #0;  P := 1;  inc (LNo);
    case getlexem of
    '#':  writeln (copy (S, 1, length(S)-1));
    '!':  begin  getlexem;  A := read_expr;
	    if CL <> #0 then fatal ('extra characters');
	    printobj (A)
	  end;
    '?':  begin  getlexem;  A := read_expr;
	    Rel := CL;
	    if not (Rel in ['<','>','=', _Leq.._Supset]) then 
	      fatal ('relation expected');
	    getlexem;  B := read_expr;
	    if CL <> #0 then fatal ('extra characters');
	    if check_cond (A, B, Rel) then writeln ('TRUE') else writeln ('FALSE')
	  end;
    _Id:  begin
	    Id := CH;  if getlexem <> _Let then expect (':=');
	    getlexem;  A := read_expr;
	    if CL <> #0 then fatal ('extra characters');
	    HV[Id] := A
	  end;
    _End: begin end;
    else fatal ('identifier expected')
    end
  end
end.
