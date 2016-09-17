uses
    genpoly, dorand;

{$I const.inc}

var a: extended;

function p: tp;
begin
    result := rotate(c(
        rflip(longrandfixd(0, 4, lnd)),
        rflip(longrandfixd(0, 25, lnd))
    ), a);
end;

var
    n, i: longint;
begin
    n := 25;
    writeln(n);
    regint(10086);
    for i := 1 to n do begin
        a := lnd * 2 * pi;
        genPolygon(3 + random(50), p);
    end;
end.