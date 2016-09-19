{ Chessboard style inserts }

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
        for i := 1 to n do
        begin
            write(2 * i - j mod 2);
            if (j < 4) or (i < n) then
                write(' ')
            else
                writeln;
        end;
    end;
end.