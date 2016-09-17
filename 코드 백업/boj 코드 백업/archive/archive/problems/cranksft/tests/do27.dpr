uses
    genpoly, dorand;

{$I const.inc}

function p: tp;
begin
    result := polar(1000, fvd, lnd);
    result := c(
        rflip(longrandfixd(0, max_a, gauss)),
        rflip(longrandfixd(0, max_a, r5))
    );
end;

var
    n, i: longint;
begin
    n := 100;
    writeln(n);
    regint(10028);
    for i := 1 to n do begin
        genPolygon(200, p);
    end;
end.