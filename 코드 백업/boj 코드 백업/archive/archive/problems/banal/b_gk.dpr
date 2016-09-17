{-----------------------------------------------------------}
{ ACM ICPC 2003-2004                                        }
{ Northeastern European Region                              }
{ Northern Subregional Contest                              }
{                                                           }
{ Problem B. Banal Tickets                                  }
{ Author: ???                                               }
{ Solution: Georgiy Korneev                                 }
{-----------------------------------------------------------}
{ Ordinary solution                                         }
{-----------------------------------------------------------}

{$q+,r+,o+}
{$apptype console}

uses
    math;

const
    max_c = 20;
    max_l = 2 * max_c;
    radix = 10;

type
    tlong = array [0..max_l] of longint;
    tcount = array [1..4] of longint;

procedure add(var a, b: tlong);
var
    i, p: longint;
begin
    p := 0;
    for i := 0 to max_l do begin
        p := p div radix + a[i] + b[i];
        a[i] := p mod radix;
    end;
    if p <> 0 then begin
        writeln('Overflow');
        runerror(240);
    end;
end;

procedure sub(var a, b: tlong);
var
    i, p: longint;
begin
    p := 0;
    for i := 0 to max_l do begin
        p := a[i] - b[i] - p;
        if p >= 0 then begin
            a[i] := p;
            p := 0;
        end else begin
            a[i] := p + radix;
            p := 1;
        end;
    end;
end;

procedure mul3(var a, b, c: tlong);
var
    i, j: longint;
    p: longint;
begin
    p := 0;
    for i := 0 to max_l do begin
        p := p div radix;
        for j := 0 to i do begin
            p := p + b[j] * c[i - j];
        end;
        a[i] := p mod radix;
    end;
end;

procedure o(var a: tlong);
var
    f: boolean;
    i: longint;
begin
    f := false;
    for i := max_l downto 1 do begin
        f := f or (a[i] <> 0);
        if f then begin
            write(a[i]);
        end;
    end;
    write(a[0]);
    writeln;
end;

procedure init(var a: tlong; p: int64);
var
    i: longint;
begin
    fillchar(a, sizeof(a), 0);
    i := 0;
    while p <> 0 do begin
        a[i] := p mod radix;
        p := p div radix;
        inc(i);
    end;
end;

procedure mul(var a: tlong; b: int64);
var
    i: longint;
    p: int64;
begin
    p := 0;
    for i := 0 to max_l do begin
        p := p div radix + a[i] * b;
        a[i] := p mod radix;
    end;
end;

var
    c23: array [0..max_c, 0..max_c * 3 + 3, 0..max_c * 2 + 2] of int64;

procedure power(var r: tlong; a, p: longint);
var
    i: longint;
begin
    init(r, 1);
    for i := 1 to p do begin
        mul(r, a);
    end;
end;

const
    _d: array [1..9] of tcount = (
        (0, 0, 0, 0),
        (1, 0, 0, 0),
        (0, 1, 0, 0),
        (2, 0, 0, 0),
        (0, 0, 1, 0),
        (1, 1, 0, 0),
        (0, 0, 0, 1),
        (3, 0, 0, 0),
        (0, 2, 0, 0)
    );
var
    s: string;
    i, j, k, l, n, d: longint;
    c, cl, cr: tcount;
    lz, rz: boolean;
    lf, rf: longint;
    cnk: array [-max_c..max_c, -max_c..max_c] of longint;
    lr, rr, r, sr: tlong;
    tl, tr, rs7, ls7, ls5, rs5: longint;
    qr, ql, zr, zl: longint;
    md: longint;
    mx: int64;
begin
    assign(input, 'banal.in'); reset(input);
    assign(output, 'banal.out'); rewrite(output);

    fillchar(c23, sizeof(c23), 0);

    c23[0][0][0] := 1;
    for l := 0 to max_c - 1 do begin
        for i := 0 to max_c * 3 do begin
            for j := 0 to max_c * 2 do begin
                c23[l + 1][i + 0][j + 0] := c23[l + 1][i + 0][j + 0] + c23[l][i][j];
                c23[l + 1][i + 1][j + 0] := c23[l + 1][i + 1][j + 0] + c23[l][i][j];
                c23[l + 1][i + 0][j + 1] := c23[l + 1][i + 0][j + 1] + c23[l][i][j];
                c23[l + 1][i + 2][j + 0] := c23[l + 1][i + 2][j + 0] + c23[l][i][j];
                c23[l + 1][i + 1][j + 1] := c23[l + 1][i + 1][j + 1] + c23[l][i][j];
                c23[l + 1][i + 3][j + 0] := c23[l + 1][i + 3][j + 0] + c23[l][i][j];
                c23[l + 1][i + 0][j + 2] := c23[l + 1][i + 0][j + 2] + c23[l][i][j];
            end;
        end;
    end;

    while not seekeof do begin
        readln(n);
        readln(s);
        if length(s) <> n * 2 then runerror(239);

        fillchar(c, sizeof(c), 0);
        fillchar(cl, sizeof(cl), 0);
        fillchar(cr, sizeof(cr), 0);

        lz := false;
        lf := 0;
        for i := 1 to length(s) div 2 do begin
            case s[i] of
                '0': lz := true;
                '?': inc(lf);
                else begin
                    d := ord(s[i]) - ord('0');
                    for j := 1 to 4 do begin
                        inc(c[j], _d[d][j]);
                        inc(cl[j], _d[d][j]);
                    end;
                end;
            end;
        end;

        rz := false;
        rf := 0;
        for i := length(s) div 2 + 1 to length(s) do begin
            case s[i] of
                '0': rz := true;
                '?': inc(rf);
                else begin
                    d := ord(s[i]) - ord('0');
                    for j := 1 to 4 do begin
                        dec(c[j], _d[d][j]);
                        inc(cr[j], _d[d][j]);
                    end;
                end;
            end;
        end;

        for i := 0 to max_c do begin
            cnk[i][0] := 1;
            for j := 1 to i do begin
                cnk[i][j] := cnk[i - 1][j] + cnk[i - 1][j - 1];
            end;
        end;

        power(lr, 10, lf);
        power(rr, 10, rf);

        if not lz and (lf <> 0) then begin
            power(r, 9, lf);
            sub(lr, r);
        end;
        if not rz and (rf <> 0) then begin
            power(r, 9, rf);
            sub(rr, r);
        end;

        if not rz and (rf = 0) then begin
            init(rr, 0);
        end;

        if not lz and (lf = 0) then begin
            init(lr, 0);
        end;

        //write('lr='); o(lr);
        //write('rr='); o(rr);
        mul3(sr, lr, rr);
        //write('sr='); o(sr);

        mx := 0;
        if not (lz or rz) then begin
            for ls7 := 0 to lf do begin
                rs7 := ls7 + c[4];
                if (rs7 < 0) or (rs7 > rf) then continue;
                for ls5 := 0 to lf - ls7 do begin
                    rs5 := ls5 + c[3];
                    if (rs5 < 0) or (rs7 + rs5 > rf) then continue;

                    ql := cnk[lf - ls7][ls5] * cnk[lf][ls7];
                    qr := cnk[rf - rs7][rs5] * cnk[rf][rs7];
                    for k := 0 to 3 * (lf - ls5 - ls7) do begin
                        for l := 0 to 2 * (lf - ls5 - ls7) do begin
                            if
                                (k + c[1] >= 0) and (l + c[2] >= 0) and
                                (c23[lf - ls7 - ls5][k][l] <> 0) and
                                (c23[rf - rs7 - rs5][k + c[1]][l + c[2]] <> 0)
                            then begin
                                init(r, c23[lf - ls7 - ls5][k][l]);
                                mul(r, c23[rf - rs7 - rs5][k + c[1]][l + c[2]]);
                                mul(r, ql);
                                mul(r, qr);
                                add(sr, r);
                                if mx < c23[lf - ls7 - ls5][k][l] then begin
                                    mx := c23[lf - ls7 - ls5][k][l];
                                end;
                                if mx < c23[rf - rs7 - rs5][k + c[1]][l + c[2]] then begin
                                    mx := c23[rf - rs7 - rs5][k + c[1]][l + c[2]];
                                end;
                            end;
                        end;
                    end;
                end;
            end;
            //writeln(mx);
        end;
        //writeln(c[1], ' ', c[2], ' ', c[3], ' ', c[4]);
        power(rr, 10, rf + lf);
        sub(rr, sr);

        o(sr);
        o(rr);
        writeln;
    end;

    close(input);
    close(output);
end.