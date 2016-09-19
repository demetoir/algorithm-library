var
    i: longint;
    n, m: longint;
begin
    n := 20;
    m := 20;
    writeln(n, ' ', m);
    for i := 1 to n do
    begin
        write(i);
        if i < n then
            write(' ')
        else
            writeln;
    end;
end.