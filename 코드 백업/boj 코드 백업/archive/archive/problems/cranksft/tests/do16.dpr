uses
    genpoly, dorand;

{$I const.inc}

var a: extended;

function p: tp;
begin
    result := polar(1000, fvd, lnd);
end;

var
    n, i: longint;
begin
    n := 15;
    writeln(n);
    regint(10004);
    for i := 1 to n do begin
        a := lnd * 2 * pi;
        genPolygon(3 + random(8), p);
    end;
end.