{$apptype console}
uses
    testlib, sysutils;
var
    ja, pa: string;
    i: longint;
begin
    ja := ans.readstring;
    pa := ouf.readstring;
    pa := trim(pa);

    if pa = '' then begin
        quit(_pe, 'Interesting tickets number not specified');
    end;

    if not (pa[1] in ['-', '0'..'9']) then begin
        quit(_pe, 'Invalid character in interesting tickets number');
    end;

    for i := 2 to length(pa) do begin
        if not (pa[i] in ['0'..'9']) then begin
            quit(_pe, 'Invalid character in interesting tickets number');
        end;
    end;

    if ja <> pa then begin
        quit(_wa, format('Wrong number of interesting tickets: "%s" instead of "%s"', [pa, ja]));
    end;

    ja := ans.readstring;
    pa := ouf.readstring;
    pa := trim(pa);

    if pa = '' then begin
        quit(_pe, 'Banal tickets number not specified');
    end;

    if not (pa[1] in ['-', '0'..'9']) then begin
        quit(_pe, 'Invalid character in banal tickets number');
    end;

    for i := 2 to length(pa) do begin
        if not (pa[i] in ['0'..'9']) then begin
            quit(_pe, 'Invalid character in banal tickets number');
        end;
    end;

    if ja <> pa then begin
        quit(_wa, format('Wrong number of banal tickets: "%s" instead of "%s"', [pa, ja]));
    end;

    quit(_ok, '');
end.