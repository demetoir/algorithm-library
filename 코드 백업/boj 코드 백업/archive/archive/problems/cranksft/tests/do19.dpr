uses
    genpoly, dorand;

{$I const.inc}

var a: extended;

function q: extended;
begin
    q := 1 - sqd;
end;

function p: tp;
begin
    result := rotate(polar(max_a div 5, q, qwd), a);
end;

var
    n, i: longint;
begin
    n := 50;
    writeln(n);
    regint(10020);
    for i := 1 to n do begin
        a := lnd * 2 * pi;
        genPolygon(180 + round(lnd * (max_m - 180)), p);
    end;
end.