const
    maxn = 500;

var
    pair: array [0..maxn, 0..maxn] of longint;
    c: array [0..maxn, 0..maxn] of longint;
    f: array [0..maxn, 0..maxn] of longint;

    a, b: array [1..maxn] of longint;

    i, j, k, l, n, m: longint;

procedure outp(x, y: longint);
begin
    if (x = 0) or (y = 0) then 
        exit;

    case f[x][y] of
        -1: outp(x - 1, y);
        -2: outp(x, y - 1);
        else
            outp(f[x][y], pair[f[x][y]][y - 1]);
            if a[x] <> b[y] then
                runerror(240);
            write(a[x], ' ');
    end;
end;

begin
    assign(input, 'gcis.in');
    reset(input);
    assign(output, 'gcis.out');
    rewrite(output);

    read(n);
    for i := 1 to n do
        read(a[i]);
    read(m);
    for i := 1 to m do
        read(b[i]);

    for i := 1 to n do
    begin
        pair[i][0] := 0;
        for j := 1 to m do
        begin
            if a[i] = b[j] then
                pair[i][j] := j
            else
                pair[i][j] := pair[i][j - 1];
        end;
    end;

    for i := 1 to n do
        for j := 1 to m do
        begin
            if a[i] = b[j] then 
            begin
                if c[i][j] = 0 then
                begin
                    c[i][j] := 1;
                    f[i][j] := 0;
                end;

                for k := 1 to i - 1 do
                    if (a[k] < a[i]) and (pair[k][j - 1] > 0) then
                    begin
                        if c[k][pair[k][j - 1]] + 1 > c[i][j] then
                        begin
                            c[i][j] := c[k][pair[k][j - 1]] + 1;
                            f[i][j] := k;
                        end;
                    end;
            end;
        end;

    k := 0;
    l := 0;
    for i := 1 to n do
        for j := 1 to m do
            if c[i][j] > c[k][l] then
            begin
                k := i;
                l := j;
            end;

    writeln(c[k][l]);
    outp(k, l);
    writeln;

    close(input);
    close(output);
end.