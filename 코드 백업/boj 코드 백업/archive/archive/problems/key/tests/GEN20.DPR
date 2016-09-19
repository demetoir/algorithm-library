
var
    k, i: longint;
    n, m: longint;
    p, sz, pieces, j: longint;
begin
    k := 256;
    n := k * (k + 1) div 2;
    m := 2 * k;
    writeln(n, ' ', m);
    for i := k downto 1 do
    begin
        for j := i downto 1 do
        begin
            write(2 * i);
            if (i > 1) or (j > 1) then
                write(' ')
            else
                writeln;
        end;
    end;
end.