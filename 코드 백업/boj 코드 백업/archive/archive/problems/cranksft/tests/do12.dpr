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
    n := 10;
    writeln(n);
    regint(10003);
    for i := 1 to n do begin
        a := lnd * 2 * pi;
        genPolygon(3 + random(8), p);
    end;
end.