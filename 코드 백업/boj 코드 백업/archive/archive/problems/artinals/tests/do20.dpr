{$Q+,R+,O+}
const MaxL=250;  N=4;  M=24;
  Comm = 'Permutation group on four objects; permutations encoded by 0..23';
type subst = array [1..4] of byte;

var g : string; c : char;
function pair (a, b : string) : string; 
begin pair := '{{'+a+'},{'+a+','+b+'}}' end;
function tripl (a, b, c : string) : string;
begin tripl := pair (pair (a, b), c) end;
function i2s (i : integer) : string;
begin str (i, Result) end;
procedure add (t : string);
begin
  if g = '' then g := c+':={'+t else
  if (length(g)+length(t) > MaxL - 2) then begin
    writeln (g+'}');  g := c+':='+c+'+{'+t
  end else g := g + ',' + t;
end;
procedure addp (a, b : integer);
begin add (pair (i2s(a), i2s(b))) end;
procedure addt (a, b, c : integer);
begin add (tripl (i2s(a), i2s(b), i2s(c))) end;
procedure flush;
begin if g <> '' then writeln (g + '}');  g := '' end;

var X : array [1..M] of subst;
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
  for i := 1 to M do
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


var i, j : integer;  
begin
  randseed := 20;  writeln ('# ' + Comm);
  T := 0;  rec (1);  assert (T = M);
  for i := 1 to M do begin j := random(i)+1;  
    Y := X[i];  X[i] := X[j];  X[j] := Y end;
  for i := 1 to M do begin j := random(i)+1;  Z[i]:=Z[j];  Z[j]:=i end;
  c := 'M';
  for i := 1 to M do
    for j := 1 to M do addt (Z[i], Z[j], compos (X[Z[i]], X[Z[j]]));
  flush;  c := 'I';
  for i := 1 to M do
    addp (Z[i], inv (X[Z[i]]));
  flush;
  writeln ('G:='+pair('M',pair('I',i2s(one))));
  writeln ('!M');
  writeln ('!I');
  writeln ('!G');
end.
