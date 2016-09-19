{$i const.inc}
var
    n, m: longint;
    i, j: longint;
    vp, vr: array [1..maxn] of longint;
    ep: array [1..maxm] of longint;
    w: array [1..2, 1..maxn] of longint;
    e: array [1..maxm] of record a, b: longint; end;
begin   
    read(n);
    read(m);
    randseed := n + m;
    for j := 1 to 2 do
        for i := 1 to n do
        begin
            read(w[j][i]);
        end;

    for i := 1 to m do
    begin
        read(e[i].a, e[i].b);
    end;

    for i := 1 to n do
    begin
        repeat
            j := random(n) + 1;
        until vp[j] = 0;
        vp[j] := i;
        vr[i] := j;
    end;

    for i := 1 to m do
    begin
        repeat
            j := random(m) + 1;
        until ep[j] = 0;
        ep[j] := i;
    end;

    writeln(n, ' ', m);
    for j := 1 to 2 do
        for i := 1 to n do
        begin
            write(w[j][vp[i]]);
            if i < n then
                write(' ')
            else
                writeln;
        end;

    for i := 1 to m do
    begin
        writeln(vr[e[ep[i]].a], ' ', vr[e[ep[i]].b]);
    end;
end.