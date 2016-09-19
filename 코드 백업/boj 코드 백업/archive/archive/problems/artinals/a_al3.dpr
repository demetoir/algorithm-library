{$O+,Q-,R-}
uses math, sysutils;

type partinal=^tartinal;
     tartinal=record
       d:array of partinal;
       n:integer;
     end;

var numbers:array [0..1024] of partinal;

function compare (a, b:partinal):integer;
var i:integer;
begin
  if b=nil then
    writeln (longint (a), ' ', longint (b));
  flush (output);
  if (a.n>=0) and (b.n>=0) then begin
    if a.n>b.n then Result:=1 else
    if a.n<b.n then Result:=-1 else
    Result:=0;
  end else begin
    for i:=0 to min (high (a.d), high (b.d)) do begin
      Result:=compare (a.d[i], b.d[i]);
      if Result<>0 then exit;
    end;
    if length (a.d)>length (b.d) then Result:=1 else
    if length (a.d)<length (b.d) then Result:=-1 else
    Result:=0;
  end;
end;


function binary_intersection (a, b:partinal):partinal;
var r:partinal;
    i, j, l, im, jm:integer;
begin
  if (a.n>=0) and (b.n>=0) then begin
    if a.n>b.n then Result:=b else Result:=a;
  end else begin
    i:=0; j:=0; l:=0; im:=high (a.d); jm:=high (b.d);
    new (r); r.n:=-1; setlength (r.d, max (length (a.d), length (b.d)));
    while (i<=im) and (j<=jm) do
      case compare (a.d[i], b.d[j]) of
        -1:inc (i);
         1:inc (j);
         0:begin
           r.d[l]:=a.d[i];
           inc (i); inc (j); inc (l)
         end;
      end;
    setlength (r.d, l);
    if compare (r, numbers[l])=0 then Result:=numbers[l] else Result:=r;
  end;
end;


function binary_union (a, b:partinal):partinal;
var r:partinal;
    i, j, l, im, jm:integer;
begin
  if (a.n>=0) and (b.n>=0) then begin
    if a.n>b.n then Result:=a else Result:=b;
  end else begin
    i:=0; j:=0; l:=0; im:=high (a.d); jm:=high (b.d);
    new (r); r.n:=-1; setlength (r.d, length (a.d)+length (b.d));
    while (i<=im) and (j<=jm) do 
      case compare (a.d[i], b.d[j]) of
        -1:begin r.d[l]:=a.d[i]; inc (i); inc (l) end;
         0:begin r.d[l]:=a.d[i]; inc (i); inc (j); inc (l) end;
         1:begin r.d[l]:=b.d[j]; inc (j); inc (l) end;
      end;
    while (i<=im) do begin r.d[l]:=a.d[i]; inc (i); inc (l) end;
    while (j<=jm) do begin r.d[l]:=b.d[j]; inc (j); inc (l) end;
    setlength (r.d, l);
    if compare (r, numbers[l])=0 then Result:=numbers[l] else Result:=r;
  end;
end;


function binary_difference (a, b:partinal):partinal;
var r:partinal;
    i, j, l, im, jm:integer;
begin
  i:=0; j:=0; l:=0; im:=high (a.d); jm:=high (b.d);
  new (r); r.n:=-1; setlength (r.d, length (a.d));
  while (i<=im) and (j<=jm) do 
    case compare (a.d[i], b.d[j]) of
      -1:begin r.d[l]:=a.d[i]; inc (i); inc (l) end;
       0:begin inc (i); inc (j) end;
       1:begin inc (j) end;
    end;
  while (i<=im) do begin r.d[l]:=a.d[i]; inc (i); inc (l) end;
  setlength (r.d, l);
  if compare (r, numbers[l])=0 then Result:=numbers[l] else Result:=r;
end;


function binary_symmetrical_difference (a, b:partinal):partinal;
var r:partinal;
    i, j, l, im, jm:integer;
begin
  i:=0; j:=0; l:=0; im:=high (a.d); jm:=high (b.d);
  new (r); r.n:=-1; setlength (r.d, length (a.d)+length (b.d));
  while (i<=im) and (j<=jm) do 
    case compare (a.d[i], b.d[j]) of
      -1:begin r.d[l]:=a.d[i]; inc (i); inc (l) end;
       0:begin inc (i); inc (j) end;
       1:begin r.d[l]:=b.d[j]; inc (j); inc (l) end;
    end;
  while (i<=im) do begin r.d[l]:=a.d[i]; inc (i); inc (l) end;
  while (j<=jm) do begin r.d[l]:=b.d[j]; inc (j); inc (l) end;
  setlength (r.d, l);
  if compare (r, numbers[l])=0 then Result:=numbers[l] else Result:=r;
end;


function unary_intersection (a:partinal):partinal;
var i:integer;
begin
  with a^ do begin
    assert (n<>0);
    if n>0 then Result:=numbers[0] else begin
      Result:=d[low (d)];
      for i:=low (d)+1 to high (d) do Result:=binary_intersection (Result, d[i]);
    end;
  end;
end;

function unary_union (a:partinal):partinal;
var i:integer;
begin
  with a^ do begin
    if n>0 then Result:=numbers[n-1] else 
    if n=0 then Result:=numbers[0] else begin
      Result:=d[low (d)];
      for i:=low (d)+1 to high (d) do Result:=binary_union (Result, d[i]);
    end;
  end;
end;


function element (a, b:partinal):boolean;
var i:integer;
begin
  for i:=low (b.d) to high (b.d) do
    if compare (a, b.d[i])=0 then begin
      Result:=true; exit
    end;
  Result:=false
end;


const Pr=17239;
var st:array [0..Pr-1] of string;
    val:array [0..Pr-1] of partinal;


function hash (const s:string):integer;
var i, h1, h2:integer;
begin
  h1:=0; h2:=0;
  for i:=1 to length (s) do begin
    h1:=h1*3+ord (s[i]); while h1>=Pr do dec (h1, Pr);
    h2:=h2*5+ord (s[i]); while h2>=Pr-1 do dec (h2, Pr-1);
  end;
  inc (h2);
  while (st[h1]<>'') and (st[h1]<>s) do begin
    inc (h1, h2); if h1>=Pr then dec (h1, Pr);
  end;
  if st[h1]='' then st[h1]:=s;
  Result:=h1;
end;


function getvar (const s:string):partinal;
begin
  Result:=val[hash (s)];
end;


procedure setvar (const s:string; value:partinal);
begin
  val[hash (s)]:=value;
end;


type tlex = (_var, _open, _close, _plus, _minus, _mul, _xor,
             _less, _gt, _eq, _leq, _geq, _neq, _in, _ni, _subset,
             _supset, _copen, _cclose, _sep, _assign, _end);


var curlex:tlex;
    s, cn:string;
    p:integer;


function getlex:tlex;
var cp:integer;
begin
  getlex:=curlex;
  case s[p] of
    #0:curlex:=_end;
    '(':curlex:=_open;
    ')':curlex:=_close;
    '{':curlex:=_copen;
    '}':curlex:=_cclose;
    ',':curlex:=_sep;
    '+':curlex:=_plus;
    '-':case s[p+1] of
          '>':curlex:=_in;
          else curlex:=_minus;
        end;
    '*':curlex:=_mul;
    '^':curlex:=_xor;
    '=':curlex:=_eq;
    '<':case s[p+1] of
          '<':curlex:=_subset;
          '>':curlex:=_neq;
          '=':curlex:=_leq;
          '-':curlex:=_ni;
          else curlex:=_less;
        end;
    '>':case s[p+1] of
          '>':curlex:=_supset;
          '=':curlex:=_geq;
          else curlex:=_gt;
        end;
    ':':case s[p+1] of
          '=':curlex:=_assign;
          else runerror (239);
        end;
    'A'..'Z', 'a'..'z', '0'..'9':begin
      cp:=p; repeat inc (p) until not (s[p] in ['A'..'Z', 'a'..'z', '0'..'9']);
      cn:=copy (s, cp, p-cp);
      curlex:=_var;
    end else runerror (239);
  end;
  if curlex in [_geq, _supset, _subset, _neq, _leq, _ni, _in, _assign] then
    inc (p, 2)
  else if not (curlex in [_end, _var]) then
    inc (p);
end;


procedure initlex;
begin
  p:=1; 
  getlex;
end;


const ops:array [0..3] of tlex = (_xor, _minus, _plus, _mul);


function expr (p:integer):partinal;
var left, right, tmp:partinal;
    i, j, l:integer;
begin
  Result:=nil;
  if p<4 then begin
    left:=expr (p+1);
    while curlex=ops[p] do begin
      getlex;
      right:=expr (p+1);
      case p of
        0:left:=binary_symmetrical_difference (left, right);
        1:left:=binary_difference (left, right);
        2:left:=binary_union (left, right);
        3:left:=binary_intersection (left, right);
      end;
    end;
    Result:=left;
  end else case p of
    4:if curlex=_plus then begin getlex; Result:=unary_union (expr (p)) end
      else Result:=expr (p+1);
    5:if curlex=_mul then begin getlex; Result:=unary_intersection (expr (p)) end
      else Result:=expr (p+1);
    6:case getlex of
        _open:begin Result:=expr (0); assert (getlex=_close) end;
        _var:Result:=getvar (cn);
        _copen:begin
          new (Result);
          with Result^ do begin
            setlength (d, 200); n:=-1;
            l:=0;
            if curlex<>_cclose then repeat
              d[l]:=expr (0); inc (l);
              if curlex=_cclose then break;
              assert (getlex=_sep);
            until false;
            getlex;
            setlength (d, l);
            for i:=1 to high (d) do
              for j:=high (d) downto i do
                if compare (d[j-1], d[j])>0 then
                  begin tmp:=d[j-1]; d[j-1]:=d[j]; d[j]:=tmp end;
            if length (d)>0 then begin
              l:=0;
              for i:=1 to high (d) do
                if compare (d[i], d[l])<>0 then
                  begin inc (l); d[l]:=d[i] end;
            end else l:=-1;
            inc (l);
            setlength (d, l);
          end;
          if compare (Result, numbers [l])=0 then Result:=numbers[l];
        end;
        else runerror (239);
      end;
    else runerror (239);
  end;
end;


procedure print (p:partinal);
var i:integer;
begin
  with p^ do
    if n>=0 then write (n) else begin
      write ('{');
      print (d[0]);
      for i:=1 to high (d) do begin write (','); print (d[i]) end;
      write ('}');
    end;
end;


var ss:string;
    i, j:integer;
    left, right:partinal;
    sign:tlex;

begin
  assign (input, 'artin.in'); reset (input);
  assign (output, 'artin.out'); rewrite (output);
  for i:=0 to 1024 do begin
    new (numbers [i]);
    with numbers[i]^ do begin
      setlength (d, i);
      for j:=0 to i-1 do d[j]:=numbers[j];
      n:=i;
    end;
    str (i, cn);
    if i<=512 then setvar (cn, numbers[i]);
  end;
  for i:=0 to Pr-1 do if val[i]=nil then val[i]:=numbers[0];
  repeat
    readln (s); ss:=s;  
    s:=stringreplace (s, #32, '', [rfReplaceAll]);
    s:=stringreplace (s, #9, '', [rfReplaceAll]);
    s:=s+#0;
    if s<>#0 then 
      case s[1] of
        '!':begin delete (s, 1, 1); initlex; print (expr (0)); writeln; assert (curlex=_end) end;
        '?':begin delete (s, 1, 1); initlex;
                  left:=expr (0);
                  sign:=getlex;
                  right:=expr (0);
                  assert (curlex=_end);
                  case sign of
                    _less:writeln (compare (left, right)<0);
                    _gt:writeln (compare (left, right)>0);
                    _leq:writeln (compare (left, right)<=0);
                    _geq:writeln (compare (left, right)>=0);
                    _neq:writeln (compare (left, right)<>0);
                    _eq:writeln (compare (left, right)=0);
                    _in:writeln (element (left, right));
                    _ni:writeln (element (right, left));
                    _subset:writeln (compare (left, binary_intersection (left, right))=0);
                    _supset:writeln (compare (right, binary_intersection (left, right))=0);
                  end;
            end;
        '#':writeln (ss);
        else begin
          initlex;
          assert (getlex=_var);
          ss:=cn;
          assert (getlex=_assign);
          setvar (ss, expr (0));
          assert (curlex=_end);
        end;
      end;
    flush (output);
  until eof;
end.