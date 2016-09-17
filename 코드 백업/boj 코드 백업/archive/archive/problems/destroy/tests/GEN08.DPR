uses
    sysutils;
const
    maxw = 1000000;
var
    m, i, j, k, l, n: longint;
    a: array [1..100, 1..100] of longint;
    delta: real;
begin
    n := 10;
    k := 500;

    randseed := 48;
    delta := 0.92411950;

    m := 0;
    for i := 1 to n do
    begin
        for j := i + 1 to i + k do
        begin
            inc(a[i][(j - 1) mod n + 1]);
            inc(m);
        end;
    end;

    writeln(n, ' ', m);
    for j := 1 to 2 do
    begin
        for i := 1 to n do
        begin
            write(random(maxw) + 1);
            if i < n then write(' ') else writeln;
        end;
    end;

    for i := 1 to n do
    begin
        for j := 1 to n do
        begin
            for k := 1 to a[i][j] do
                writeln(i, ' ', j);
        end;
    end;

end.