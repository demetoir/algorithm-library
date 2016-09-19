{-----------------------------------------------------------}
{ ACM ICPC 2003-2004                                        }
{ Northeastern European Region                              }
{ Northern Subregional Contest                              }
{                                                           }
{ Problem A. Artinals                                       }
{ Author: Nick Dourov                                       }
{ Solution: Georgiy Korneev                                 }
{-----------------------------------------------------------}

{$Q+,R+,O+}
{$APPTYPE CONSOLE}
uses
    sysutils, math;

const
    max_l = 4096;
    max_h = 568913;
    max_o = 512; // Number of ordinals
    max_o1 = 1100; // Number of ordinals

type
    partinal = ^tartinal;
    tartinal = record
        l, r: partinal;
        s, h: longint;
        v: longint;
    end;

type
    plist = ^tlist;
    tlist = record
        n: plist;
        a: partinal;
    end;

type
    artinal = partinal;
    artinals = array of partinal;
var
    lp: array [0..max_l] of longint;
    ZERO: partinal;
    hlist: array [0..max_h] of plist;
    cNodes: longint;
    ordinals: artinals;

function size(a: partinal): longint;
begin
    if a = nil then begin
        result := 0;
    end else begin
        result := a.s;
    end;
end;

function hash(a: partinal): longint;
begin
    if a = nil then begin
        result := 0;
    end else begin
        result := a.h;
    end;
end;

function createNode(l, r: partinal; s, h: longint): partinal;
begin
    inc(cNodes);
    new(result);
    result.l := l;
    result.r := r;
    result.s := s;
    result.h := h;
    result.v := -1;
end;

function getNode(l, r: partinal; s: longint): partinal;
var
    p: plist;
    h: longint;
begin
    h := (hash(l) * 13 + hash(r) * 257) mod max_h;
    p := hlist[h];
    while p <> nil do begin
        if (p.a.l = l) and (p.a.r = r) then begin
            result := p.a;
            exit;
        end;
        p := p.n;
    end;
    result := createNode(l, r, s, h);

    p := hlist[h];
    new(hlist[h]);
    hlist[h].n := p;
    hlist[h].a := result;
end;

function pack(var a: artinals; l, r: longint): partinal;
begin
    case r - l of
         0: result := ZERO;
         1: result := getNode(a[l], nil, 1);
         else result := getNode(pack(a, l, l + lp[r - l]), pack(a, l + lp[r - l], r), r - l);
    end;
end;

procedure unpack(var q: artinals; a: artinal; l: longint); overload;
begin
    if a.s = 0 then begin
    end else if a.s = 1 then begin
        q[l] := a.l;
    end else begin
        unpack(q, a.l, l);
        unpack(q, a.r, l + a.l.s);
    end;
end;

function unpack(a: artinal): artinals; overload;
begin
    setLength(result, a.s);
    unpack(result, a, low(result));
end;

procedure print(a: artinal);
var
    i: longint;
    q: artinals;
begin
    if a.v < 0 then begin
        q := unpack(a);
        write('{');
        for i := low(q) to high(q) do begin
            if i <> low(q) then write(',');
            print(q[i]);
        end;
        write('}');
    end else begin
        write(a.v);
    end;
end;

const
    alpha: set of char = ['a'..'z', 'A'..'Z', '0'..'9', '_'];

type
    pnode = ^tnode;
    tnode = record
        a: artinal;
        v: array ['0'..'z'] of pnode;
    end;

var
    vars: pnode;

var
    s: string;
    pos: longint;
    token: string;

procedure setVar(s: string; a: artinal);
var
    i: longint;
    p: ^pnode;
begin
    p := addr(vars);
    for i := 1 to length(s) do begin
        if p^ = nil then begin
            new(p^);
            fillchar(p^^, sizeof(p^^), 0);
        end;
        p := addr(p^.v[s[i]]);
    end;
    if p^ = nil then begin
        new(p^);
        fillchar(p^^, sizeof(p^^), 0);
    end;
    p^.a := a;
end;

function getVar(s: string): artinal;
var
    i: longint;
    p: pnode;
begin
    p := vars;
    for i := 1 to length(s) do begin
        if p = nil then begin
            break;
        end;
        p := p.v[s[i]];
    end;
    if p <> nil then begin
        result := p.a;
    end else begin
        result := ZERO;
    end;
end;

procedure nextToken();
begin
    while s[pos] <= ' ' do begin
        inc(pos);
    end;
    case s[pos] of
        '*', '+', '^', '(', ')', '{', '}', ',', '=', '!', '?', '#', '|':
            begin
                token := s[pos];
            end;
        ':':
            begin
                if s[pos + 1] = '=' then begin
                    token := ':=';
                    inc(pos);
                end;
            end;
        '-':
            begin
                if s[pos + 1] = '>' then begin
                    token := '->';
                    inc(pos);
                end else begin
                    token := '-';
                end;
            end;
        '<':
            begin
                if s[pos + 1] in ['=', '>', '-', '<'] then begin
                    inc(pos);
                    token := '<' + s[pos];
                end else begin
                    token := '<';
                end;
            end;
        '>':
            begin
                if s[pos + 1] in ['=', '>'] then begin
                    inc(pos);
                    token := '>' + s[pos];
                end else begin
                    token := '>';
                end;
            end;
        else begin
            token := '';
            while s[pos] in alpha do begin
                token := token + s[pos];
                inc(pos);
            end;
            dec(pos);
        end;
    end;
    if token <> '|' then begin
        inc(pos);
    end;
end;

procedure setLine(line: string);
begin
    s := line + '|';
    pos := 1;
    nextToken();
end;

procedure expect(e: string);
begin
    if e <> token then begin
        writeln(s);
        writeln('':pos - length(token), '^');
        writeln('Expected "', e , '" instead of "',  token, '"');
        halt(0);
    end;
    nextToken();
end;

function test(s: string): boolean;
begin
    if s = token then begin
        test := true;
        nextToken();
    end else begin
        test := false;
    end;
end;

function compare(a1, a2: artinal): longint;
var
    ta: artinal;
begin
    if a1 = a2 then begin
        result := 0;
    end else if (a1.v >= 0) and (a2.v >= 0) then begin
        if a1.v > a2.v then begin
            result := 1;
        end else begin
            result := -1;
        end;
    end else if (a1 = nil) or (a1.s = 0) then begin
        compare := -1
    end else if (a2 = nil) or (a2.s = 0) then begin
        compare := 1;
    end else if a1.s > a2.s then begin
        compare := -compare(a2, a1);
    end else begin
        //write('compare '); print(a1); write(' ---- '); print(a2); writeln;
        ta := a2;
        while (a1.s < ta.s) and (a1.s <= ta.l.s) do begin
            ta := ta.l;
        end;
        result := compare(a1.l, ta.l);
        if result = 0 then begin
            result := compare(a1.r, ta.r);
            if result = 0 then begin
                result := -1;
            end;
        end;
        //print(a1); write('  ', result, '  '); print(a2); writeln;
    end;
end;

function belongs(a1, a2: artinal): boolean;
var
    q: artinals;
    i: longint;
begin
    q := unpack(a1);
    for i := low(q) to high(q) do begin
        if compare(q[i], a2) = 0 then begin
            result := true;
            exit;
        end;
    end;
    result := false;
end;


function sdiff(a1, a2: artinal): artinal;
var
    q1, q2, q3: artinals;
    i1, i2, i3: longint;
begin
    q1 := unpack(a1);
    q2 := unpack(a2);
    setLength(q3, a1.s + a2.s);

    i2 := low(q2);
    i3 := low(q3);
    for i1 := low(q1) to high(q1) do begin
        while (i2 <= high(q2)) and (compare(q1[i1], q2[i2]) > 0) do begin
            q3[i3] := q2[i2];
            inc(i3);
            inc(i2)
        end;
        if (i2 <= high(q2)) and (compare(q1[i1], q2[i2]) = 0) then begin
            inc(i2);
        end else begin
            q3[i3] := q1[i1];
            inc(i3);
        end;
    end;
    while (i2 <= high(q2)) do begin
        q3[i3] := q2[i2];
        inc(i3);
        inc(i2)
    end;
    result := pack(q3, low(q3), i3);
end;

function diff(a1, a2: artinal): artinal;
var
    q1, q2, q3: artinals;
    i1, i2, i3: longint;
begin
    q1 := unpack(a1);
    q2 := unpack(a2);
    setLength(q3, a1.s);

    i2 := low(q2);
    i3 := low(q3);
    for i1 := low(q1) to high(q1) do begin
        while (i2 <= high(q2)) and (compare(q1[i1], q2[i2]) > 0) do begin
            inc(i2)
        end;
        if (i2 <= high(q2)) and (compare(q1[i1], q2[i2]) = 0) then begin
            inc(i2);
        end else begin
            q3[i3] := q1[i1];
            inc(i3);
        end;
    end;
    result := pack(q3, low(q3), i3);
end;

function union(a1, a2: artinal): artinal;
var
    q1, q2, q3: artinals;
    i1, i2, i3: longint;
begin
    if a1 = a2 then begin
        result := a1;
    end else if (a1.v >= 0) and (a2.v >= 0) then begin
        if a1.v > a2.v then begin
            result := a1;
        end else begin
            result := a2;
        end;
    end else begin
        q1 := unpack(a1);
        q2 := unpack(a2);
        setLength(q3, a1.s + a2.s);

        i2 := low(q2);
        i3 := low(q3);
        for i1 := low(q1) to high(q1) do begin
            while (i2 <= high(q2)) and (compare(q1[i1], q2[i2]) > 0) do begin
                q3[i3] := q2[i2];
                inc(i3);
                inc(i2)
            end;
            if (i2 <= high(q2)) and (compare(q1[i1], q2[i2]) = 0) then begin
                inc(i2);
            end;
            q3[i3] := q1[i1];
            inc(i3);
        end;
        while (i2 <= high(q2)) do begin
            q3[i3] := q2[i2];
            inc(i3);
            inc(i2)
        end;
        result := pack(q3, low(q3), i3);
    end;
end;

function intersection(a1, a2: artinal): artinal;
var
    q1, q2, q3: artinals;
    i1, i2, i3: longint;
begin
    if a1 = a2 then begin
        result := a1;
    end else if (a1.v >= 0) and (a2.v >= 0) then begin
        if a1.v > a2.v then begin
            result := a2;
        end else begin
            result := a1;
        end;
    end else begin
        q1 := unpack(a1);
        q2 := unpack(a2);
        setLength(q3, min(a1.s, a2.s));

        i2 := low(q2);
        i3 := low(q3);
        for i1 := low(q1) to high(q1) do begin
            while (i2 <= high(q2)) and (compare(q1[i1], q2[i2]) > 0) do begin
                inc(i2)
            end;
            if (i2 <= high(q2)) and (compare(q1[i1], q2[i2]) = 0) then begin
                q3[i3] := q1[i1];
                inc(i3);
                inc(i2);
            end;
        end;
        result := pack(q3, low(q3), i3);
    end;
end;

function subset(a1, a2: artinal): boolean;
begin
    result := compare(intersection(a1, a2), a2) = 0;
end;

function uunion(a: artinal): artinal;
var
    q: artinals;
    i: longint;
    s: longint;
begin
    if a.v >= 0 then begin
        if a.v = 0 then begin
            result := a;
        end else begin
            result := ordinals[a.v - 1];
        end;
    end else if a.s = 0 then begin
        result := a;
    end else if a.s = 1 then begin
        result := a.l;
    end else begin
        q := unpack(a);
        s := a.s;
        while s > 1 do begin
            for i := 0 to s div 2 - 1 do begin
                q[i + low(q)] := union(q[2 * i + low(q)], q[2 * i + 1 + low(q)]);
            end;
            if s mod 2 = 1 then begin
                q[s div 2 + low(q)] := q[s - 1 + low(q)];
            end;
            s := (s + 1) div 2;
        end;
        uunion := q[low(q)];
    end;
end;

function uintersection(a: artinal): artinal;
var
    q: artinals;
    i: longint;
begin
    q := unpack(a);
    result := q[low(q)];
    for i := low(q) + 1 to high(q) do begin
        result := intersection(result, q[i]);
    end;
end;

function parseXor(): artinal; forward;

function parseCommas: artinal;
var
    q: artinals;
    a: artinal;
    i, j, k: longint;
begin
    if not test('}') then begin
        setLength(q, 2);
        q[low(q)] := parseXor();
        i := 1;
        while test(',') do begin
            a := parseXor();
            j := 0;
            while (j < i) and (compare(q[j], a) < 0) do begin
                inc(j);
            end;
            if (j >= i) or (compare(q[j], a) > 0) then begin
                if i >= length(q) then begin
                    setLength(q, i * 2);
                end;
                for k := i downto j + 1 do begin
                    q[k] := q[k - 1];
                end;
                q[j] := a;
                inc(i);
            end;
        end;
        expect('}');
        result := pack(q, low(q), i);
    end else begin
        result := ZERO;
    end;
end;

function parseTerm(): artinal;
begin
    if test('{') then begin
        result := parseCommas();
    end else if test('(') then begin
        result := parseXor();
        expect(')');
    end else if test('+') then begin
        result := uunion(parseTerm());
    end else if test('*') then begin
        result := uintersection(parseTerm());
    end else begin
        if not (token[1] in alpha) then begin
            expect('var');
        end;
        result := getVar(token);
        nextToken();
    end;
end;

function parseIntersection(): artinal;
begin
    result := parseTerm();
    while test('*') do begin
        result := intersection(result, parseTerm());
    end;
end;

function parseUnion(): artinal;
begin
    result := parseIntersection();
    while test('+') do begin
        result := union(result, parseIntersection());
    end;
end;

function parseDifference(): artinal;
begin
    result := parseUnion();
    while test('-') do begin
        result := diff(result, parseUnion());
    end;
end;

function parseXor(): artinal;
begin
    result := parseDifference();
    while test('^') do begin
        result := sdiff(result, parseDifference());
    end;
end;

function parseExpression(): artinal;
begin
    parseExpression := parseXor();
end;

procedure parseCondition();
var
    a1, a2: artinal;
    c: string;
begin
    a1 := parseExpression();
    c := token;
    nextToken();
    a2 := parseExpression();
    //print(a1); write(' ----- ', c, ' ----- '); print(a2); writeln;
    if c = '>' then begin
        writeln(compare(a1, a2) > 0);
    end else if c = '<' then begin
        writeln(compare(a1, a2) < 0);
    end else if c = '<=' then begin
        writeln(compare(a1, a2) <= 0);
    end else if c = '>=' then begin
        writeln(compare(a1, a2) >= 0);
    end else if c = '=' then begin
        writeln(compare(a1, a2) = 0);
    end else if c = '<>' then begin
        writeln(compare(a1, a2) <> 0);
    end else if c = '->' then begin
        writeln(belongs(a2, a1));
    end else if c = '<-' then begin
        writeln(belongs(a1, a2));
    end else if c = '>>' then begin
        writeln(subset(a1, a2));
    end else if c = '<<' then begin
        writeln(subset(a2, a1));
    end;
end;

procedure parseAssignment();
var
    v: string;
begin
    v := token;
    nextToken();
    expect(':=');
    setVar(v, parseExpression());
    //write(v, ' = '); print(getVar(v)); writeln;
end;

var
    line: string;

procedure parseLine();
begin
    if test('#') then begin
        writeln(line);
    end else if test('|') then begin
    end else if test('!') then begin
        print(parseExpression());
        writeln;
    end else if test('?') then begin
        parseCondition();
    end else begin
        parseAssignment();
    end;
end;

procedure initLp();
var
    i, j: longint;
begin
    i := 1;
    j := 1;
    while i * 2 <= max_l do begin
       while j <= i * 2 do begin
           lp[j] := i;
           inc(j);
       end;
       i := i * 2;
    end;
end;

var
    i, j: longint;
    q: longint;
begin
    assign(input, 'artinals.in'); reset(input);
    assign(output, 'artinals.out'); rewrite(output);

    initLp();

    zero := createNode(nil, nil, 0, 239);
    setlength(ordinals, max_o1 + 1);
    ordinals[0] := zero;
    ordinals[0].v := 0;
    for i := 1 to max_o do begin
        ordinals[i] := pack(ordinals, 0, i);
        ordinals[i].v := i;
        setVar(inttostr(i), ordinals[i]);
    end;
    for i := max_o to max_o1 do begin
        ordinals[i] := pack(ordinals, 0, i);
        ordinals[i].v := i;
    end;
    //writeln(cNodes);

    {
    for i := 0 to 20 do begin
        for j := 0 to 20 do begin
            write(compare(ordinals[i], ordinals[j]):3);
        end;
        writeln;
    end;
    }

    {
    for i := 0 to 5 do begin
        print(getVar(inttostr(i))); writeln;
    end;
    }

    while not eof do begin
        readln(line);
        setLine(line);
        //writeln(line);
        parseLine();
        //writeln('nodes=', cNodes);
    end;

    close(input);
    close(output);
end.