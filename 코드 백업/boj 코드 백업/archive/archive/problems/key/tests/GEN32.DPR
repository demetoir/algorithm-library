{ Many merges, inserting into the head of the block }

var
    i: longint;
    n, m: longint;
    p, sz, pieces, j: longint;
begin
    n := 65536;
    m := 65536;
    sz := 256;

{    n := 20;
    m := 20;
    sz := 4;}


    pieces := n div (sz + 2);
    n := pieces * sz + 2 * (pieces - 1);
    writeln(n, ' ', m);
    p := 0;
    for i := 1 to pieces do
    begin
        for j := 1 to sz do
        begin
            write(p + 1);
            if (i < pieces) or (j < sz) then
                write(' ');
        end;
        p := p + sz;
        if i = 1 then
            p := p + 1
        else
            p := p + 2;
    end;

    p := 1;
    for i := pieces - 1 downto 1 do
    begin
        write(' ', p + (sz + 2) * (i - 1) + sz);
        write(' ', p + (sz + 2) * (i - 1) + sz);
    end;
    writeln;
end.