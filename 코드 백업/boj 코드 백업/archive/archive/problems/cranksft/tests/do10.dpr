uses
    genpoly, dorand;

{$I const.inc}

var a: extended;

function p: tp;
begin
    result := polar(1000, fvd, lnd);
    result := rotate(c(
        rflip(longrandfixd(0, 10, gauss)),
        rflip(longrandfixd(0, 10, sqd))
    ), a);
end;

var
    n, i: longint;
begin
    n := 3;
    writeln(n);
    regint(10001);
    for i := 1 to n do begin
        a := lnd * 2 * pi;
        genPolygon(3, p);
    end;
end.