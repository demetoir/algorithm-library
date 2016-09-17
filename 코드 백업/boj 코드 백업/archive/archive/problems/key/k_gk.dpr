{-----------------------------------------------------------}
{ ACM ICPC 2003-2004                                        }
{ Northeastern European Region                              }
{ Northern Subregional Contest                              }
{                                                           }
{ Problem K. Key Insertion                                  }
{ Author: ???                                               }
{ Solution: Georgiy Korneev                                 }
{-----------------------------------------------------------}

{$q-,r-,o+}
{$apptype console}

{$define stopwatch}

uses
    math, sysutils;
const
    max_n = $100000;
var
    i, j, n, m: longint;
    p, r, next, last: array [1..max_n] of longint;
    a: array [0..2*max_n] of longint;
    z: longint;
    x, t, h, s, head: array [0..max_n + 1] of longint;
    u: array [0..max_n + 1] of boolean;
    c: longint;

function find(i: longint): longint;
begin
    inc(c);
    if x[i] <> i then begin
        x[i] := find(x[i]);
    end;
    find := x[i];
end;

function join(i, j: longint): longint;
var
    k: longint;
    i1, j1: longint;
begin
    i := find(i);
    j := find(j);
    if i = j then runerror(239);
    if t[i] > t[j] then begin
        k := i; i := j; j := k;
    end;
    if h[i] = h[j] then begin
        inc(h[i]);
    end;
    i1 := head[i];
    j1 := head[j];
    next[last[j1]] := i1;
    last[j1] := last[i1];
    if h[i] > h[j] then begin
        x[j] := i;
        s[i] := s[i] + s[j];
        head[i] := head[j];
        join := i;
    end else begin
        x[i] := j;
        s[j] := s[i] + s[j];
        t[j] := t[i];
        join := j
    end;
end;

function remove(p: longint): longint;
var
    i: longint;
begin
    i := 1;
    while i < z do begin
        if p <= a[i] then begin
            dec(a[i]);
            i := i * 2;
        end else begin
            p := p - a[i];
            i := i * 2 + 1;
        end;
    end;
    remove := i - z + 1;
end;

procedure use(i, p: longint);
begin
    u[p] := true;
    next[i] := 0;
    last[i] := i;
    head[p] := i;
end;

var
    tm, tm2: double;
procedure initStopwatch();
begin
    tm := now();
    tm2 := tm;
end;
procedure stopwatch(s: string);
begin
    {$ifdef _stopwatch}
    writeln(s, ' ', (now() - tm) * 24 * 60 * 60:0:5, ' (', (now() - tm2) * 24 * 60 * 60:0:5, ')');
    tm := now();
    {$endif}
end;

var
    xm, q: longint;
begin
    initStopwatch();

    assign(input, 'key.in'); reset(input);
    assign(output, 'key.out'); rewrite(output);
    stopwatch('assign');
    read(m, n);
    n := max_n;
    for i := 1 to m do begin
        read(p[i]);
    end;

    stopwatch('input');

    z := 1;
    while z < n do begin
        z := z * 2;
    end;
    for i := z div 2 to z - 1 do begin
        a[i] := 1;
    end;
    for i := z div 2 - 1 downto 1 do begin
        a[i] := a[i * 2] + a[i * 2 + 1];
    end;

    stopwatch('init a');

    for i := 1 to n do begin
        x[i] := i;
        h[i] := 0;
        s[i] := 1;
        t[i] := i;
    end;
    stopwatch('init DS');

    for i := 1 to m do begin
        if u[p[i]] then begin
            xm := find(p[i]);
            use(i, t[xm] + s[xm]);
            xm := join(xm, t[xm] + s[xm]);
            if u[t[xm] + s[xm]] then begin
                join(xm, t[xm] + s[xm]);
            end;
        end else begin
            use(i, p[i]);
            if u[p[i] - 1] then begin
                join(p[i] - 1, p[i]);
            end;
            if u[p[i] + 1] then begin
                join(p[i], p[i] + 1);
            end;
        end;
        {
        j := 1;
        while j <= n do begin
            if u[j] then begin
                write('[');
                for k := 1 to s[find(j)] - 1 do begin
                    if k <> 1 then write(' ');
                    write(j + k - 1, '  ');
                end;
                if s[find(j)] <> 1 then write(' ');
                write(j + s[find(j)] - 1, '] ');
                j := j + s[find(j)];
            end else begin
                write(' ', j, '  ');
                inc(j);
            end;
        end;
        writeln;
        }
    end;
    stopwatch('join');

    j := n;
    while j > 0 do begin
        if u[j] then begin
            j := find(j);
            i := head[j];
            j := t[j];
            while i <> 0 do begin
                r[remove(p[i])] := i;
                i := next[i];
                {
                for k := 1 to n do begin
                    write(r[k], ' ');
                end;
                writeln;
                }
            end;
        end ;
        dec(j);
    end;
    stopwatch('restore');

    q := 0;
    for i := n downto 1 do begin
        if r[i] <> 0 then begin
            q := i;
            break;
        end;
    end;

    writeln(q);
    for i := 1 to q do begin
        write(r[i], ' ');
    end;
    writeln;
    stopwatch('finish');

    //writeln(c);
    close(input);
    close(output);
end.
