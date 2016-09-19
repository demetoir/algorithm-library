uses
    genpoly, dorand;

{$I const.inc}

var a: extended;

function p: tp;
begin
    result := polar(1000, fvd, lnd);
    result := rotate(c(
        rflip(longrandfixd(0, max_a div 2, gauss)),
        rflip(longrandfixd(0, max_a div 2, sqd))
    ), a);
end;

var
    n, i: longint;
begin
    n := 80;
    writeln(n);
    regint(10023);
    for i := 1 to n do begin
        a := lnd * 2 * pi;
        genPolygon(10 + round(lnd * (max_m - 10)), p);
    end;
end.