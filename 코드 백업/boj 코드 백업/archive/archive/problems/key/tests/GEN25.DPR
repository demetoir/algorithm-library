{ Chessboard style inserts, there and back }

var
    i: longint;
    n, m: longint;
    p, sz, pieces, j: longint;
begin
    n := 65536;
    m := 65536;

    writeln(n, ' ', m);
    n := n div 4;
    for j := 1 to 2 do
    begin
        for i := n downto 1 do
        begin
            write(2 * i - j mod 2);
            write(' ')
        end;
        for i := 1 to n do
        begin
            write(2 * i - (j + 1) mod 2);
            if (j < 2) or (i < n) then
                write(' ')
            else
                writeln;
        end;
    end;
end.