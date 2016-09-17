uses
    sysutils;

procedure gen(l: longint; s, f: string);
begin
    l := l - length(s) - length(f);
    write(s);
    if l < 9 then begin
        write(random(1000));        
    end else begin
        case (random(4)) of
            0: 
                begin
                    gen(l, '', '');
                    //gen(l, '+(', ')');
                end;
            1:
                begin
                    gen(l, '', '');
                    //gen(l div 2, '(', ')*');
                    //gen(l - l div 2, '(', ')');
                end;
            2: 
                begin
                    gen(l, '', '');
                    //gen(l div 2, '(', ')+');
                    //gen(l - l div 2, '(', ')');
                end;
            3: 
                begin
                    gen(l, '({', '}+' + inttostr(random(1001)) + ')');
                end;
        end;
    end;
    write(f);
end;

var
    i: longint;
begin
    randseed := 239;
    for i := 1 to 100 do begin
        gen(250, '!(', ')*1000');
        writeln;
    end;
end.