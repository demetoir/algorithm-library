{ $O-,Q+,R+,S+}
{$O+,Q-,R-,S+}
{$APPTYPE CONSOLE}

const
    maxn = 131072;
    maxm = 131072;
    maxv = 4 * (maxn + maxm);

type
    tpair = record
        k, l: longint;
    end;

var
    chd, cnt: array [0..maxv, 1..4] of longint;
    nc, vl: array [0..maxv] of longint;
    vcount: longint;
    root, value: longint;
    a, b, ans: array [1..maxv] of longint;
    p, s: array [1..maxn + maxm] of longint;
    num: longint;
    heap: array [1..maxn] of tpair;
    hn: longint;

procedure doinsert(v, x, p, i: longint);
var
    r, j, k: longint;
begin       
    r := 0;
    j := 0;
    for k := 1 to nc[v] do
    begin
        if r + cnt[v][k] > x then
        begin
            j := k;
            break;
        end;
        r := r + cnt[v][k];
    end;
    if j = 0 then
    begin
        j := nc[v];
        r := r - cnt[v][j];
    end;

    if nc[chd[v][j]] = 0 then
    begin
        j := x;
        inc(vcount);
        nc[vcount] := 0;
        vl[vcount] := value;
        inc(nc[v]);
        for k := nc[v] downto j + 2 do
        begin
            chd[v][k] := chd[v][k - 1];
            cnt[v][k] := cnt[v][k - 1];
        end;
        chd[v][j + 1] := vcount;
        cnt[v][j + 1] := 1;
    end else begin
        doinsert(chd[v][j], x - r, v, j);
    end;

    if nc[v] = 4 then
    begin
        if p = 0 then
        begin
            inc(vcount);
            p := vcount;
            root := p;
            nc[p] := 1;
            chd[p][1] := v;
            i := 1;
        end;

        inc(vcount);
        nc[vcount] := 2;
        chd[vcount][1] := chd[v][3];
        cnt[vcount][1] := cnt[v][3];
        chd[vcount][2] := chd[v][4];
        cnt[vcount][2] := cnt[v][4];
        nc[v] := 2;
        cnt[p][i] := cnt[v][1] + cnt[v][2];
        inc(nc[p]);
        for j := nc[p] downto i + 2 do
        begin
            chd[p][j] := chd[p][j - 1];
            cnt[p][j] := cnt[p][j - 1];
        end;
        chd[p][i + 1] := vcount;
        cnt[p][i + 1] := cnt[vcount][1] + cnt[vcount][2];
    end else begin
        inc(cnt[p][i]);
    end;
end;

procedure insert(x, v: longint);
begin
    value := v;
    if root = 0 then
    begin
        inc(vcount);
        nc[vcount] := 1;
        root := vcount;
        inc(vcount);
        nc[vcount] := 0;
        chd[root][1] := vcount;
        cnt[root][1] := 1;
        vl[vcount] := v;
    end else begin
        doinsert(root, x, 0, 1);
    end;
end;

procedure print(x: integer);
var
    i: longint;
begin
    write('(', x, ' ', nc[x]);
    for i := 1 to nc[x] do
    begin
        write(' ');
        print(chd[x][i]);
        write(',', cnt[x][i], ' ');
    end;
    write(')');
end;

procedure outp(x: integer);
var
    i: longint;
begin
    for i := 1 to nc[x] do
    begin
        outp(chd[x][i]);
    end;
    if nc[x] = 0 then
        write(vl[x], ' ');
end;

procedure expand(x: integer);
var
    i: longint;
begin
    for i := 1 to nc[x] do
    begin
        expand(chd[x][i]);
    end;
    if nc[x] = 0 then
    begin
        inc(num);
        ans[num] := vl[x];
    end;
end;

procedure sort(l, r: longint);
var
    i, j, t, x: longint;
begin
    i := l;
    j := r;
    x := a[l + random(r - l + 1)];
    while i <= j do
    begin
        while a[i] < x do inc(i);
        while a[j] > x do dec(j);
        if i <= j then
        begin
            t := a[i]; a[i] := a[j]; a[j] := t;
            t := b[i]; b[i] := b[j]; b[j] := t;
            inc(i);
            dec(j);
        end;
    end;
    if l < j then sort(l, j);
    if i < r then sort(i, r);
end;

procedure siftup(i: longint);
var
    t: tpair;
begin
    while (i > 1) and (heap[i].k < heap[i div 2].k) do
    begin
        t := heap[i]; heap[i] := heap[i div 2]; heap[i div 2] := t;
        i := i div 2;
    end;
end;

procedure siftdown(i: longint);
var
    j: longint;
    t: tpair;
begin
    while 2 * i <= hn do
    begin
        j := i;
        if heap[2 * i].k < heap[j].k then
            j := 2 * i;
        if (2 * i + 1 <= hn) and (heap[2 * i + 1].k < heap[j].k) then
            j := 2 * i + 1;
        if i = j then break;
        t := heap[i]; heap[i] := heap[j]; heap[j] := t;
        i := j;
    end;
end;

procedure heapins(l, k: longint);
begin
    inc(hn);
    heap[hn].l := l;
    heap[hn].k := k;
    siftup(hn);
end;

procedure heapmin(var l, k: longint);
begin
    if hn = 0 then runerror(240);
    l := heap[1].l;
    k := heap[1].k;
    heap[1] := heap[hn];
    dec(hn);
    siftdown(1);
end;

var 
    n, m, i, j, k, l, r: longint;

begin
    assign(input, 'key.in');
    reset(input);
    assign(output, 'key.out');
    rewrite(output);

    read(n, m);
    if (n < 1) or (n > maxn) or (m < 1) or (m > maxm) then
        runerror(239);

    for i := 1 to n do
    begin
        read(a[i]);
        if (a[i] < 1) or (a[i] > m) then
            runerror(239);
        inc(s[a[i]]);
        b[i] := i;
    end;

    r := 0;
    j := 0;
    for i := 1 to n + m do
    begin
        dec(r);
        if r < 0 then
        begin
            r := 0;
            j := i;
        end;
        p[i] := j;
        r := r + s[i];
    end;

    sort(1, n);

    i := 1;
    while i <= n do
    begin
        j := a[i];
        root := 0;
        vcount := 0;
        r := 0;
        hn := 0;
        while ((i <= n) and (p[a[i]] = j)) or (hn > 0) do
        begin
            while (i <= n) and (a[i] <= j + r) do
            begin
                heapins(a[i], b[i]);
                inc(i);
            end;
            heapmin(l, k);
            insert(l - j, k);
            inc(r);
        end;
        num := j - 1;
        expand(root);
    end;
    writeln(num);
    for k := 1 to num do
        write(ans[k], ' ');

    close(input);
    close(output);
end.