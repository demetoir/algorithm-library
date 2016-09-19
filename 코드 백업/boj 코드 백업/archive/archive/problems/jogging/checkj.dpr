uses
    testlib, sysutils, math;
const
    maxn = 100;
    eps = 1e-4;
    maxc = 1000000;
    maxpc = 300;
var
    d, x1, y1, x2, y2, v1, v2, xp1, yp1, xp2, yp2, ja, pa, time, xp, yp, xn, yn: extended;
    p, i, op, pc, n: longint;
    a, b, c, ton, toff: array [0..maxn] of extended;
begin
    n := inf.readlongint;
    x1 := inf.readreal;
    y1 := inf.readreal;
    x2 := inf.readreal;
    y2 := inf.readreal;

    v1 := inf.readreal;
    v2 := inf.readreal;

    ton[0] := 0;
    toff[0] := 0;
    for i := 1 to n do
    begin
        xp1 := inf.readreal;
        yp1 := inf.readreal;
        xp2 := inf.readreal;
        yp2 := inf.readreal;
        a[i] := yp1 - yp2;
        b[i] := xp2 - xp1;
        d := hypot(a[i], b[i]);
        a[i] := a[i] / d;
        b[i] := b[i] / d;
        c[i] := a[i] * xp1 + b[i] * yp1;
        ton[i] := inf.readreal;
        toff[i] := inf.readreal;
    end;

    ja := ans.readreal;
    pa := ouf.readreal;
    if pa > ja + eps then
        quit(_wa, 'expected: ' + floattostr(ja) + ', found: ' + floattostr(pa));

    pc := ouf.readlongint;
    if pc > maxpc then
        quit(_wa, 'too many steps');

    xp := x1;
    yp := y1;
    op := 0;
    time := 0;
    for i := 1 to pc do
    begin
        p := ouf.readlongint;

        if (p < 0) or (p > n) then
            quit(_wa, 'invalid path number');

        xn := ouf.readreal;
        yn := ouf.readreal;

        if (abs(xn) > maxc) or (abs(yn) > maxc) then
            quit(_wa, 'going too far...');

        if p = 0 then
        begin
            if p <> op then
                time := time + toff[op];
            time := time + hypot(xp - xn, yp - yn) / v2;
        end else begin
            d := a[p] * xp + b[p] * yp - c[p];
            if abs(d) > eps then
                quit(_wa, 'trying to jog on pathway ' + inttostr(p) + ' from wrong point');
            d := a[p] * xn + b[p] * yn - c[p];
            if abs(d) > eps then
                quit(_wa, 'trying to jog on pathway ' + inttostr(p) + ' towards wrong point');
            if p <> op then 
                time := time + toff[op] + ton[p];
            time := time + hypot(xp - xn, yp - yn) / (v1 + v2);
        end;
        xp := xn;
        yp := yn;
        op := p;
    end;

    if (abs(x2 - xp) > eps) or (abs(y2 - yp) > eps) then
        quit(_wa, 'eddy did not get to work');

    if abs(time - pa) > eps then
        quit(_wa, 'wrong time, promised: ' + floattostr(pa) + ', calculated: ' + floattostr(time));

    if time < ja - eps then
        quit(_fail, 'expected: ' + floattostr(ja) + ', found: ' + floattostr(pa));

    quit(_ok, floattostr(pa));
end.