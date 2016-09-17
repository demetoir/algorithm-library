
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
        for j := 1 to i do
        begin
            write(j);
            if j < k then
                write(' ')
            else
                writeln;
        end;
    end;
end.