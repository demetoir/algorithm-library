{$APPTYPE CONSOLE}
{$Q+,R+,O-}
uses math, sysutils;

const LongL=5;
      Base=1000000000;
      LogBase=9;
      MaxN=18;
type State=record
       c0:boolean;
       c2, c3, c5, c7:integer;
       cf:integer;
     end;
     Long=array [1..LongL] of integer;

procedure add (var a, b, c:long);
var i, cy:integer;
begin
  cy:=0;
  for i:=1 to LongL do begin
    inc (cy, b[i]+c[i]);
    if cy>=Base then begin a[i]:=cy-Base; cy:=1 end
                else begin a[i]:=cy;      cy:=0 end;
  end;
  if cy>0 then runerror (239);
end;


procedure sub (var a, b, c:long);
var i, cy:integer;
begin
  cy:=0;
  for i:=1 to LongL do begin
    inc (cy, b[i]-c[i]);
    if cy<0 then begin a[i]:=cy+Base; cy:=-1 end
            else begin a[i]:=cy;      cy:= 0 end;
  end;
  if cy<0 then runerror (239);
end;


procedure muls (var a, b:long; s:int64);
var cy:int64;
    i:integer;
begin
  cy:=0;
  for i:=1 to LongL do begin
    cy:=cy+b[i]*s;
    a[i]:=cy mod Base; cy:=cy div Base;
  end;
  if cy>0 then runerror (239);
end;

{x, y<Base^2=10^18}
procedure mul2int64 (var Res:long; x, y:int64);
var a, b, c, d, tmp:int64;
begin
  a:=x div Base; b:=x mod Base;
  c:=y div Base; d:=y mod Base;
  Res[1]:=(b*d) mod Base;
  tmp:=(b*d) div Base + (a*d+b*c);
  Res[2]:=tmp mod Base;
  tmp:=tmp div Base + a*c;
  Res[3]:=tmp mod Base;
  Res[4]:=tmp div Base;
end;


procedure WriteB (x:integer);
var s:string;
begin
  str (x, s); while length (s)<LogBase do s:='0'+s;
  write (s);
end;


procedure WriteL (var a:long);
var i, k:integer;
begin
  k:=1; for i:=LongL downto 1 do if a[i]<>0 then begin k:=i; break end;
  write (a[k]); for i:=k-1 downto 1 do WriteB (a[i]);
  writeln;
end;


procedure Set0 (var a:long);
begin
  fillchar (a, sizeof (a), 0);
end;


procedure Set1 (var a:long);
begin
  Set0 (a); a[1]:=1;
end;


procedure getrec (s:string; l, r:integer; var st:state);
var i:integer;
begin
  with st do
    for i:=l to r do case s[i] of
      '0':c0:=true;
      '1':;
      '2':inc (c2);
      '3':inc (c3);
      '4':inc (c2, 2);
      '5':inc (c5);
      '6':begin inc (c2); inc (c3) end;
      '7':inc (c7);
      '8':inc (c2, 3);
      '9':inc (c3, 2);
      '?':inc (cf);
    end;
end;


var c:array [0..MaxN, -1..MaxN] of integer;
    d:array [-3..MaxN*3, -2..MaxN*2, 0..MaxN] of int64;


procedure Rec5 (var l, r:state; cl, cr:integer; var Res:long);
var Acc, Bcc:long;
    l2, l3, l2min, l2max, l3min, l3max:integer;
begin
  if (l.cf>0) and (r.cf>0) then begin
    inc (l.c5); inc (r.c5);
    dec (l.cf); dec (r.cf);
    Rec5 (l, r, cl+1, cr+1, Res);
    inc (l.cf); inc (r.cf);
    dec (l.c5); dec (r.c5);
  end else Set0 (Res);
  l2min:=max (r.c2-l.c2, 0);
  l2max:=l.cf*3;
  l3min:=max (r.c3-l.c3, 0);
  l3max:=l.cf*2;
  Set0 (Acc);
  for l2:=l2min to l2max do
    for l3:=l3min to l3max do 
      begin
        Set0 (Bcc);
        mul2int64 (Bcc, d[l2, l3, l.cf], d[l.c2+l2-r.c2, l.c3+l3-r.c3, r.cf]);
        add (Acc, Acc, Bcc);
      end;
  muls (Acc, Acc, c[l.cf+cl, cl]);
  muls (Acc, Acc, c[r.cf+cr, cr]);
  add (Res, Res, Acc);
end;


procedure Rec7 (var l, r:state; cl, cr:integer; var Res:long);
var Acc:Long;
    l5, r5:integer;
begin
  if (l.cf>0) and (r.cf>0) then begin
    inc (l.c7); inc (r.c7);
    dec (l.cf); dec (r.cf);
    Rec7 (l, r, cl+1, cr+1, Res);
    inc (l.cf); inc (r.cf);
    dec (l.c7); dec (r.c7);
  end else Set0 (Res);
  l5:=max (r.c5-l.c5, 0);
  r5:=max (l.c5-r.c5, 0);
  if (r5>r.cf) or (l5>l.cf) then exit;
  inc (l.c5, l5); dec (l.cf, l5);
  inc (r.c5, r5); dec (r.cf, r5);
  Rec5 (l, r, l5, r5, Acc);
  dec (l.c5, l5); inc (l.cf, l5);
  dec (r.c5, r5); inc (r.cf, r5);
  muls (Acc, Acc, c[l.cf+cl, cl]);
  muls (Acc, Acc, c[r.cf+cr, cr]);
  add (Res, Res, Acc);
end;


procedure Answer (var l, r:State; var Res:long);
var tmp:State;
    Acc, Bcc, Ccc:long;
    i, r7:integer;
begin
  if l.c0 and r.c0 then begin
    Set1 (Res); for i:=1 to l.cf+r.cf do muls (Res, Res, 10);
    exit;
  end;
  if r.c0 then begin tmp:=l; l:=r; r:=tmp end;
  if l.c0 then begin
    Set1 (Res); for i:=1 to r.cf do muls (Res, Res, 10);
    Set1 (Acc); for i:=1 to r.cf do muls (Acc, Acc, 9);
    sub (Res, Res, Acc);
    for i:=1 to l.cf do muls (Res, Res, 10);
    exit;
  end;
  if (r.cf>0) and (l.cf>0) then begin
    Set1 (Res); for i:=1 to l.cf do muls (Res, Res, 10);
    Set1 (Acc); for i:=1 to l.cf do muls (Acc, Acc, 9);
    Bcc:=Res; Ccc:=Acc;
    for i:=1 to r.cf do muls (Res, Res, 10);
    for i:=1 to r.cf do muls (Acc, Acc, 9);
    for i:=1 to r.cf do muls (Bcc, Bcc, 9);
    for i:=1 to r.cf do muls (Ccc, Ccc, 10);
    Add (Res, Res, Acc);
    Sub (Res, Res, Bcc);
    Sub (Res, Res, Ccc);
  end else Set0 (ReS);
  if l.c7<r.c7 then begin tmp:=l; l:=r; r:=tmp end;
  if l.c7-r.c7>r.cf then exit;
  r7:=l.c7-r.c7; dec (r.cf, r7); inc (r.c7, r7);
  Rec7 (l, r, 0, r7, Acc);
  Add (Res, Res, Acc);
end;


var l, r:state;
    s:string;
    i, j, k, N:integer;
    Res, Banal:long;


begin
  c[0, 0]:=1;
  for i:=1 to MaxN do
    for j:=0 to MaxN do
      c[i, j]:=c[i-1, j-1]+c[i-1, j];
  d[0, 0, 0]:=1;
  for k:=1 to MaxN do
    for i:=0 to MaxN*3 do
      for j:=0 to MaxN*2 do
        d[i, j, k]:=d[i-1, j, k-1]+
                    d[i-2, j, k-1]+
                    d[i-3, j, k-1]+
                    d[i, j-1, k-1]+
                    d[i, j-2, k-1]+
                    d[i-1, j-1, k-1]+
                    d[i, j, k-1];
  for k:=0 to MaxN do
    for i:=0 to MaxN*3 do
      for j:=0 to MaxN*2 do
        if (d[i, j, k]>=int64 (Base)*Base) or (d[i, j, k]<0) then
          runerror (239);
  assign (input, 'banal.in'); reset (input);
  assign (output, 'banal.out'); rewrite (output);
  readln (N);
  if (N<1) or (N>MaxN) then runerror (239);
  readln (s);
  if length (s)<>2*N then runerror (239);
  for i:=1 to length (s) do if not (s[i] in ['0'..'9', '?']) then runerror (239);
  if not seekeof then runerror (239);
  GetRec (s, 1, N, l);
  GetRec (s, N+1, N+N, r);
  Set1 (Banal); for i:=1 to l.cf+r.cf do MulS (Banal, Banal, 10);
  Answer (l, r, Res);
  Sub (Banal, Banal, Res);
  WriteL (Res);
  WriteL (Banal);
end.