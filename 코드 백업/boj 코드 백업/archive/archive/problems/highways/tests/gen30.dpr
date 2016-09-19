const
    maxn = 100000;
    max = 1000000000;
var
    i, j, n: longint;
    delta: longint;
    a: array [1..maxn] of longint;
begin
    n := 49997;
    randseed := 18;
    writeln(n);
    j := 5;
    delta := 4;
    for i := 1 to n do
    begin
        a[i] := 2;
    end;
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