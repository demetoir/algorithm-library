{$Q+,R+,O+}
const MaxL=250;  N=6;  F=720;  M=16;
  Comm = 'Sylow 2-subgroup of the permutation group on {1,2,3,4,5,6}';
type subst = array [1..N] of integer;
     sarr = array [1..4] of subst;
const Gen : sarr = ((1,2,3,4,6,5),(2,1,3,4,5,6),(1,2,4,3,5,6),(3,4,1,2,5,6));

var g : string; c : char;
function pair (a, b : string) : string; 
begin pair := '{{'+a+'},{'+a+','+b+'}}' end;
function tripl (a, b, c : string) : string;
begin tripl := pair (pair (a, b), c) end;
function i2s (i : integer) : string;
begin str (i, Result) end;
function i2q (i : integer) : string;
begin i2q:='e'+i2s(i) end;
procedure add (t : string);
begin
  if g = '' then g := c+':={'+t else
  if (length(g)+length(t) > MaxL - 2) then begin
    writeln (g+'}');  g := c+':='+c+'+{'+t
  end else g := g + ',' + t;
end;
procedure addp (a, b : integer);
begin add (pair (i2q(a), i2q(b))) end;
procedure addt (a, b, c : integer);
begin add (tripl (i2q(a), i2q(b), i2q(c))) end;
procedure flush;
begin if g <> '' then writeln (g + '}');  g := '' end;

function tuple (const a : array of integer; u, v : integer) : string;
begin
  if u = v then tuple := i2s(a[u])
  else tuple := pair (i2s(a[u]), tuple (a, u+1, v))
end;

function tuplen (const a : array of integer) : string;
begin tuplen := tuple (a, low(a), high(a)) end;

var X : array [1..F] of subst;
    XF : array [1..F] of integer;
    Z : array [1..M] of integer;
    T : integer;
    Y, S : subst;

procedure rec (p : integer);
var i : integer;
begin
  if p > N then begin inc(T); X[T]:=Y; exit end;
  for i := 1 to N do if S[i] = 0 then 
    begin S[i]:=p;  Y[p]:=i;  rec(p+1);  S[i]:=0 end
end;

function src (const Y : subst) : integer;
var i, j : integer;
begin
  for i := 1 to F do
    for j := 1 to N + 1 do
      if j > N then begin src := i;  exit end
      else if X[i,j] <> Y[j] then break;
  assert(false); src:=-1
end;

function compos (const U, V : subst) : integer;
var i : integer;  W : subst;
begin
  for i := 1 to N do W[i] := U[V[i]];
  compos := src(W)
end;

function inv (const U : subst) : integer;
var i : integer;  W : subst;
begin
  for i := 1 to N do W[U[i]] := i;
  inv := src(W)
end;

function one : integer;
var i : integer;  W : subst;
begin
  for i := 1 to N do W[i] := i;
  one := src(W)
end;


var i, j, k : integer;  F0 : boolean;
begin
  randseed := 22;  writeln ('# ' + Comm);
  T := 0;  rec (1);  assert (T = F);
  XF[1] := 2;  T := 0;
  repeat
    F0 := true;
    for i := 1 to F do if XF[i] = 2 then begin
      F0 := false;  XF[i] := 1;  inc (T);
      for k := low(Gen) to high (Gen) do begin
        j := compos (X[i], Gen[k]);
        if XF[j] = 0 then XF[j] := 2
      end
    end
  until F0;
  assert (T = M);
  j := 1;
  for i := 1 to F do if XF[i] <> 0 then begin X[j]:=X[i]; inc(j) end;
  for i := 1 to M do begin j := random(i)+1;  
    Y := X[i];  X[i] := X[j];  X[j] := Y end;
  for i := 1 to M do begin j := random(i)+1;  Z[i]:=Z[j];  Z[j]:=i end;
  for i := 1 to M do writeln (i2q(i), ':=', tuplen (X[i]));
  c := 'M';
  for i := 1 to M do
    for j := 1 to M do addt (Z[i], Z[j], compos (X[Z[i]], X[Z[j]]));
  flush;  c := 'I';
  for i := 1 to M do
    addp (Z[i], inv (X[Z[i]]));
  flush;
  writeln ('G:='+pair('M',pair('I',i2q(one))));
  writeln ('!M');
  writeln ('!I');
  writeln ('!G');
end.
