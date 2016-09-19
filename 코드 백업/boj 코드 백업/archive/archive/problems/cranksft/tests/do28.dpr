uses
    genpoly, dorand;

{$I const.inc}

function p: tp;
begin
    result := polar(max_a, lnd, lnd);
end;

var
    n, i: longint;
begin
    n := 100;
    writeln(n);
    regint(10029);
    for i := 1 to n do begin
        genPolygon(200, p);
    end;
end.