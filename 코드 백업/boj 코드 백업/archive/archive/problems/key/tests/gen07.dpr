var
    i: longint;
    n, m: longint;
begin
    n := 20;
    m := 20;
    writeln(n, ' ', m);
    for i := 1 to n div 2 do
    begin
        write(2 * i - 1);
        write(' ')
    end;
    for i := 1 to n div 2 do
    begin
        write(2 * i);
        if i < n then
            write(' ')
        else
            writeln;
    end;
end.