{-----------------------------------------------------------}
{ ACM ICPC 2003-2004                                        }
{ Northeastern European Region                              }
{ Northern Subregional Contest                              }
{                                                           }
{ Problem G. Greatest Common Inreasing Subsequence          }
{ Author: ???                                               }
{ Solution: Georgiy Korneev                                 }
{-----------------------------------------------------------}

{$apptype console}
const
    max_l = 500;
var
    l1, l2: longint;
    s1, s2, f: array [1..max_l] of longint;
    i, j, k: longint;
    q, pi, pj: array [0..max_l, 0..max_l] of longint;
    m, mi, mj: longint;

procedure o(i, j: longint);
begin
    if (i > 0) and (j > 0) then begin
        o(pi[i][j], pj[i][j]);
        write(s1[i], ' ');
    end;
end;

begin
    assign(input, 'gcis.in'); reset(input);
    assign(output, 'gcis.out'); rewrite(output);

    read(l1);
    for i := 1 to l1 do begin
        read(s1[i]);
    end;

    read(l2);
    for i := 1 to l2 do begin
        read(s2[i]);
    end;

    m := 0;
    mi := 0;
    mj := 0;
    for i := 1 to l1 do begin
        for j := 1 to l2 do begin
            q[i][j] := 0;
            if s1[i] = s2[j] then begin
                for k := 1 to j - 1 do begin
                    if (s2[k] < s2[j]) and (q[i][j] < q[f[k]][k]) then begin
                        q[i][j] := q[f[k]][k];
                        pi[i][j] := f[k];
                        pj[i][j] := k;
                    end;
                end;
                q[i][j] := q[i][j] + 1;
                if m < q[i][j] then begin
                    m := q[i][j];
                    mi := i;
                    mj := j;
                end;
            end;
        end;
        for j := 1 to l2 do begin
            if s1[i] = s2[j] then begin
                f[j] := i;
            end;
        end;
    end;

    writeln(m);
    o(mi, mj);

    close(input);
    close(output);
end.