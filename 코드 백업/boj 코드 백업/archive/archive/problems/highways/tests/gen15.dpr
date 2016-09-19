var
    i, j, n: longint;
begin
    n := 10;
    writeln(n);
    for i := 2 to n do
    begin
        j := i - 1;
        write(j * j);
        if i < n then
            write(' ')
        else
            writeln;
    end;
end.