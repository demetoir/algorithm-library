uses
    sysutils, testlib;
const
    maxn = 200;
var
    i, j, k, n, m: longint;
    ja, pa, pn, cost: longint;
    w, v: array [1..maxn] of longint;
    wi, wo: array [1..maxn] of boolean;
    s: string;
begin
    n := inf.readlongint;
    m := inf.readlongint;
    for i := 1 to n do
    begin
        w[i] := inf.readlongint;
    end;
    for i := 1 to n do
    begin
        v[i] := inf.readlongint;
    end;

    ja := ans.readlongint;
    pa := ouf.readlongint;

    pn := ouf.readlongint;

    cost := 0;
    for i := 1 to pn do
    begin
        j := ouf.readlongint;
        if (j < 1) or (j > n) then
            quit(_wa, 'invalid vertex number ' + inttostr(j));
        s := ouf.readword(blanks, blanks);
        if s = '+' then
        begin
            cost := cost + w[j];
            wi[j] := true;
        end 
        else if s = '-' then begin  
            cost := cost + v[j];
            wo[j] := true;
        end else begin
            quit(_pe, '"+" or "-" expected');
        end;
    end;

    if cost <> pa then
        quit(_wa, 'wrong cost, promised: ' + inttostr(pa) + ', calculated: ' + inttostr(cost));

    for i := 1 to m do
    begin
         j := inf.readlongint;
         k := inf.readlongint;

         if (not wo[j]) and (not wi[k]) then
            quit(_wa, 'arc (' + inttostr(j) + '->' + inttostr(k) + ') not destroyed');
    end;

    if pa > ja then
        quit(_wa, 'expected: ' + inttostr(ja) + ', found: ' + inttostr(pa));

    if pa < ja then
        quit(_fail, 'expected: ' + inttostr(ja) + ', found: ' + inttostr(pa));

    quit(_ok, '');
end.