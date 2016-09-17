{$i const.inc}
var
    n, m, i, j, k: longint;
begin
    n := 85;
    m := n * (n - 1) div 2;
    if m > maxm then
        m := maxm;
    writeln(n, ' ', m);
    for i := 1 to n do
    begin
        if i < n div 2 then
            write(1)
        else
            write(100);
        if i < n then
            write(' ')
        else
            writeln;
    end;

    for i := 1 to n do
    begin
        write(10);
        if i < n then
            write(' ')
        else
            writeln;
    end;

    k := 0;
    for i := 1 to n do
    begin
        for j := 1 to i do
        begin
            inc(k);
            writeln(i, ' ', j);
            if k = m then
                break;
        end;
        if k = m then 
            break;
    end;
end.