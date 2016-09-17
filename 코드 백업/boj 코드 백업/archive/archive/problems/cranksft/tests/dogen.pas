{$I trans.inc}
{$O+,Q-,R-}
unit dogen;
interface
uses dorand, inter2, sysutils;
procedure genrandom (N, MinCX, MaxCX, MinCY, MaxCY, p:int64);
procedure genrandom2 (N, MinCX, MaxCX, MinCY, MaxCY, p:int64);
procedure genrandom3 (N, MinCX, MaxCX, MinCY, MaxCY, p:int64);
implementation

type integer=longint;


procedure getbox (x1, y1, x2, y2:int64; var x3, y3, x4, y4:int64);
begin
  if x1<x2 then begin x3:=x1; x4:=x2 end else begin x3:=x2; x4:=x1 end;
  if y1<y2 then begin y3:=y1; y4:=y2 end else begin y3:=y2; y4:=y1 end;
end;

function intersect (x1, y1, x2, y2, x3, y3, x4, y4:int64):boolean;
var bx1, by1, bx2, by2, bx3, by3, bx4, by4, v1, v2, v3, v4:int64;
begin
  getbox (x1, y1, x2, y2, bx1, by1, bx2, by2);
  getbox (x3, y3, x4, y4, bx3, by3, bx4, by4);
  if (bx2<bx3) or (bx1>bx4) or (by2<by3) or (by1>by4) then begin Result:=false; exit end;
  v1:=(x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
  v2:=(x2-x1)*(y4-y1)-(x4-x1)*(y2-y1);
  if v1*v2>0 then begin Result:=false; exit end;
  v3:=(x4-x3)*(y1-y3)-(x1-x3)*(y4-y3);
  v4:=(x4-x3)*(y2-y3)-(x2-x3)*(y4-y3);
  Result:=v3*v4<=0;
end;

const inf=1e1000;

procedure genrandom (N, MinCX, MaxCX, MinCY, MaxCY, p:int64);
var x, y:array of int64;
    cur, min:extended;
    i, j, mi, mj:integer;
    changes, Res1:boolean;
    ops,sum, cnt, tmp:int64;
label start;
begin
  start:
  ops:=0;
  regint (N); regint (MinCX); regint (MaxCX); regint (MinCY); regint (MaxCY); regint (p);
  setlength (x, N+2); setlength (y, N+2);
  for i:=0 to N-1 do begin
    x[i]:=randr (MinCX, MaxCX);
    y[i]:=randr (MinCY, MaxCY);
  end;
  repeat
    x[N]:=x[0]; y[N]:=y[0]; x[N+1]:=x[1]; y[N+1]:=y[1];
    min:=inf; mi:=-1; mj:=-1; changes:=false;
    for i := 0 to N-1 do
      for j := i+2 to N-1 do
        if j-i<N-1 then begin
          Res1:=intersect (x[i], y[i], x[i+1], y[i+1], x[j], y[j], x[j+1], y[j+1]);
          {Res2:=inter2.intersect (x[i], y[i], x[i+1], y[i+1], x[j], y[j], x[j+1], y[j+1], xp, yp);
          if Res1 xor (Res2<>0) then begin
            writeln (Res2);
            writeln (x[i], ' ', y[i], ' ', x[i+1], ' ', y[i+1]);
            writeln (x[j], ' ', y[j], ' ', x[j+1], ' ', y[j+1]);
            assert (false);
          end;}
          if Res1 then begin
            cur:=random;
            if cur<min then begin min:=cur; mi:=i; mj:=j end;
            changes:=true;
          end;
        end;
    if not changes then break;
    if coin then begin
      tmp:=x[mi]; x[mi]:=x[mj]; x[mj]:=tmp;
      tmp:=y[mi]; y[mi]:=y[mj]; y[mj]:=tmp;
    end else begin
      inc (mi); if mi>=N then dec (mi, N);
      tmp:=x[mi]; x[mi]:=x[mj]; x[mj]:=tmp;
      tmp:=y[mi]; y[mi]:=y[mj]; y[mj]:=tmp;
    end;
    inc (ops);
    if ops>N*N then goto start;
  until not changes;
  x[N]:=x[0]; y[N]:=y[0];
  x[N+1]:=x[1]; y[N+1]:=y[1];
  sum:=0;
  for i:=1 to N do
    sum:=sum+(x[i-1]-x[i])*(y[i]+y[i-1]);
  if sum>0 then
    for i:=1 to N shr 1 do begin
      tmp:=x[i]; x[i]:=x[N-i+1]; x[N-i+1]:=tmp;
      tmp:=y[i]; y[i]:=y[N-i+1]; y[N-i+1]:=tmp;
    end;
  x[0]:=x[N]; y[0]:=y[N];
  x[N+1]:=x[1]; y[N+1]:=y[1];
  cnt:=0;
  for i:=1 to N do
    if (x[i]-x[i-1])*(y[i+1]-y[i])-(x[i+1]-x[i])*(y[i]-y[i-1])<>0 then
      inc (cnt);
  writeln (cnt);
  for i:=1 to N do
    if (x[i]-x[i-1])*(y[i+1]-y[i])-(x[i+1]-x[i])*(y[i]-y[i-1])<>0 then
      writeln (x[i], ' ', y[i]);
end;

procedure genrandom2 (N, MinCX, MaxCX, MinCY, MaxCY, p:int64);
var x, y:array of int64;
    cur, min, xp, yp:extended;
    i, j, mi, mj, Res2:integer;
    changes, Res1:boolean;
    ops,sum, cnt, tmp:int64;
label start;
begin
  start:
  ops:=0;
  regint (N); regint (MinCX); regint (MaxCX); regint (MinCY); regint (MaxCY); regint (p);
  setlength (x, N+2); setlength (y, N+2);
  for i:=0 to N-1 do begin
    x[i]:=randr (MinCX, MaxCX);
    y[i]:=randr (MinCY, MaxCY);
  end;
  repeat
    x[N]:=x[0]; y[N]:=y[0]; x[N+1]:=x[1]; y[N+1]:=y[1];
    min:=inf; mi:=-1; mj:=-1; changes:=false;
    for i := 0 to N-1 do
      for j := i+2 to N-1 do
        if j-i<N-1 then begin
          Res1:=intersect (x[i], y[i], x[i+1], y[i+1], x[j], y[j], x[j+1], y[j+1]);
          {Res2:=inter2.intersect (x[i], y[i], x[i+1], y[i+1], x[j], y[j], x[j+1], y[j+1], xp, yp);
          if Res1 xor (Res2<>0) then begin
            writeln (Res2);
            writeln (x[i], ' ', y[i], ' ', x[i+1], ' ', y[i+1]);
            writeln (x[j], ' ', y[j], ' ', x[j+1], ' ', y[j+1]);
            assert (false);
          end;}
          if Res1 then begin
            mi:=i; mj:=j;
            changes:=true;
            if coin then break;
          end;
        end;
    if not changes then break;
    if coin then begin
      tmp:=x[mi]; x[mi]:=x[mj]; x[mj]:=tmp;
      tmp:=y[mi]; y[mi]:=y[mj]; y[mj]:=tmp;
    end else begin
      inc (mi); if mi>=N then dec (mi, N);
      tmp:=x[mi]; x[mi]:=x[mj]; x[mj]:=tmp;
      tmp:=y[mi]; y[mi]:=y[mj]; y[mj]:=tmp;
    end;
    writeln (mi, ' ', mj);
    inc (ops);
    if ops>N*N then goto start;
  until not changes;
  x[N]:=x[0]; y[N]:=y[0];
  x[N+1]:=x[1]; y[N+1]:=y[1];
  sum:=0;
  for i:=1 to N do
    sum:=sum+(x[i-1]-x[i])*(y[i]+y[i-1]);
  if sum>0 then
    for i:=1 to N shr 1 do begin
      tmp:=x[i]; x[i]:=x[N-i+1]; x[N-i+1]:=tmp;
      tmp:=y[i]; y[i]:=y[N-i+1]; y[N-i+1]:=tmp;
    end;
  x[0]:=x[N]; y[0]:=y[N];
  x[N+1]:=x[1]; y[N+1]:=y[1];
  cnt:=0;
  for i:=1 to N do
    if (x[i]-x[i-1])*(y[i+1]-y[i])-(x[i+1]-x[i])*(y[i]-y[i-1])<>0 then
      inc (cnt);
  writeln (cnt);
  for i:=1 to N do
    if (x[i]-x[i-1])*(y[i+1]-y[i])-(x[i+1]-x[i])*(y[i]-y[i-1])<>0 then
      writeln (x[i], ' ', y[i]);
end;

procedure genrandom3 (N, MinCX, MaxCX, MinCY, MaxCY, p:int64);
var x, y:array of int64;
    cur, min:extended;
    i, j, mi, mj:integer;
    changes, Res1:boolean;
    ops,sum, cnt, tmp:int64;
label start;
begin
  start:
  ops:=0;
  regint (N); regint (MinCX); regint (MaxCX); regint (MinCY); regint (MaxCY); regint (p);
  setlength (x, N+2); setlength (y, N+2);
  for i:=0 to N-1 do begin
    x[i]:=randr (MinCX, MaxCX);
    y[i]:=randr (MinCY, MaxCY);
  end;
  repeat
    x[N]:=x[0]; y[N]:=y[0]; x[N+1]:=x[1]; y[N+1]:=y[1];
    min:=inf; mi:=-1; mj:=-1; changes:=false;
    for i := 0 to N-1 do
      for j := i+2 to N-1 do
        if j-i<N-1 then begin
          Res1:=intersect (x[i], y[i], x[i+1], y[i+1], x[j], y[j], x[j+1], y[j+1]);
          {Res2:=inter2.intersect (x[i], y[i], x[i+1], y[i+1], x[j], y[j], x[j+1], y[j+1], xp, yp);
          if Res1 xor (Res2<>0) then begin
            writeln (Res2);
            writeln (x[i], ' ', y[i], ' ', x[i+1], ' ', y[i+1]);
            writeln (x[j], ' ', y[j], ' ', x[j+1], ' ', y[j+1]);
            assert (false);
          end;}
          if Res1 then begin
            cur:=random;
            if cur<min then begin min:=cur; mi:=i; mj:=j end;
            changes:=true;
          end;
        end;
    if not changes then break;
    for i:=mi+1 to (mi+mj) shr 1 do begin
      tmp:=x[i]; x[i]:=x[mj-i+mi+1]; x[mj-i+mi+1]:=tmp;
      tmp:=y[i]; y[i]:=y[mj-i+mi+1]; y[mj-i+mi+1]:=tmp;
    end;
    inc (ops);
    if ops>N*N then goto start;
  until not changes;
  x[N]:=x[0]; y[N]:=y[0];
  x[N+1]:=x[1]; y[N+1]:=y[1];
  sum:=0;
  for i:=1 to N do
    sum:=sum+(x[i-1]-x[i])*(y[i]+y[i-1]);
  if sum>0 then
    for i:=1 to N shr 1 do begin
      tmp:=x[i]; x[i]:=x[N-i+1]; x[N-i+1]:=tmp;
      tmp:=y[i]; y[i]:=y[N-i+1]; y[N-i+1]:=tmp;
    end;
  x[0]:=x[N]; y[0]:=y[N];
  x[N+1]:=x[1]; y[N+1]:=y[1];
  cnt:=0;
  for i:=1 to N do
    if (x[i]-x[i-1])*(y[i+1]-y[i])-(x[i+1]-x[i])*(y[i]-y[i-1])<>0 then
      inc (cnt);
  writeln (cnt);
  for i:=1 to N do
    if (x[i]-x[i-1])*(y[i+1]-y[i])-(x[i+1]-x[i])*(y[i]-y[i-1])<>0 then
      writeln (x[i], ' ', y[i]);
end;


end.
