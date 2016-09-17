var
    i: longint;
    n, m: longint;
begin
    randomize;
    n := 100000;
    m := 100000;
    writeln(n, ' ', m);
    for i := 1 to n do
    begin
        write(random(m) + 1);
        if i < n then
            write(' ')
        else
            writeln;
    end;
end.