var
    i: longint;
    n, m: longint;
begin
    n := 131072;
    m := 131072;
    writeln(n, ' ', m);
    for i := 1 to n do
    begin
        write(m + 1 - i);
        if i < n then
            write(' ')
        else
            writeln;
    end;
end.