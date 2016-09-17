{ Chessboard style inserts, reverse order }

var
    i: longint;
    n, m: longint;
    p, sz, pieces, j: longint;
begin
    n := 65536;
    m := 65536;

    writeln(n, ' ', m);
    n := n div 4;
    for j := 1 to 4 do
    begin
        for i := n downto 1 do
        begin
            write(2 * i - j mod 2);
            if (j < 4) or (i > 1) then
                write(' ')
            else
                writeln;
        end;
    end;
end.