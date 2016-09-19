var
    a, b, c, n: int64;
begin
    assign(input, 'factor.in');
    reset(input);
    assign(output, 'factor.out');
    rewrite(output);

    read(n);
    if n <= 1 then
        writeln('YES')
    else if n > 2 then
        writeln('NO')
    else begin
        read(a, b, c);
        if b * b - 4 * a * c < 0 then
            writeln('YES')
        else
            writeln('NO');
    end;


    close(input);
    close(output);
end.