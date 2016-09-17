var
    d, s, k, n, p: longint;
begin
    assign(input, 'invar.in');
    reset(input);
    assign(output, 'invar.out');
    rewrite(output);

    while not seekeof do begin
    read(d, n);
    s := 0;
    for k := 0 to d do
    begin
        p := d - k - (k mod n);
        if p >= 0 then
            s := s + 1 + p div n;
    end;
    writeln(s);
    end;

    close(input);
    close(output);
end.