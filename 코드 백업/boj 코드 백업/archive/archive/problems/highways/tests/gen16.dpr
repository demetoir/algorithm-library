const
    maxn = 100000;
var
    i, j, n: longint;
    a: array [1..maxn] of longint;
begin
    n := 10;
    writeln(n);
    for i := 10 downto 1 do
    begin
        j := 11 - i;
        a[i] := j * j;
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