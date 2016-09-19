{-----------------------------------------------------------}
{ ACM ICPC 2003-2004                                        }
{ Northeastern European Region                              }
{ Northern Subregional Contest                              }
{                                                           }
{ Problem C. Crankshaft                                     }
{ Author: ???                                               }
{ Solution: Georgiy Korneev                                 }
{-----------------------------------------------------------}

{$apptype console}

const
    max_n = 100;
    max_m = 100;
var
    i, j, n, m: longint;
    x, y: array [1..max_m] of int64;
    lm, gm, cm: int64;
    lx, ly, gx, gy: double;
begin
    assign(input, 'cranksft.in'); reset(input);
    assign(output, 'cranksft.out'); rewrite(output);

    gm := 0;
    gx := 0;
    gy := 0;

    read(n);
    for i := 1 to n do begin
        read(m);
        read(x[1], y[1]);
        for j := 2 to m do begin
            read(x[j], y[j]);
            x[j] := x[j] - x[1];
            y[j] := y[j] - y[1];
        end;
        lm := 0;
        lx := 0;
        ly := 0;
        for j := 2 to m - 1 do begin
            cm := x[j] * y[j + 1] - x[j + 1] * y[j];
            lm := lm + cm;
            lx := lx + cm * (x[j] + x[j + 1]) / 3;
            ly := ly + cm * (y[j] + y[j + 1]) / 3;
        end;
        gx := gx + (x[1] + lx / lm) * abs(lm);
        gy := gy + (y[1] + ly / lm) * abs(lm);
        gm := gm + abs(lm);
    end;
    writeln(gx / gm:0:7, ' ', gy / gm:0:7);

    close(input);
    close(output);
end.