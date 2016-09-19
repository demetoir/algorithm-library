var
    i, n: longint;
begin
    n := 10;
    writeln(n);
    for i := 2 to n do
    begin
        write(i - 1);
        if i < n then
            write(' ')
        else
            writeln;
    end;
end.