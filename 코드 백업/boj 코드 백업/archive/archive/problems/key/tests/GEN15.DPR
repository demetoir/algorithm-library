var
    i: longint;
    n, m: longint;
    k: longint;
begin
    randseed := 35;
    n := 1024;
    m := 16384;
    writeln(n, ' ', m);
    for i := 1 to n do
    begin
        k := random(m) + 1;
        write(k);
        if i < n then
            write(' ')
        else
            writeln;
    end;
end.