{$q+,r+,o-}
{$MINSTACKSIZE 10000000}
{$APPTYPE CONSOLE}

const
    maxn = 18;

procedure fatal(s: string);
begin
    writeln(s);
    runerror(239);
end;

const
    maxd = 10;
    base = 10000;
    bl = 4;

type
    tarr = array [0..3 * maxn, 0..2 * maxn, 0..maxn, 0..maxn] of int64;
    tlong = array [1..maxd] of longint;

var
    n: longint;
    c: array [-1..maxn, -1..maxn] of int64;
    cnt: array [0..maxn, 0..3 * maxn, 0..2 * maxn] of int64;

function pow(x: int64; b: longint): int64;
var
    r: int64;
begin
    r := 1;
    while b > 0 do
    begin   
        r := r * x;
        dec(b);
    end;
    pow := r;
end;

procedure solve(const s: string; var a: tarr; var q: longint; var zn: int64);
var
    b: array [0..3] of longint;
    i, j, k, l, p: longint;
    z: boolean;
begin
    q := 0;
    fillchar(b, sizeof(b), 0);
    z := false;
    for p := 1 to n do
    begin
        case s[p] of
            '?': inc(q);
            '0': z := true;
            '2': inc(b[0]);
            '3': inc(b[1]);
            '4': inc(b[0], 2);
            '5': inc(b[2]);
            '6': begin inc(b[0]); inc(b[1]); end;
            '7': inc(b[3]);
            '8': inc(b[0], 3);
            '9': inc(b[1], 2);
        end;
    end;

    if z then
    begin
        zn := pow(10, q)
    end else begin
        zn := pow(10, q) - pow(9, q);

        for i := 0 to q do
            for j := 0 to (q - i) do
                for k := 0 to 3 * (q - i - j) do
                    for l := 0 to 2 * (q - i - j) do
                    begin
                        a[b[0] + k][b[1] + l][b[2] + i][b[3] + j] := 
                            c[q][i + j] * c[i + j][i] * cnt[q - i - j][k][l];
    {                    writeln(b[0] + k, ' ', b[1] + l, ' ', b[2] + i, ' ', b[3] + j, ': ',
                            a[b[0] + k][b[1] + l][b[2] + i][b[3] + j]);}
                    end;
    end;
end;

procedure init(var t: tlong; x: int64);
var
    i: longint;
begin
    fillchar(t, sizeof(t), 0);
    i := 1;
    while x > 0 do
    begin
        t[i] := x mod base;
        x := x div base;
        inc(i);
    end;
end;

procedure mul(const x, y: tlong; var z: tlong);
var
    i, j: longint;
begin
    fillchar(z, sizeof(z), 0);
    for i := 1 to maxd do
        for j := 1 to maxd - i + 1 do
        begin
            z[i + j - 1] := z[i + j - 1] + x[i] * y[j];
        end;
    for i := 1 to maxd - 1 do
    begin
        z[i + 1] := z[i + 1] + z[i] div base;
        z[i] := z[i] mod base;
    end;
end;

procedure add(var x: tlong; const y: tlong);
var
    i, c: longint;
begin
    c := 0;
    for i := 1 to maxd do
    begin   
        c := c + x[i] + y[i];
        x[i] := c mod base;
        c := c div base;
    end;
end;

procedure sub(var x: tlong; const y: tlong);
var
    i, c: longint;
begin
    c := 0;
    for i := 1 to maxd do
    begin   
        c := c + x[i] - y[i];
        if c < 0 then
        begin
            c := c + base;
            dec(x[i + 1]);
        end;
        x[i] := c mod base;
        c := c div base;
    end;
end;

procedure print(const x: tlong);
var
    i, j, k: longint;
begin
    i := maxd;
    while (i > 1) and (x[i] = 0) do
        dec(i);
    write(x[i]);
    dec(i);
    while i > 0 do
    begin
        j := base;
        k := x[i];
        while j > 1 do
        begin
            j := j div 10;
            write(k div j);
            k := k mod j;
        end;
        dec(i);
    end;
end;

var
    p, i, j, k, l: longint;
    s: string;
    lft, rgt: tarr;
    zl, zr: int64;
    lq, rq: longint;
    t1, t2, tmp: tlong;
    answer: tlong;

begin
    assign(input, 'banal.in');
    reset(input);
    assign(output, 'banal.out');
    rewrite(output);

    readln(n);
    if (n < 1) or (n > maxn) then
        fatal('invalid n');
    readln(s);

    if length(s) <> 2 * n then
        fatal('invalid pattern length');

    for i := 1 to 2 * n do
        if not (s[i] in ['0'..'9', '?']) then
            fatal('invalid character in pattern');

    cnt[0][0][0] := 1;
    for p := 1 to n do
    begin
        for i := 0 to 3 * n do
            for j := 0 to 2 * n do
            begin
                cnt[p][i][j] := cnt[p-1][i][j];
                if i > 0 then
                    cnt[p][i][j] := cnt[p][i][j] + cnt[p-1][i-1][j];
                if i > 1 then
                    cnt[p][i][j] := cnt[p][i][j] + cnt[p-1][i-2][j];
                if i > 2 then
                    cnt[p][i][j] := cnt[p][i][j] + cnt[p-1][i-3][j];
                if j > 0 then
                    cnt[p][i][j] := cnt[p][i][j] + cnt[p-1][i][j-1];
                if j > 1 then
                    cnt[p][i][j] := cnt[p][i][j] + cnt[p-1][i][j-2];
                if (i > 0) and (j > 0) then
                    cnt[p][i][j] := cnt[p][i][j] + cnt[p-1][i-1][j-1];
            end;
    end;

    c[-1][-1] := 1;
    for i := 0 to n do
        for j := 0 to n do
            c[i][j] := c[i - 1][j] + c[i - 1][j - 1];

    solve(copy(s, 1, n), lft, lq, zl);
    solve(copy(s, n + 1, n), rgt, rq, zr);

    init(answer, 0);
    for k := 0 to n do
        for l := 0 to n - k do
            for i := 0 to 3 * (n - k - l) do
                for j := 0 to 2 * (n - k - l) do
                begin
                    init(t1, lft[i][j][k][l]);
                    init(t2, rgt[i][j][k][l]);
                    mul(t1, t2, tmp);
                    add(answer, tmp);
                end;
    init(t1, zl);
    init(t2, zr);
    mul(t1, t2, tmp);
    add(answer, tmp);
    print(answer);
    writeln;
    init(t1, pow(10, lq));
    init(t2, pow(10, rq));
    mul(t1, t2, tmp);
    sub(tmp, answer);
    print(tmp);

    close(input);
    close(output);
end.