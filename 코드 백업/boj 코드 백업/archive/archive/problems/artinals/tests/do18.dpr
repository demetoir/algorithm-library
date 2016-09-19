{$Q+,R+,O+}
const MaxL=250;  M=16;  Comm = 'Group (Z/2Z)^4';

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

var i, j : integer;  X : array [0..M-1] of integer;
begin
  randseed := 18;  writeln ('# ' + Comm);
  for i := 0 to M - 1 do begin j := random(i+1);  X[i] := X[j];  X[j] := i end;
  c := 'M';
  for i := 0 to M - 1 do
    for j := 0 to M - 1 do addt (X[i], X[j], X[i] xor X[j]);
  flush;  c := 'I';
  for i := 0 to M - 1 do
    addp (X[i], X[i]);
  flush;
  writeln ('G:='+pair('M',pair('I','0')));
  writeln ('!M');
  writeln ('!I');
  writeln ('!G');
end.
