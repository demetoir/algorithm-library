{$i const.inc}
var
    n, m, i, j, w: longint;
begin
    n := 10;
    m := 15;
    w := 1000;
    writeln(n, ' ', m);
    randseed := 3;
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