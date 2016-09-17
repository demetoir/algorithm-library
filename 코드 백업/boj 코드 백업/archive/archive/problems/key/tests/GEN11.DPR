var
    i: longint;
    n, m: longint;
    k: longint;
begin
    randseed := 32;
    n := 32;
    m := 131072;
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