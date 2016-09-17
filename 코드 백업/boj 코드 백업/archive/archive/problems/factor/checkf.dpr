uses
    testlib, sysutils;
var
    ja, pa: string;        
begin
    ja := ans.readstring;
    pa := uppercase(ouf.readstring);

    if (pa <> 'YES') and (pa <> 'NO') then
        quit(_pe, '"YES" or "NO" expected, "' + pa + '" found');

    if ja <> pa then
        quit(_wa, 'expected: ' + ja + ', found: ' + pa);

    quit(_ok, ja);
end.