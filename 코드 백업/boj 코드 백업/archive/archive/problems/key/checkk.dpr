program checkk;

uses
    testlib, sysutils;

var
    i, ja, pa, j, p: longint;

begin
    ja := ans.readlongint;
    pa := ouf.readlongint;

    if ja <> pa then
        quit(_wa, 'wrong array length, expected: ' + inttostr(ja) + ',found: ' + inttostr(pa));

    for i := 1 to ja do
    begin
        j := ans.readlongint;
        p := ouf.readlongint;

        if j <> p then
            quit(_wa, 'a[' + inttostr(i) + '] is wrong, expected: ' + inttostr(j) + ', found: ' + inttostr(p));
    end;

    quit(_ok, inttostr(ja) + ' values');
end.