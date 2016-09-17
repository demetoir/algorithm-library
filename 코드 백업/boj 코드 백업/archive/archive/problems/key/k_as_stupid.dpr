const
    maxn = 100000;
    maxm = 100000;

var 
    n, m, i, j, k: longint;
    a: array [1..maxn + maxm] of longint;

procedure insert(x, y: longint);
begin
    if y = 0 then exit;
    insert(x + 1, a[x]);
    a[x] := y;
end;

begin
    assign(input, 'key.in');
    reset(input);
    assign(output, 'key.out');
    rewrite(output);

    read(n, m);
    if (n > maxn) or (m > maxm) then
        runerror(239);

    for i := 1 to n do
    begin
        read(j);
        if j > m then
            runerror(239);
        insert(j, i);
    end;

    j := n + m;
    while a[j] = 0 do
        dec(j);
    writeln(j);
    for i := 1 to j do
        write(a[i], ' ');
    writeln;

    close(input);
    close(output);
end.