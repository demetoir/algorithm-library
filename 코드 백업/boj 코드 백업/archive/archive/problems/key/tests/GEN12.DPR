var
    i: longint;
    n, m: longint;
    k: longint;
begin
    randseed := 33;
    n := 256;
    m := 5;
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