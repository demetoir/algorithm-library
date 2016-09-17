uses
    math;

const
    maxn = 200;
    maxm = 10000;
    maxp = maxm * 2 + maxn * 2 + 2;

var
    i, j, k, n, m, p, h, t, w, s, count, value: longint;
    src, dst, cap, rev, next, flow: array [1..maxp] of longint;
    head, d, f, q: array [0..2 * maxn + 1] of longint;
    u: array [0..2 * maxn + 1] of boolean;
    z: longint;
begin
    assign(input, 'destroy.in');
    reset(input);
    assign(output, 'destroy.out');
    rewrite(output);

    read(n, m);
    if (n > maxn) or (m > maxm) then
        runerror(239);

    p := 0;
    s := 0;
    for i := 1 to n do
    begin
        read(w);
        inc(p);
        dst[p] := 2 * n + 1;
        src[p] := i + n;
        cap[p] := w;
        rev[p] := 0;
        next[p] := head[i + n];
        head[i + n] := p;

        s := s + w;
    end;
    for i := 1 to n do
    begin
        read(w);
        inc(p);
        dst[p] := i;
        src[p] := 0;
        cap[p] := w;
        rev[p] := 0;
        next[p] := head[0];
        head[0] := p;

        s := s + w;
    end;

    for i := 1 to m do
    begin   
        read(j, k);
        inc(p);
        dst[p] := n + k;
        src[p] := j;
        cap[p] := s;
        rev[p] := p + 1;
        next[p] := head[j];
        head[j] := p;

        inc(p);
        dst[p] := j;
        src[p] := n + k;
        cap[p] := 0;
        rev[p] := p - 1;
        next[p] := head[k + n];
        head[k + n] := p;
    end;

    value := 0;
    while true do
    begin
        for i := 0 to 2 * n + 1 do
        begin
            u[i] := false;
        end;

        h := 0;
        t := 1;
        q[h] := 0;
        u[0] := true;
        d[0] := s;
        while h < t do
        begin
            i := q[h];
            inc(h);

            j := head[i];
            while j <> 0 do
            begin
                if flow[j] < cap[j] then
                begin
                    if not u[dst[j]] then
                    begin
                        w := min(d[i], cap[j] - flow[j]);
                        d[dst[j]] := w;
                        f[dst[j]] := j;
                        u[dst[j]] := true;
                        q[t] := dst[j];
                        inc(t);
                    end;
                end;
                j := next[j];
            end;
        end;

        if u[2 * n + 1] then
        begin
            w := d[2 * n + 1];
            value := value + w;
            i := 2 * n + 1;
            while i <> 0 do
            begin
                j := f[i];
                flow[j] := flow[j] + w;
                if rev[j] <> 0 then
                    flow[rev[j]] := flow[rev[j]] - w;
                i := src[j];
            end;
        end else begin
            break;
        end;
    end;

    writeln(value);
    count := 0;

    for i := 1 to n do
        if not u[i] then
            inc(count);
    for i := 1 to n do
        if u[n + i] then
            inc(count);

    writeln(count);
    for i := 1 to n do
        if not u[i] then
            writeln(i, ' -');
    for i := 1 to n do
        if u[n + i] then
            writeln(i, ' +');


    close(input);
    close(output);
end.