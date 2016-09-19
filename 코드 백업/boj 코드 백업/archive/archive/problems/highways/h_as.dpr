const
    maxn = 50000;
var
    a: array [1..maxn] of longint;
    i, j, n: longint;
begin
    assign(input, 'highways.in');
    reset(input);
    assign(output, 'highways.out');
    rewrite(output);

    read(n);
    if (n < 1) or (n > maxn) then
        runerror(239);

    a[1] := 0;
    for i := 2 to n do
    begin
        read(a[i]);
        if a[i] <= a[i - 1] then runerror(239);
    end;
    for i := 1 to n do
        if (a[i] < 0) or (a[i] > 1000000000) then runerror(239);

    if n <= 3 then
    begin
        writeln(0)
    end else begin
        j := 3;
        for i := 4 to n - 1 do
            if a[i] - a[i - 1] < a[j] - a[j - 1] then
                j := i;
        writeln(a[n] - a[1] + a[j] - a[j - 1]);
        writeln(n, ' ', j - 1);
        writeln(j, ' ', 1);
    end;

    close(input);
    close(output);
end.