{-----------------------------------------------------------}
{ ACM ICPC 2003-2004                                        }
{ Northeastern European Region                              }
{ Northern Subregional Contest                              }
{                                                           }
{ Problem F. Factoring a Polynomial                         }
{ Author: Nick Dourov                                       }
{ Solution: Georgiy Korneev                                 }
{-----------------------------------------------------------}

{$apptype console}
const
    max_n = 100;
var
    i, n: longint;
    a: array [0..max_n] of longint;
begin
    assign(input, 'factor.in'); reset(input);
    assign(output, 'factor.out'); rewrite(output);

    read(n);
    for i := 0 to n do begin
        read(a[i]);
    end;

    if n < 2 then begin
        writeln('YES');
    end else if (n > 2) then begin
        writeln('NO');
    end else begin
        if a[1] * a[1] - a[0] * a[2] * 4 >= 0 then begin
            writeln('NO');
        end else begin 
            writeln('YES');
        end;
    end;

    close(input);
    close(output);
end.