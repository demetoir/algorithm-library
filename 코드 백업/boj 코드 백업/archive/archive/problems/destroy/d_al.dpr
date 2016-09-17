{$O-,Q+,R+}                    
uses sysutils, math;
{$I const.inc}

var f1, f2:array [1..MaxN] of boolean;
    g:array [1..MaxN, 1..MaxN] of boolean;
    wp, wm, wlp, wlm:array [1..MaxN] of integer;
    c:array [1..MaxN, 1..MaxN] of integer;
    a, n:integer;

function poisk1 (i, b:integer):integer;forward;


function poisk2 (i, b:integer):integer;
var j:integer;
begin
  f2[i]:=true;
  if wp[i]>=a then begin Result:=min (wp[i], b); dec (wp[i], Result); exit end;
  for j:=1 to n do
    if not f1[j] and (c[j, i]>=a) then begin Result:=poisk1 (j, min (c[j, i], b));
      if Result>0 then begin dec (c[j, i], Result); exit end;
    end;
  Result:=0;
end;


function poisk1 (i, b:integer):integer;
var j:integer;
begin
  f1[i]:=true;
  for j:=1 to n do
    if not f2[j] and g[i, j] then begin Result:=poisk2 (j, b);
      if Result>0 then begin inc (c[i, j], Result); exit end;
    end;
  Result:=0;
end;


function sol:integer;
var i:integer;
begin
  fillchar (f1, sizeof (f1), 0);
  fillchar (f2, sizeof (f2), 0);
  for i:=1 to n do begin
    if (wm[i]>=a) then begin Result:=poisk1 (i, wm[i]);
      if Result>0 then begin dec (wm[i], Result); exit end;
    end;
  end;
  Result:=0;
end;

var i, m, x, y, sum, cur, test, cnt:integer;

begin
  assign (input, 'destroy.in'); reset (input);
  assign (output, 'destroy.out'); rewrite (output);
  assert (not seekeoln); read (n); assert ((n>=1) and (n<=MaxN));
  assert (not seekeoln); read (m); assert ((m>=1) and (m<=MaxM));
  assert (seekeoln); readln;
  for i:=1 to n do begin assert (not seekeoln); read (wp[i]) end;
  wlp:=wp;
  assert (seekeoln); readln;
  for i:=1 to n do begin assert (not seekeoln); read (wm[i]) end;
  wlm:=wm;
  assert (seekeoln); readln;
  for i:=1 to m do begin
    assert (not seekeoln); read (x);
    assert (not seekeoln); read (y);
    assert (seekeoln); readln;
    assert ((x>=1) and (x<=n) and (y>=1) and (y<=n));
    g[x, y]:=true;
  end;
  assert (seekeof);
  a:=1 shl 19; sum:=0;
  repeat cur:=sol; if cur=0 then a:=a shr 1 else inc (sum, cur) until a=0;
  writeln (sum);
  fillchar (f1, sizeof (f1), 0);
  fillchar (f2, sizeof (f2), 0);
  a:=1;
  for i:=1 to n do if wm[i]>0 then poisk1 (i, wm[i]);
  for i:=1 to n do f1[i]:=not f1[i];
  test:=0; cnt:=0;
  for i:=1 to n do if f1[i] then begin inc (cnt); inc (test, wlm[i]) end;
  for i:=1 to n do if f2[i] then begin inc (cnt); inc (test, wlp[i]) end;
  assert (sum=test);
  writeln (cnt);
  for i:=1 to n do if f1[i] then writeln (i, ' -');
  for i:=1 to n do if f2[i] then writeln (i, ' +');
end.
