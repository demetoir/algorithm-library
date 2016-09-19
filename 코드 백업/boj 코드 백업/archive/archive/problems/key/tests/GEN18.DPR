
var
    k, i: longint;
    n, m: longint;
    p, sz, pieces, j: longint;
begin
    k := 256;
    n := k * (k + 1) div 2;
    m := k;
    writeln(n, ' ', m);
    for i := 1 to k do
    begin
        for j := i downto 1 do
        begin
            write(i);
            if (i < k) or (j > 1) then
                write(' ')
            else
                writeln;
        end;
    end;
end.