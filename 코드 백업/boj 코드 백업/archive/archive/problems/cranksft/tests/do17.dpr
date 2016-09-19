uses
    genpoly, dorand;

{$I const.inc}

var a: extended;

function p: tp;
begin
    result := rotate(polar(10000, lnd, fvd), a);
end;

var
    n, i: longint;
begin
    n := 15;
    writeln(n);
    regint(10005);
    for i := 1 to n do begin
        a := lnd * 2 * pi;
        genPolygon(3 + random(20), p);
    end;
end.