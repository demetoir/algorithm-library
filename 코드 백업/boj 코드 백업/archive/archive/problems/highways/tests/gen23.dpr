const
    maxn = 100000;
var
    i, j, n: longint;
    delta: longint;
    a: array [1..maxn] of longint;
begin
    n := 1000;
    writeln(n);
    j := 5;
    delta := 4;
    for i := 3 to n - 1 do
    begin
        if (i div 40) mod 2 = 0 then
            inc(j)
        else if j > 0 then
            dec(j);
        a[i] := j * j * j + delta;
        if i = n div 2 then
            dec(j);
    end;
    a[2] := 1;
    a[n] := 1;
    for i := 2 to n do
    begin
        a[i] := a[i] + a[i - 1];
    end;
    for i := 2 to n do
    begin
        write(a[i] - a[1]);
        if i < n then
            write(' ')
        else
            writeln;
    end;
end.