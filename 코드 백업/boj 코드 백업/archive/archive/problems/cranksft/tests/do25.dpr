uses
    genpoly, dorand;

{$I const.inc}

var a: extended;

function p: tp;
begin
    result := polar(1000, fvd, lnd);
    result := rotate(c(
        rflip(longrandfixd(0, max_a, fvd)),
        rflip(longrandfixd(0, max_a, lnd))
    ), a);
end;

var
    n, i: longint;
begin
    n := 100;
    writeln(n);
    regint(10026);
    for i := 1 to n do begin
        a := lnd * 2 * pi;
        genPolygon(200, p);
    end;
end.