uses
    genpoly, dorand;

{$I const.inc}

var 
    a: extended;
    z: longint;
    cz: longint;

function p: tp;
begin
    result := rotate(c(max_a div 17, 0), 2 * pi * cz / z * 0.9 + a);
    inc(cz);
end;

var
    n, i: longint;
begin
    n := 10;
    writeln(n);
    regint(10054);
    for i := 1 to n do begin    
        a := lnd * 2 * pi;
        cz := 0;
        z := 3 + random(123);
        genPolygon(z, p);
    end;
end.