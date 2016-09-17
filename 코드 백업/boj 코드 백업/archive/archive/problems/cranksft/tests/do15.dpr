uses
    genpoly, dorand;

{$I const.inc}

var 
    z: longint;
    cz: longint;

function p: tp;
begin
    result := rotate(c(max_a div 17, 0), 2 * pi * cz / z * 0.99);
    inc(cz);
end;

var
    n, i: longint;
begin
    n := 10;
    writeln(n);
    regint(10053);
    for i := 1 to n do begin    
        cz := 0;
        z := 3 + random(123);
        genPolygon(z, p);
    end;
end.