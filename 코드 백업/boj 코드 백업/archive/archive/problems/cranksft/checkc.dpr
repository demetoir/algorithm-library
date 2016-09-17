uses
    testlib, sysutils;

const
    eps = 1.1e-4;

var
    ja, pa: extended;

begin
    ja := ans.readreal;
    pa := ouf.readreal;

    if abs(ja - pa) > eps then
        quit(_wa, 'X expected: ' + floattostr(ja) + ', found: ' + floattostr(pa));

    ja := ans.readreal;
    pa := ouf.readreal;

    if abs(ja - pa) > eps then
        quit(_wa, 'Y expected: ' + floattostr(ja) + ', found: ' + floattostr(pa));

    quit(_ok, floattostr(ja));
end.