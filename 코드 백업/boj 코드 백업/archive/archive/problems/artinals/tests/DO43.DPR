uses
    sysutils;
var
    a: string;

procedure gen(l, indent: longint; s, f: string);
var 
    q: string;
begin
    l := l - length(s) - length(f);
    if l < 4 then begin
        write('':indent, random(1000));
    end else begin
        write('':indent, s);
        case (random(1)) of
            0: begin
                    if random(3) = 0 then begin
                        q := a;
                    end else begin
                        q := inttostr(random(1000));
                    end;
                    gen(l, indent + 0, '{', '}+' + q);
                    //write('+');
                    //gen(3, 0, '', '');
               end;
            1:
                begin
                    gen(l div 2, indent + 0, '(', ')');
                    write('':indent + 0, '+');
                    gen(l div 2, indent + 0, '(', ')');
                end;
        end;
        write('':indent, f);
    end;
end;

begin
    randseed := 239;
    a := '999';
    gen(250, 0, 'a:=', ''); writeln;
    a := 'a';
    gen(100, 0, 'a:=', '');  writeln;
    a := 'a';
    gen(250, 0, '!', '');  writeln;
end.