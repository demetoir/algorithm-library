{-----------------------------------------------------------}
{ ACM ICPC 2003-2004                                        }
{ Northeastern European Region                              }
{ Northern Subregional Contest                              }
{                                                           }
{ Problem I. Invariant Polynomials                          }
{ Author: Nick Dourov                                       }
{ Solution: Georgiy Korneev                                 }
{-----------------------------------------------------------}

var
    i, j, k, n, t: longint;
begin
    assign(input, 'inv.in'); reset(input);
    assign(output, 'inv.out'); rewrite(output);

    read(n, t);

    k := 0;
    for i := 0 to t do begin
        for j := 0 to t - i do begin
            if (i - j) mod n = 0 then begin
                inc(k);
            end;
        end;
    end;

    writeln(k);

    close(input);
    close(output);
end.