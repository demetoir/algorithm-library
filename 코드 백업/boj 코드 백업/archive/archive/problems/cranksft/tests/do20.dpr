uses
    genpoly, dorand;

{$I const.inc}

var a: extended;

function q: extended;
begin
    q := 1 - fvd;
end;

function p: tp;
begin
    result := polar(max_a div 5, q, lnd);
end;

var
    n, i: longint;
begin
    n := 70;
    writeln(n);
    regint(10021);
    for i := 1 to n do begin
        a := lnd * 2 * pi;
        genPolygon(180 + round(lnd * (max_m - 180)), p);
    end;
end.