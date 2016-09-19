uses
    sysutils;
var
    m, i, j, k, l, n: longint;
    a: array [1..100, 1..100] of boolean;
begin
    n := 100;

    m := 0;
    for i := 1 to n div 2 do
    begin
        for j := i to i + n div 2 do
        begin
            a[i][j] := true;
            inc(m);
        end;
    end;
    for i := n div 2 + 1 to n do
    begin
        a[i][i - n div 2] := true;
        inc(m);
    end;

    writeln(n, ' ', m);
    for j := 1 to 2 do
    begin
        for i := 1 to n do
        begin
            write(1);
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