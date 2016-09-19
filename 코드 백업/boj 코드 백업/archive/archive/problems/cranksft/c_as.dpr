const
    maxm = 1000;
var
    sa, xa, ya, xc, yc, s: int64;
    i, j, m, n: longint;
    x, y: array [1..maxm] of int64;

function sign(x: int64): int64;
begin
    if x >= 0 then
        sign := 1
    else
        sign := -1;
end;

begin
    assign(input, 'cranksft.in');
    reset(input);
    assign(output, 'cranksft.out');
    rewrite(output);

    read(n);
    xa := 0;
    ya := 0;
    sa := 0;
    for j := 1 to n do
    begin
        read(m);
        for i := 1 to m do
        begin
            read(x[i], y[i]);
        end;
        x[m + 1] := x[1];
        y[m + 1] := y[1];

        s := 0;
        xc := 0;
        yc := 0;
        for i := 1 to m do
        begin
            s := s + (x[i + 1] + x[i]) * (y[i + 1] - y[i]);
            xc := xc + (x[i + 1] * x[i + 1] + x[i] * x[i + 1] + x[i] * x[i]) * (y[i + 1] - y[i]);
            yc := yc + (y[i + 1] * y[i + 1] + y[i] * y[i + 1] + y[i] * y[i]) * (x[i + 1] - x[i]);
        end;
        xa := xa + xc * sign(s);
        ya := ya + yc * sign(s);
        sa := sa + abs(s);
    end;

    writeln(xa / sa / 3 :0 :20, ' ', -ya / sa / 3 :0 :20);

    close(input);
    close(output);
end.