{-----------------------------------------------------------}
{ ACM ICPC 2003-2004                                        }
{ Northeastern European Region                              }
{ Northern Subregional Contest                              }
{                                                           }
{ Problem K. Key Insertion                                  }
{ Author: ???                                               }
{ Solution: Georgiy Korneev                                 }
{-----------------------------------------------------------}
{ Stupid solution                                           }
{-----------------------------------------------------------}

{$q+,r+}
{$apptype console}
const
    max_n = 1024;
var
    i, j, n, m: longint;
    p, r: array [0..max_n + 1] of longint;
begin
    assign(input, 'key.in'); reset(input);
    read(n, m);
    for i := 1 to m do begin
        read(p[i]);
        j := p[i];
        while r[j] <> 0 do begin
            inc(j);
        end;
        while j <> p[i] do begin
            r[j] := r[j - 1];
            dec(j);
        end;
        r[p[i]] := i;
        {
        for j := 1 to n do begin
            if (r[j - 1] = 0) and (r[j] <> 0) then begin
                write('[');
            end else begin
                write(' ');
            end;

            //write(r[j]);
            write(j);
            if (r[j + 1] = 0) and (r[j] <> 0) then begin
                write(']');
            end else begin
                write(' ');
            end;
            write(' ');
        end;
        writeln;        
        }
    end;
    for j := 1 to n do begin
        write(r[j], ' ');
    end;
    writeln;
end.
