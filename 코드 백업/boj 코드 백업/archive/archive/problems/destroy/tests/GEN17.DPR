{$i const.inc}
var
    n, m, i, j: longint;
begin
    n := maxn;
    m := maxm;
    writeln(n, ' ', m);
    for j := 1 to 2 do
    begin
        for i := 1 to n do
        begin
            if (i < (n div 2)) and (j = 1) then
                write(i * 2 * j + 1)
            else
                write(i * (3 - j) + 1);
            if i < n then
                write(' ')
            else
                writeln;
        end;
    end;
    for i := 1 to m do
    begin
        writeln(random(n) + 1, ' ', random(n) + 1);
    end;
end.