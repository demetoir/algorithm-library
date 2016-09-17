var
    i, j: longint;
    n: longint;
begin
    n := 22;
    writeln(n * n);
    for i := 1 to n do
        for j := 1 to n do
            write(i, ' ');
    writeln;
    writeln(n * n);
    for i := 1 to n do
        for j := 1 to n do
            write(i, ' ');
end.