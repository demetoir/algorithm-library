{-----------------------------------------------------------}
{ ACM ICPC 2003-2004                                        }
{ Northeastern European Region                              }
{ Northern Subregional Contest                              }
{                                                           }
{ Problem J. Jogging                                        }
{ Author: ???                                               }
{ Solution: Georgiy Korneev                                 }
{-----------------------------------------------------------}

{$q+,r+,o-}
{$apptype console}
const
    max_n = 100;
    eps = 1e-10;
    inf = 1e100;

function dist(x1, y1, x2, y2: double): double;
begin
    dist := sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
end;

var
    i, j, n: longint;
    x1, y1, x2, y2, v1, v2, v: double;
    a, b, c: array [1..max_n] of double;
    t1, t2: array [1..max_n] of double;
    tx1, ty1, tx2, ty2: double;
    x, y: array [1..max_n + 4, 1..max_n + 4] of double;
    z: array [1..max_n, 1..max_n + 4] of double;
    u: array [1..max_n, 1..max_n] of boolean;
    d, l, dl: double;
    m: double;
    mi, mj: longint;
begin
    assign(input, 'jogging.in'); reset(input);
    assign(output, 'jogging.out'); rewrite(output);

    read(n);
    read(x1, y1, x2, y2, v2, v1);
    v := (v1 + v2) / v1;

    for i := 1 to n do begin
        read(tx1, ty1, tx2, ty2, t1[i], t2[i]);
        a[i] := ty1 - ty2;
        b[i] := tx2 - tx1;
        c[i] := sqrt(a[i] * a[i] + b[i] * b[i]);
        a[i] := a[i] / c[i];
        b[i] := b[i] / c[i];
        c[i] := a[i] * tx1 + b[i] * ty1;
    end;

    for i := 1 to n do begin
        for j := 1 to n do begin
            d := a[i] * b[j] - a[j] * b[i];
            if abs(d) > eps then begin
                x[i][j] := (c[i] * b[j] - a[j] * c[i]) / d;
                y[i][j] := (a[i] * c[j] - c[j] * b[i]) / d;
                u[i][j] := true;
                z[i][j] := inf;
            end else begin
                u[i][j] := false;
            end;
        end;
        l := b[i] * x1 - a[i] * y1;
        dl := (a[i] * x1 + b[i] * y1 - c[i]) / sqrt(v * v - 1);
        x[i][n + 1] := a[i] * c[i] + b[i] * (l + dl);
        y[i][n + 1] := b[i] * c[i] - a[i] * (l + dl);
        u[i][n + 1] := true;
        z[i][n + 1] := dist(x1, y1, x[i][n + 1], y[i][n + 1]) / v1;

        x[i][n + 2] := a[i] * c[i] + b[i] * (l - dl);
        y[i][n + 2] := b[i] * c[i] - a[i] * (l - dl);
        u[i][n + 2] := true;
        z[i][n + 2] := dist(x1, y1, x[i][n + 2], y[i][n + 2]) / v1;

        l := b[i] * x2 - a[i] * y2;
        dl := (a[i] * x2 + b[i] * y2 - c[i]) / sqrt(v * v - 1);
        x[i][n + 3] := a[i] * c[i] + b[i] * (l + dl);
        y[i][n + 3] := b[i] * c[i] - a[i] * (l + dl);
        u[i][n + 3] := true;
        z[i][n + 3] := inf;

        x[i][n + 4] := a[i] * c[i] + b[i] * (l - dl);
        y[i][n + 4] := b[i] * c[i] - a[i] * (l - dl);
        u[i][n + 4] := true;
        z[i][n + 4] := inf;
    end;

    while true do begin
        m := inf;
        mi := 0;
        mj := 0;
        for i := 1 to n do begin
            for j := 1 to n + 4 do begin
                if u[i][j] and (m > z[i][j]) then begin
                    m := z[i][j];
                    mi := i;
                    mj := j;
                end;
            end;
        end;

        if m > inf / 2 then begin
            break;
        end;

        u[mi][mj] := false;
        for j := 1 to n + 4 do begin
            if u[mi][j] and (z[mi][j] > z[mi][mj] + dist(x[mi][mj], y[mi][mj], x[mi][j], y[mi][j]) / (v1 + v2)) then begin
                z[mi][j] := z[mi][mj] + dist(x[mi][mj], y[mi][mj], x[mi][j], y[mi][j]) / (v1 + v2);
                if z[j][mi] > z[mi][j] + t2[mi] + t1[j] then begin
                    z[j][mi] := z[mi][j] + t2[mi] + t1[j];
                end;
            end;
        end;
    end;

    m := dist(x1, y1, x2, y2) / v1;
    for i := 1 to n do begin
        if m > z[i][n + 3] + dist(x2, y2, x[i][n + 3], y[i][n + 3]) / v1 then begin
            m := z[i][n + 3] + dist(x2, y2, x[i][n + 3], y[i][n + 3]) / v1;
        end;
        if m > z[i][n + 4] + dist(x2, y2, x[i][n + 4], y[i][n + 4]) / v1 then begin
            m := z[i][n + 4] + dist(x2, y2, x[i][n + 4], y[i][n + 4]) / v1;
        end;
    end;

    writeln(m:10:3);
    close(input);
    close(output);
end.