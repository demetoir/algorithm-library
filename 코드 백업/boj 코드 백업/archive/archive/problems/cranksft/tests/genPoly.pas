{ $define _graph}
{$q+,r+,o-}

unit genPoly;

interface
uses dorand;

type tp = record
    x, y: int64;
end;

type tcoord=function:tp;
type rcoord=function:longint;

procedure genPolygon(n: longint; c: tcoord);
function rflip(x: longint): longint;
function c(x, y: longint): tp;
function rotate(p: tp; angle: double): tp;
procedure rect(size_x, size_y: longint; angle: double);
function polar(max_r: longint; rf, phif: rands): tp;

function r2: extended;
function r3: extended;
function r4: extended;
function r5: extended;

implementation
uses
    sysutils, math, graph, types, graphics;

const
    eps = 1e-3;

const
    scale = 0.90;

{$I const.inc}

function between(a, x, b: extended): boolean;
begin
    between := 
        (a < x + eps) and (x - eps < b) or
        (b < x + eps) and (x - eps < a);
end;

function intersect(x11, y11, x12, y12, x21, y21, x22, y22: int64): boolean;
var
    a1, b1, c1, a2, b2, c2, d: int64;
    x, y: extended;
begin
    a1 := y11 - y12;
    b1 := x12 - x11;
    c1 := x11 * a1 + y11 * b1;

    a2 := y21 - y22;
    b2 := x22 - x21;
    c2 := x21 * a2 + y21 * b2;

    d := a1 * b2 - a2 * b1;
    if d <> 0 then begin
        x := (c1 * b2 - c2 * b1) / d;
        y := (a1 * c2 - a2 * c1) / d;
        result := 
            between(x11, x, x12) and between(y11, y, y12) and
            between(x21, x, x22) and between(y21, y, y22)
            
    end else begin  
        result := false;
    end;
end;

var
    p: array [1..max_m] of tp;

procedure drawPoints(n: longint);
var
    i: longint;
    minx, maxx, miny, maxy: longint;
    sx, sy, cx, cy: double;
    sizex, sizey: integer;
    points: array of tPoint;     
begin    
    {$ifdef _graph}
    minx := maxlongint;
    maxx := -maxlongint;
    miny := maxlongint;
    maxy := -maxlongint;
    for i := 1 to n do begin
        if (minx > p[i].x) then minx := p[i].x;
        if (maxx < p[i].x) then maxx := p[i].x;
        if (miny > p[i].y) then miny := p[i].y;
        if (maxy < p[i].y) then maxy := p[i].y;
    end;

    sizex := form.clientwidth;
    sizey := form.clientheight;

    if maxx - minx = 0 then begin
        maxx := maxx + 1;
        minx := minx - 1;
    end;
    if maxy - miny = 0 then begin
        maxy := maxy + 1;
        miny := miny - 1;
    end;
    sx := sizex / (maxx - minx) * scale;
    sy := sizey / (maxy - miny) * scale;
    if sx > sy then begin
        sx := sy;
    end else begin
        sy := sx;
    end;
    cx := (maxx + minx) / 2;
    cy := (maxy + miny) / 2;

    clear;

    setLength(points, n);
    for i := 1 to n do begin
        points[i - 1].x := round(sizex / 2 + sx * (p[i].x - cx));
        points[i - 1].y := round(sizey / 2 - sy * (p[i].y - cy));
        //write(' ', p[i].x, ' ', p[i].y);
    end;
    //writeln('!');
    canvas.
    polygon(points);
    waitForKey;
    {$endif}
end;

procedure reverse(a, b: longint);
var
    i: longint;
    t: tp;
begin
    for i := 0 to (b - a) div 2 do begin
        t := p[a + i]; p[a + i] := p[b - i]; p[b - i] := t;
    end;
end;

procedure normalize(n: longint);
var
    i, j: longint;
    f: boolean;
    cm: int64;
begin
    f := true;
    while f do begin
        f := false;
        for i := 1 to n do begin
            for j := i + 2 to n do begin
                if (i = 1) and (j = n) then continue;
                if 
                    intersect(
                        p[i].x, p[i].y, p[i mod n + 1].x, p[i mod n + 1].y,
                        p[j].x, p[j].y, p[j mod n + 1].x, p[j mod n + 1].y
                    ) 
                then begin
                    {
                    if not f or (mb - ma > j - i - 1) then begin
                        ma := i + 1;
                        mb := j;
                    end;
                    }
                    reverse(i + 1, j);
                    f := true;
                end;
            end;
        end;
        //inc(p[1 + random(n)].x);
        //dec(p[1 + random(n)].y);
        //if f then reverse(ma, mb);
        //drawPoints(n);
    end;

    cm := 0;
    for j := 1 to n do begin
        cm := cm + p[j].x * p[j mod n + 1].y - p[j mod n + 1].x * p[j].y;
    end;
    //writeln('! ', cm);
    {
    cm := 0;
    for j := 1 to n do begin
        cm := cm + (p[j].x + p[j mod n + 1].x) * (p[j mod n + 1].y - p[j].y);
    end;
    //writeln('? ', cm);
    }
    if cm > 0 then reverse(1, n);
end;

procedure print(n: longint);
var
    i: longint;
    x: array of integer;
    y: array of integer;
    cnt:integer;
begin
    setlength (x, n+2);
    setlength (y, n+2);
    for i:=1 to n do x[i]:=p[i].x;
    for i:=1 to n do y[i]:=p[i].y;
    {write(n);
    for i := 1 to n do begin
        write(' ', p[i].x, ' ', p[i].y);
    end;}
    x[0]:=x[N]; y[0]:=y[N]; x[N+1]:=x[1]; y[N+1]:=y[1];
    cnt:=0;
    for i:=1 to N do
      if (x[i]-x[i-1])*(y[i+1]-y[i])-(x[i+1]-x[i])*(y[i]-y[i-1])<>0 then
        inc (cnt);
    write (cnt);
    for i:=1 to N do
      if (x[i]-x[i-1])*(y[i+1]-y[i])-(x[i+1]-x[i])*(y[i]-y[i-1])<>0 then
        write (' ', x[i], ' ', y[i]);
    writeln;
end;

procedure all(n: longint);
begin
    //writeln('normalize');
    normalize(n);
    print(n);
    drawPoints(n);
end;

procedure genPolygon(n: longint; c: tcoord);
var
    i, j: longint;
    f: boolean;
    ta, tb, tc: array [1..max_m] of int64;
begin
    for i := 1 to n do begin
        repeat
            f := false;
            p[i] := c();
            if p[i].x > max_a then p[i].x := max_a;
            if p[i].y > max_a then p[i].y := max_a;
            if p[i].x < -max_a then p[i].x := -max_a;
            if p[i].y < -max_a then p[i].y := -max_a;
            for j := 1 to i - 1 do begin
                f := f or (p[i].x = p[j].y) and (p[i].x = p[j].y);
            end;
            for j := 2 to i - 1 do begin
                f := f or (
                    (p[i].x * ta[j] + p[i].y * tb[j] - tc[j] = 0) and
                    between(p[j - 1].x, p[i].x, p[j].x) and
                    between(p[j - 1].y, p[i].y, p[j].y)
                );
            end;
        until not f;
        if i > 1 then begin
            ta[i] := p[i - 1].y - p[i].y;
            tb[i] := p[i].x - p[i - 1].x;
            tc[i] := p[i].x * ta[i] + p[i].y * tb[i];
        end;
    end;

    all(n);
end;

procedure rect(size_x, size_y: longint; angle: double);
begin
    p[1] := rotate(c(+size_x, +size_y), angle);
    p[2] := rotate(c(+size_x, -size_y), angle);
    p[3] := rotate(c(-size_x, -size_y), angle);
    p[4] := rotate(c(-size_x, +size_y), angle);
    all(4);
end;

function rflip(x: longint): longint;
begin
    if coin then rflip := x else rflip := -x;
end;

function c(x, y: longint): tp;
begin
    result.x := x;
    result.y := y;
end;

function rotate(p: tp; angle: double): tp;
begin
    result.x := round(p.x * cos(angle) + p.y * sin(angle));
    result.y := round(p.y * cos(angle) - p.x * sin(angle));
end;

function r2: extended;
var
    r: extended;
begin
    r := random;
    result := r * r;
end;

function r3: extended;
var
    r: extended;
begin
    r := random;
    result := r * r * r;
end;

function r4: extended;
var
    r: extended;
begin
    r := random;
    result := r * r * r * r;
end;

function r5: extended;
var
    r: extended;
begin
    r := random;
    result := r * r * r * r * r;
end;

function polar(max_r: longint; rf, phif: rands): tp;
var
    r, phi: double;
begin
    r := rf * max_r;
    phi := phif * 2 * pi;
    result.x := round(r * cos(phi));
    result.y := round(r * sin(phi));
end;

begin
    {$ifdef _graph}
    initGraph();
    {$endif}
end.

