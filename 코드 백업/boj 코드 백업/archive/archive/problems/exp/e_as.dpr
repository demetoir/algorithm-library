{ $O-,Q+,R+,S+}
{$O+,Q-,R-,S-}
{$APPTYPE CONSOLE}
uses
    math;

const
    maxk = 30;
    maxm = 24;
    maxs = 10000;
    base = 1000000000;
    maxd = 100;

type
    tarr = array [1..maxk] of longint;
    tlong = record
        d: longint;
        a: array [1..maxd] of longint;
    end;

var
    b: tarr;
    a: array [1..maxm, 1..maxk] of longint;
    count: array [0..maxs] of longint;
    n, m, s: longint;
    _x: longint;

procedure rec(x, y: longint; b: tarr);
var
    i, r: longint;
begin
    if x > m then
    begin
        r := 0;
        for i := 1 to n do
            r := r + b[i];
        if s >= r then
            count[s - r] := count[s - r] + y;
        exit;
    end;

    rec(x + 1, y, b);
    for i := 1 to n do
    begin
        _x := x;
        if a[x][i] > b[i] then
            b[i] := a[x][i];
        end;
    rec(x + 1, -y, b);
end;

procedure norm(var x: tlong);
var
    i, c: longint;
begin
    c := 0;
    for i := 1 to x.d do
    begin
        x.a[i] := x.a[i] + c;
        c := 0;
        if x.a[i] > base div 2 then
        begin
            x.a[i] := x.a[i] - base;
            c := 1;
        end;
        if x.a[i] < -(base div 2) then
        begin
            x.a[i] := x.a[i] + base;
            c := -1;
        end;
    end;
    if c <> 0 then
    begin
        inc(x.d);
        x.a[x.d] := c;
    end;
end;

procedure pnorm(var x: tlong);
var
    i, c: longint;
begin
    c := 0;
    norm(x);
    for i := 1 to x.d do
    begin
        x.a[i] := x.a[i] + c;
        c := 0;
        while x.a[i] < 0 do
        begin
            x.a[i] := x.a[i] + base;
            dec(c);
        end;
    end;
    if (c < 0) or (c >= base) then   
        runerror(240);
    if c > 0 then
    begin
        inc(x.d);
        x.a[x.d] := c;
    end;
    if x.a[x.d] < 0 then
        runerror(240);
end;

procedure init(var x: tlong; y: longint);
begin
    x.d := 1;
    x.a[1] := y;
    norm(x);
end;

procedure addl(var x, y: tlong);
var
    i, u: longint;
begin
    u := max(x.d, y.d);
    for i := 1 to u do
    begin
        x.a[i] := x.a[i] + y.a[i];
    end;
    x.d := u;
    norm(x);
end;

procedure muls(var x: tlong; s: int64);
var
    i: longint;
    c: int64;
begin
    c := 0;
    for i := 1 to x.d do
    begin
        c := c + x.a[i] * s;
        x.a[i] := c mod base;
        c := c div base;
    end;
    if c <> 0 then
    begin
        inc(x.d);
        x.a[x.d] := c;
    end;
    norm(x);
end;

procedure print(var x: tlong);
var
    i, j, k: longint;
begin
    pnorm(x);
    i := x.d;
    while (i > 1) and (x.a[i] = 0) do
        dec(i);
    write(x.a[i]);
    dec(i);
    while i > 0 do
    begin
        j := base;
        k := x.a[i];
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
    i, j: longint;
    ans: tlong;
    vol: array [0..maxs] of tlong;

begin
    assign(input, 'exp.in');
    reset(input);
    assign(output, 'exp.out');
    rewrite(output);

    read(n, s, m);
    for i := 1 to m do
    begin
        for j := 1 to n do
            read(a[i][j]);
    end;

    for i := 0 to s do
        count[i] := 0;

    for i := 1 to n do
        b[i] := 0;
    rec(1, 1, b);

    init(vol[0], 1);
    for i := 0 to n do
        for j := 1 to s do
            addl(vol[j], vol[j - 1]);

    init(ans, - n * s - 1);
    for i := 0 to s do
    begin
        muls(vol[i], count[i]);
        addl(ans, vol[i]);
    end;
    print(ans);

    close(input);
    close(output);
end.