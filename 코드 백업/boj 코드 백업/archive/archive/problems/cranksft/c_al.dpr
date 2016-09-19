{$I trans.inc}
{$O-,Q+,R+}
uses inter2, sysutils;

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


const MaxT=100;
      MaxN=200;
      MaxC=10000;

var x, y:array [0..MaxN+1] of int64;
    xm, ym, mm:array [1..MaxN*2] of extended;
    xp, yp, mp:array [1..MaxT] of extended;
    i, j, k, T, N, Res2, sum:integer;
    xz, yz, xsum, ysum, msum:extended;
    Res1:boolean;

begin
  assign (input, 'cranksft.in'); reset (input);
  assign (output, 'cranksft.out'); rewrite (output);
  read (T); assert ((T>=1) and (T<=MaxT));
  for k:=1 to T do begin
    read (N); assert ((N>=3) and (N<=MaxN));
    for i:=1 to N do begin read (x[i], y[i]); assert ((x[i]>=-MaxC) and (x[i]<=MaxC));
      assert ((y[i]>=-MaxC) and (y[i]<=MaxC));
    end;
    x[0]:=x[N]; y[0]:=y[N]; x[N+1]:=x[1]; y[N+1]:=y[1];
    for i := 0 to N-1 do
      for j := i+2 to N-1 do begin
        Res1:=intersect (x[i], y[i], x[i+1], y[i+1], x[j], y[j], x[j+1], y[j+1]);
        Res2:=inter2.intersect (x[i], y[i], x[i+1], y[i+1], x[j], y[j], x[j+1], y[j+1], xz, yz);
        if Res1 xor (Res2<>0) then begin
          writeln (Res2);
          writeln (x[i], ' ', y[i], ' ', x[i+1], ' ', y[i+1]);
          writeln (x[j], ' ', y[j], ' ', x[j+1], ' ', y[j+1]);
          assert (false);
        end;
        if (j-i<N-1) and Res1 then
          assert (false);
      end;
    sum:=0;
    for i:=1 to N do
      sum:=sum+(x[i-1]-x[i])*(y[i]+y[i-1]);
    if sum>0 then assert (false);
    for i:=1 to N do
      if (x[i]-x[i-1])*(y[i+1]-y[i])-(x[i+1]-x[i])*(y[i]-y[i-1])=0 then
        assert (false);
    for i:=1 to N do begin
      xm[i]:=(x[i]+x[i+1])/2;
      ym[i]:=y[i]/2;
      mm[i]:=(x[i+1]-x[i])*y[i];
      xm[N+i]:=(2*x[i+1]+x[i])/3;
      ym[N+i]:=(y[i+1]+2*y[i])/3;
      mm[N+i]:=(y[i+1]-y[i])*(x[i+1]-x[i])/2;
    end;
    xsum:=0; ysum:=0; msum:=0;
    for i:=1 to N+N do begin
      xsum:=xsum+xm[i]*mm[i];
      ysum:=ysum+ym[i]*mm[i];
      msum:=msum+mm[i];
    end;
    xp[k]:=xsum/msum;
    yp[k]:=ysum/msum;
    mp[k]:=msum;
  end;
  xsum:=0; ysum:=0; msum:=0;
  for i:=1 to T do begin
    xsum:=xsum+xp[i]*mp[i];
    ysum:=ysum+yp[i]*mp[i];
    msum:=msum+mp[i];
  end;
  writeln (xsum/msum:0:15, ' ', ysum/msum:0:15);
  assert (seekeof);
end.