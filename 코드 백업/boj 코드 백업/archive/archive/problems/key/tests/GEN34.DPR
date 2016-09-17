var
    i: longint;
    n, m: longint;
begin
    n := 131072;
    m := 131072;
    writeln(n, ' ', m);
    for i := 1 to n do
    begin
        if i <= n div 2 then
            write(i * 2)
        else
            write(i * 2 - n - 1);
        if i < n then
            write(' ')
        else
            writeln;
    end;
end.