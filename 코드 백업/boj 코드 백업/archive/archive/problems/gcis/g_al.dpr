{$Q-,R-,O+}
const MaxM=500;
var i, j, k, m, n, max, maxi:integer;
    a, b:array [1..MaxM] of integer;
    l, p:array [0..MaxM, 0..MaxM] of integer;

begin
  assign (input, 'gcis.in'); reset (input);
  assign (output, 'gcis.out'); rewrite (output);
  read (m); if (m<1) or (m>MaxM) then runerror (239);
  for i:=m downto 1 do read (a[i]);
  read (n); if (n<1) or (n>MaxM) then runerror (239);
  for i:=n downto 1 do read (b[i]);
  for i:=1 to m do
    for j:=1 to n do begin
      l[i, j]:=l[i, j-1]; p[i, j]:=i;
      if a[i]=b[j] then begin
        if l[i, j]<1 then begin l[i, j]:=1; p[i, j]:=0 end;
        for k:=1 to i-1 do
          if (a[k]>a[i]) and (l[k, j-1]+1>l[i, j]) then begin
            l[i, j]:=l[k, j-1]+1; p[i, j]:=k;
          end;
      end;
    end;
  max:=-1; maxi:=0;
  for i:=1 to m do if l[i, n]>max then begin max:=l[i, n]; maxi:=i end;
  writeln (max);
  i:=maxi;
  for j:=n downto 1 do begin
    if p[i, j]<>i then write (a[i], ' ');
    i:=p[i, j];
  end;
  writeln;
end.