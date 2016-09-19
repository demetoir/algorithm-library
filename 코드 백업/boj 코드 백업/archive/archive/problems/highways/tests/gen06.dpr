const
    maxn = 100000;

    n = 4;
    perm: array [1..n] of longint = (0, 2, 1, 1);
var
    i, j: longint;
    a: array [1..maxn] of longint;
begin
    writeln(n);

    for i := 1 to n do
    begin
        a[i] := perm[i];
    end;
    for i := 2 to 10 do
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