{$O-,Q+,R+}
uses sysutils;
const MaxP=1 shl 19;
      MaxN=200000;
      MaxM=200000;

var a, b:array [1..MaxP*2-1] of integer;
    s:array [1..MaxN*2] of integer;
    l:array [1..MaxN] of integer;
    i, k, x, y, n, m, lx:integer;

begin
  assign (input, 'key.in'); reset (input);
  assign (output, 'key.out'); rewrite (output);
  assert (not seekeoln); read (n); assert ((n>=1) and (n<=MaxN));
  assert (not seekeoln); read (m); assert ((m>=1) and (m<=MaxM));
  assert (seekeoln); readln;
  for i:=1 to n do begin assert (not seekeoln); read (l[i]);
    assert ((l[i]>=1) and (l[i]<=m));
  end;
  assert (seekeof);
  for i:=n downto 1 do begin
    x:=MaxP-1+l[i]; y:=1; 
    if b[x]>0 then repeat
      if not odd (x) and (b[x+1]<y) then begin inc (x); break end;
      x:=x shr 1; y:=y shl 1;
    until false;
    while (x<MaxP) do begin
      y:=y shr 1; x:=x shl 1; if a[x]=y then inc (x);
    end;
    s[x-MaxP+1]:=i;
    a[x]:=1; b[x]:=1;
    repeat
      lx:=x; x:=x shr 1; y:=y shl 1;
      if x=0 then break;
      if odd (lx) then inc (b[x]) else inc (a[x]);
      if a[x]+b[x]>=y then begin a[x]:=y; b[x]:=y end;
    until (a[x]<y) and (odd (lx) xor odd (x));
  end;
  k:=0; for i:=MaxN*2 downto 1 do if s[i]<>0 then begin k:=i; break end;
  writeln (k);
  for i:=1 to k do write (s[i], ' ');
end.