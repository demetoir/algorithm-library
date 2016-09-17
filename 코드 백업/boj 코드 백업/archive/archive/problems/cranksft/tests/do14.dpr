uses
    genpoly, dorand;

{$I const.inc}

var 
    a: extended;
    z: longint;
    cz: longint;

function p: tp;
var
    l: longint;
begin
    l := max_a div 15 ;
    if cz mod 2 = 0 then l := l div 5;
    result := rotate(c(random(l) + 10, 0), 2 * pi * cz / z * 0.9 + a);
    inc(cz);
end;

var
    n, i: longint;
begin
    n := 10;
    writeln(n);
    regint(10055);
    for i := 1 to n do begin    
        a := lnd * 2 * pi;
        cz := 0;
        z := 3 + random(123);
        genPolygon(z, p);
    end;
end.