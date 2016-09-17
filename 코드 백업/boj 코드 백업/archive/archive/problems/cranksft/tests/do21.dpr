uses
    genpoly, dorand;

{$I const.inc}

var a: extended;

function p: tp;
begin
    result := c(
        rflip(longrandfixd(0, max_a div 2, gauss)),
        rflip(longrandfixd(0, max_a div 2, gauss))
   );
end;

var
    n, i: longint;
begin
    n := 70;
    writeln(n);
    regint(10022);
    for i := 1 to n do begin
        a := lnd * 2 * pi;
        genPolygon(100 + round(lnd * (max_m - 100)), p);
    end;
end.