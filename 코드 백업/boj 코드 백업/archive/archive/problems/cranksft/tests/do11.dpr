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
    n := 5;
    writeln(n);
    regint(10002);
    rect(15, 1, 0);
    for i := 1 to n - 2 do begin
        a := lnd * 2 * pi;
        genPolygon(5, p);
    end;
    rect(10, 20, 0.35);
end.