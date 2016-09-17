var
    i: longint;
    n, m: longint;
    z, k: longint;
begin
    randseed := 94;
    n := 131072;
    m := 100;
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