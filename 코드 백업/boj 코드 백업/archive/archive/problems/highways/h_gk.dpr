{-----------------------------------------------------------}
{ ACM ICPC 2003-2004                                        }
{ Northeastern European Region                              }
{ Northern Subregional Contest                              }
{                                                           }
{ Problem H. Highways                                       }
{ Author: Andrew Stankevich                                 }
{ Solution: Georgiy Korneev                                 }
{-----------------------------------------------------------}

{$apptype console}
const
    max_n = 100000;
var
    i, n: longint;
    a: array [1..max_n] of longint;
    m, mi, mj: longint;
begin
    assign(input, 'highways.in'); reset(input);
    assign(output, 'highways.out'); rewrite(output);

    read(n);
    for i := 1 to n do begin
        read(a[i]);
    end;

    m := maxlongint;
    mi := 0;
    mj := 0;
    for i := 3 to n - 1 do begin
        if m > a[i] - a[1] + a[n] - a[i - 1] then begin
            m := a[i] - a[1] + a[n] - a[i - 1];
            mi := i;
            mj := i - 1;
        end;
    end;

    if m = maxlongint then begin
        writeln('impossibe');
    end else begin
        writeln(1, ' ', mi);
        writeln(mj, ' ', n);
    end;

    close(input);
    close(output);
end.