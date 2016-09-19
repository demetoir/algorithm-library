
var
    k, i: longint;
    n, m: longint;
    p, sz, pieces, j: longint;
begin
    k := 256;
    n := k * (k + 1) div 2 + k;
    m := n;
    writeln(n, ' ', m);
    for i := k downto 1 do
    begin
        for j := k - i + 1 downto 1 do
        begin
            write(i * (i + 1) div 2);
            write(' ')
        end;
    end;
    for i := k downto 1 do
    begin
        write(i * (i + 1) div 2);
        if i > 1 then
            write(' ')
        else
            writeln;
    end;
end.