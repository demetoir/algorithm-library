{$o-,q+,r+}
{ $o+,q-,r-}
{$apptype console}
uses
    math;

const
    maxn = 100;
    maxp = maxn + 4;

    maxc = 10000.0;

    eps = 1e-7;

procedure checkin(x, l, r: extended);
begin
    if (x < l) or (x > r) then
        runerror(239);
end;

procedure project(x0, y0, a, b, c: extended; var xc, yc: extended);
var
    d, c0: extended;
begin
    d := a * a + b * b;
    c0 := - b * x0 + a * y0;
    xc := (c * a - c0 * b) / d;
    yc := (a * c0 + b * c) / d;
end;

var
    x, y, d: array [1..maxp, 1..maxp] of extended;
    valid, u: array [1..maxp, 1..maxp] of boolean;
    from: array [1..maxp, 1..maxp] of record i, j, p: integer; end;
    a, b, c: array [1..maxn] of extended;
    t, speed: array [1..maxp] of extended;
    n: longint;
    t1, t2, v1, v2, xc, yc, dd, alpha, cf, x1, y1, x2, y2: extended;
    bi, bj, i, j: longint;
    best, ttime: extended;
    pathlen: longint;
    path: array [1..maxn * 3] of record p: longint; x, y: extended; end;

procedure createpath(i, j: longint);
var
    ni, nj, p: longint;
begin
    ni := from[i][j].i;
    nj := from[i][j].j;
    if (ni = 0) and (nj = 0) then exit;
    p := from[i][j].p;

    if p > n then p := 0;
    createpath(ni, nj);
    if hypot(x[i][j] - x[ni][nj], y[i][j] - y[ni][nj]) > eps then
    begin
        inc(pathlen);
        path[pathlen].p := p;
        path[pathlen].x := x[i][j];
        path[pathlen].y := y[i][j];
    end;
end;

begin
    assign(input, 'jogging.in');
    reset(input);
    assign(output, 'jogging.out');
    rewrite(output);

    read(n);
    if (n < 0) or (n > maxn) then
        runerror(239);

    read(x[n+1][n+1], y[n+1][n+1], x[n+3][n+3], y[n+3][n+3]);
    checkin(x[n+1][n+1], -maxc, maxc);
    checkin(y[n+1][n+1], -maxc, maxc);
    checkin(x[n+3][n+3], -maxc, maxc);
    checkin(y[n+3][n+3], -maxc, maxc);

    for i := 1 to 2 do
        for j := 1 to 2 do
        begin
            x[n + i][n + j] := x[n + 1][n + 1];
            y[n + i][n + j] := y[n + 1][n + 1];
            valid[n + i][n + j] := true;
        end;

    for i := 3 to 4 do
        for j := 3 to 4 do
        begin
            x[n + i][n + j] := x[n + 3][n + 3];
            y[n + i][n + j] := y[n + 3][n + 3];
            valid[n + i][n + j] := true;
        end;

    read(v1, v2);
    checkin(v1, 1, 100);
    checkin(v2, 1, 100);

    alpha := arccos(v2 / (v1 + v2));
    cf := 1 / tan(alpha);

    for i := 1 to n do
    begin
        read(x1, y1, x2, y2);
        checkin(x1, -maxc, maxc);
        checkin(x2, -maxc, maxc);
        checkin(y1, -maxc, maxc);
        checkin(y2, -maxc, maxc);

        if abs(x2 - x1) + abs(y2 - y1) < 1e-2 then
            runerror(239);

        a[i] := y1 - y2;
        b[i] := x2 - x1;
        c[i] := a[i] * x1 + b[i] * y1;
        dd := hypot(a[i], b[i]);
        a[i] := a[i] / dd;
        b[i] := b[i] / dd;
        c[i] := c[i] / dd;

        if abs(a[i] * x[n+1][n+1] + b[i] * y[n+1][n+1] - c[i]) < eps then
            runerror(239);
        if abs(a[i] * x[n+3][n+3] + b[i] * y[n+3][n+3] - c[i]) < eps then
            runerror(239);

        project(x[n+1][n+1], y[n+1][n+1], a[i], b[i], c[i], xc, yc);
        dd := hypot(x[n+1][n+1] - xc, y[n+1][n+1] - yc) * cf;
        x[n+1][i] := xc + b[i] * dd;
        y[n+1][i] := yc - a[i] * dd;
        x[n+2][i] := xc - b[i] * dd;
        y[n+2][i] := yc + a[i] * dd;

{        writeln('geton point for ', i, ': ', x[n+1][i] :0 :6, ' ', y[n+1][i] :0 :6);
        writeln('geton point for ', i, ': ', x[n+2][i] :0 :6, ' ', y[n+2][i] :0 :6);}

        project(x[n+3][n+3], y[n+3][n+3], a[i], b[i], c[i], xc, yc);
        dd := hypot(x[n+3][n+3] - xc, y[n+3][n+3] - yc) * cf;
        x[n+3][i] := xc + b[i] * dd;
        y[n+3][i] := yc - a[i] * dd;
        x[n+4][i] := xc - b[i] * dd;
        y[n+4][i] := yc + a[i] * dd;
{        writeln('getoff point for ', i, ': ', x[n+3][i] :0 :6, ' ', y[n+3][i] :0 :6);
        writeln('getoff point for ', i, ': ', x[n+4][i] :0 :6, ' ', y[n+4][i] :0 :6);}

        valid[n+1][i] := true;
        valid[n+2][i] := true;
        valid[n+3][i] := true;
        valid[n+4][i] := true;

        read(t1, t2);
        checkin(t1, 0, 10);
        checkin(t2, 0, 10);
        t[i] := t1 + t2;

        speed[i] := v1 + v2;
    end;

    for i := 1 to n do
        for j := 1 to 4 do
        begin
            x[i][n + j] := x[n + j][i];
            y[i][n + j] := y[n + j][i];
            valid[i][n + j] := true;
        end;

    speed[n+1] := v2;
    speed[n+2] := v2;
    speed[n+3] := v2;
    speed[n+4] := v2;

    for i := 1 to n do
        for j := i + 1 to n do
            if (abs(a[i] * b[j] - a[j] * b[i]) < eps) and
               (abs(a[i] * c[j] - a[j] * c[i]) < eps) and
               (abs(b[i] * c[j] - b[j] * c[i]) < eps) then
                runerror(239);

    for i := 1 to n do
    begin
        for j := 1 to n do
            if i <> j then
            begin
                dd := a[i] * b[j] - a[j] * b[i];

                if abs(dd) < eps then
                begin
                    valid[i][j] := false;
                end else begin
                    valid[i][j] := true;
                    x[i][j] := (c[i] * b[j] - c[j] * b[i]) / dd;
                    y[i][j] := (a[i] * c[j] - a[j] * c[i]) / dd;
                    if (abs(x[i][j]) > 1e20) or (abs(y[i][j]) > 1e20) then
                        runerror(239);
                end;
            end;
    end;

    for i := 1 to n + 4 do
        for j := 1 to n + 4 do
            d[i][j] := -1;

    fillchar(u, sizeof(u), 0);
    d[n+1][n+1] := 0;
    d[n+3][n+3] := hypot(x[n+3][n+3] - x[n+1][n+1], y[n+3][n+3] - y[n+1][n+1]) / v2;
    from[n+3][n+3].i := n+1;
    from[n+3][n+3].j := n+1;
    from[n+3][n+3].p := n+1;
    while true do
    begin
        best := -1;
        bi := 0;
        bj := 0;
        for i := 1 to n + 4 do
            for j := 1 to n + 4 do
                if valid[i][j] and not u[i][j] and (d[i][j] > -eps) and ((best < -eps) or (d[i][j] < best)) then
                begin
                    bi := i;
                    bj := j;
                    best := d[i][j];
                end;

        if best < -eps then break;

{        writeln(bi, ' ', bj, ' ', x[bi][bj] :0 :6, ' ', y[bi][bj] :0 :6, ' - ', d[bi][bj] :0 :6);}

        u[bi][bj] := true;
        for j := 1 to n + 4 do
            if valid[bi][j] then
            begin
                ttime := d[bi][bj] + t[bi] + hypot(x[bi][bj] - x[bi][j], y[bi][bj] - y[bi][j]) / speed[bi];
                if (d[bi][j] < 0) or (ttime < d[bi][j]) then
                begin
                    d[bi][j] := ttime;
                    from[bi][j].i := bi;
                    from[bi][j].j := bj;
                    from[bi][j].p := bi;
                    d[j][bi] := ttime;
                    from[j][bi].i := bi;
                    from[j][bi].j := bj;
                    from[j][bi].p := bi;
                end;
            end;
        u[bj][bi] := true;
        for i := 1 to n + 4 do
            if valid[bj][i] then
            begin
                ttime := d[bi][bj] + t[bj] + hypot(x[bj][bi] - x[bj][i], y[bj][bi] - y[bj][i]) / speed[bj];
                if (d[bj][i] < 0) or (ttime < d[bj][i]) then
                begin
                    d[bj][i] := ttime;
                    from[bj][i].i := bi;
                    from[bj][i].j := bj;
                    from[bj][i].p := bj;
                    d[i][bj] := ttime;
                    from[i][bj].i := bi;
                    from[i][bj].j := bj;
                    from[i][bj].p := bj;
                end;
            end;
    end;

    if not u[n+3][n+3] then
        runerror(239);

    writeln(d[n+3][n+3] :0 :6);
    pathlen := 0;
    createpath(n+3, n+3);
    writeln(pathlen);
    for i := 1 to pathlen do
    begin
        writeln(path[i].p, ' ', path[i].x :0 :6, ' ', path[i].y :0 :6);
    end;

    close(input);
    close(output);
end.