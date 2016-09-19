const
    maxn = 100000;
    max = 1000000000;
var
    i, j, n: longint;
    delta: longint;
    a: array [1..maxn] of longint;
begin
    n := 10000;
    randseed := 15;
    writeln(n);
    j := 5;
    delta := 4;
    for i := 1 to n do
    begin
        a[i] := random(max div n) + 1;
    end;
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