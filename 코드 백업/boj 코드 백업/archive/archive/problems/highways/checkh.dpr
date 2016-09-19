uses
    testlib, sysutils;

const
    maxn = 100000;

var
    ja, pa, pc: longint;
    a: array [1..maxn] of longint;
    p: array [1..4] of longint;
    i, j, n: longint;

begin
    ja := ans.readlongint;
    pa := ouf.readlongint;

    if pa = 0 then
    begin
        if ja = 0 then
            quit(_ok, '0')
        else
            quit(_wa, '0 unexpected');
    end;

    if (ja <> 0) and (pa > ja) then
        quit(_wa, 'wrong length, expected: ' + inttostr(ja) + ', found: ' + inttostr(pa));

    n := inf.readlongint;
    a[1] := 0;
    for i := 2 to n do
        a[i] := inf.readlongint;

    for i := 1 to 4 do
    begin
        p[i] := ouf.readlongint;
        if (p[i] < 1) or (p[i] > n) then
            quit(_wa, 'invalid city number ' + inttostr(p[i]));
    end;

    for i := 1 to 3 do
        for j := i + 1 to 4 do
            if p[i] = p[j] then
            begin
                quit(_wa, 'city ' + inttostr(p[i]) + ' is incident to more than one new highway');
            end;

    if (p[2] <> 1) and (p[4] <> 1) then
        quit(_wa, 'cannot get to the city 1');
    if (p[1] <> n) and (p[3] <> n) then
        quit(_wa, 'cannot travel from the city n');


    if abs(p[4] - p[3]) + abs(p[2] - p[1]) < n - 1 then
        quit(_wa, 'not all cities are served by the highways');

    pc := abs(a[p[2]] - a[p[1]]) + abs(a[p[4]] - a[p[3]]);
    if pc <> pa then
        quit(_wa, 'summary length wrong, promised: ' + inttostr(pa) + ', calculated: ' + inttostr(ja));

    if ja = 0 then
        quit(_fail, '"0" expected, solution found');
    if pa < ja then
        quit(_fail, 'better then jury, expected: ' + inttostr(ja) + ', found: ' + inttostr(pa));

    quit(_ok, inttostr(pa));
end.