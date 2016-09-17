{$i const.inc}
var
    n, m, i, j, w: longint;
begin
    n := 2;
    m := 20;
    w := 2;
    writeln(n, ' ', m);
    randseed := 4;
    for j := 1 to 2 do
    begin
        for i := 1 to n do
        begin
            write(random(w) + 1);
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