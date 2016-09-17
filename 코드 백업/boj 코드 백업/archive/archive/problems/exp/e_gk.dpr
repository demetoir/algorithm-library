{-----------------------------------------------------------}
{ ACM ICPC 2003-2004                                        }
{ Northeastern European Region                              }
{ Northern Subregional Contest                              }
{                                                           }
{ Problem E. Experiment "X": Expected Explosions            }
{ Author: Andrew Lopatine                                   }
{ Solution: Georgiy Korneev                                 }
{-----------------------------------------------------------}

{$q-,r-,s-}
{$apptype console}
uses watch;
const
    max_k = 30;
    max_n = 20;
    max_s = 10000;
    max_l = max_k * 4;
    radix = 10;

type tcorner = array [1..max_k] of longint;
type tlong = array [1..max_l] of longint;

procedure lmul(var a: tlong; b: longint);
var
    i, p: longint;
begin
    p := 0;
    for i := 1 to max_l do begin
        p := p div radix + a[i] * b;
        a[i] := p mod radix;
    end;
    if p <> 0 then begin
        writeln('Overflow');
        runerror(239);
    end;
end;

procedure ldiv(var a: tlong; b: longint);
var
    i, p: longint;
begin    
    p := 0;
    for i := max_l downto 1 do begin
        p := (p mod b) * radix + a[i];
        a[i] := p div b;
    end;
    if p mod b <> 0 then begin
        writeln('div has remainder');
        runerror(240);
    end;
end;

procedure init(var a: tlong; p: longint);
var
    i: longint;
begin
    for i := 1 to max_l do begin
        a[i] := p mod radix;
        p := p div radix;
    end;
end;

procedure ladd(var a, b: tlong);
var
    i, p: longint;
begin
    p := 0;
    for i := 1 to max_l do begin
        p := p div radix + a[i] + b[i];
        a[i] := p mod radix;
    end;
end;

procedure lsub(var a, b: tlong);
var
    i, p: longint;
begin
    p := 0;
    for i := 1 to max_l do begin
        p := p + a[i] - b[i];
        if p < 0 then begin
            a[i] := p + radix;
            p := -1;
        end else begin
            a[i] := p;
            p := 0;
        end;
    end;
end;

procedure o(var a: tlong);
var
    i: longint;
    f: boolean;
begin
    f := false;
    for i := max_l downto 2 do begin
        f := f or (a[i] <> 0);
        if f then write(a[i]);
    end;
    writeln(a[1]);
end;

var
    i, j, k, n, s: longint;
    a: array [0..max_s] of tlong;
    z: array [0..max_n] of tcorner;
    c: array [-max_s..max_s] of longint;
    q: tcorner;

procedure rec(l, m, s: longint; q: tcorner);
var
    i: longint;
begin
    if (l <= n) and (s >= 0) then begin
        rec(l + 1, m, s, q);        
        for i := 1 to k do begin
            if q[i] < z[l][i] then begin
                s := s + q[i] - z[l][i];
                q[i] := z[l][i];
            end;
        end;
        if m mod 2 = 1 then inc(c[s]) else dec(c[s]);
        rec(l + 1, m + 1, s, q);
    end;
end;

var
    r, r1: tlong;
begin
    //initStopwatch();

    assign(input, 'exp.in'); reset(input);
    assign(output, 'exp.out'); rewrite(output);

    read(k, s, n);

    for i := 1 to n do begin
        for j := 1 to k do begin
            read(z[i][j]);
        end;
    end;
    stopwatch('input');

    init(a[0], 1);
    for i := 1 to s do begin
        a[i] := a[i - 1];
        lmul(a[i], k + i);
        ldiv(a[i], i);
    end;
    stopwatch('calc a');

    init(r1, k);
    lmul(r1, s);
    ladd(r1, a[0]);

    r := a[s];
    lsub(r, r1);
    stopwatch('calc r');

    fillchar(q, sizeof(q), 0);
    rec(1, 0, s, q);
    stopwatch('rec');

    for i := 0 to s do begin
        lmul(a[i], abs(c[i]));
        if c[i] > 0 then begin
            ladd(r, a[i]);
        end else begin
            lsub(r, a[i]);
        end;
    end;
    stopwatch('calc result');
    o(r);
    stopwatch('output');

    close(input);
    close(output);
end.