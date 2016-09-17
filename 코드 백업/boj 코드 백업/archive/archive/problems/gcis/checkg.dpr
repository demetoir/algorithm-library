uses
    sysutils, testlib;
var
    n, m, ja, pa, i, ai, bi: longint;
    a, b, c: array [1..500] of longint;
begin
    n := inf.readlongint;
    for i := 1 to n do
        a[i] := inf.readlongint;
    m := inf.readlongint;
    for i := 1 to m do
        b[i] := inf.readlongint;

    ja := ans.readlongint;
    pa := ouf.readlongint;

    if pa < ja then
        quit(_wa, 'expected: ' + inttostr(ja) + ', found: ' + inttostr(pa));

    for i := 1 to pa do
        c[i] := ouf.readlongint;

    for i := 2 to pa do
        if c[i - 1] >= c[i] then
            quit(_wa, 'not increasing');

    ai := 0;
    bi := 0;
    for i := 1 to pa do
    begin
        inc(ai);
        inc(bi);
        while (ai <= n) and (a[ai] <> c[i]) do inc(ai);
        while (bi <= m) and (b[bi] <> c[i]) do inc(bi);
        if (ai > n) or (a[ai] <> c[i]) then
            quit(_wa, 'not subsequence of the first sequence');
        if (bi > m) or (b[bi] <> c[i]) then
            quit(_wa, 'not subsequence of the second sequence');
    end;

    if ja > pa then
        quit(_fail, 'better then jury');

    quit(_ok, '');
end.