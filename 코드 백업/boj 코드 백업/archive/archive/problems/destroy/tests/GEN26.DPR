uses
    sysutils;
var
    m, i, j, k, l, n: longint;
    a: array [1..100, 1..100] of boolean;
begin
    n := 100;
    k := 1;

    m := 0;
    for i := 1 to n do
    begin
        for j := i + 1 to i + k do
        begin
            a[i][(j - 1) mod n + 1] := true;
            inc(m);
        end;
    end;

    writeln(n, ' ', m);
    for j := 1 to 2 do
    begin
        for i := 1 to n do
        begin
            write(j);
            if i < n then write(' ') else writeln;
        end;
    end;

    for i := 1 to n do
    begin
        for j := 1 to n do
            if a[i][j] then
                writeln(i, ' ', j);
    end;

end.