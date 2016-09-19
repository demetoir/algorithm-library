{$Q+,R+,O+}
program macro;
const MaxN=500;
var
  A, B, C  : array [0..MaxN, 0..MaxN] of integer;
  X, Y     : array [1..MaxN] of integer;
  N, M, i, j, k, L, u, v, p : integer;
begin
  assign (input, 'gcis.in');  reset (input);
  assign (output, 'gcis.out');  rewrite (output);
  read (N);  assert ((N > 0) and (N <= MaxN));
  for i := N downto 1 do read (X[i]);
  read (M);  assert ((M > 0) and (M <= MaxN));
  for j := M downto 1 do read (Y[j]);
  for i := 1 to N do begin
    p := 0;
    for j := 1 to M do begin A[i,j]:=p;  if X[i] = Y[j] then p := j end
  end;
  L := 0;  u := 0;  v := 0;
  for i := 1 to N do
    for j := 1 to M do if X[i] = Y[j] then begin
      B[i,j] := 1;  C[i,j] := 0;
      if L = 0 then begin L := 1;  u := i;  v := j end;
      for k := 1 to i - 1 do if X[k] > X[i] then begin
	p := A[k,j];  
	if (p > 0) and (B[k,p] >= B[i,j]) then begin
	  B[i,j] := B[k,p] + 1;  C[i,j] := k;
	  if B[i,j] > L then begin L := B[i,j];  u := i;  v := j end;
	end
      end
    end;
  writeln (L);
  while L > 0 do begin
    write (X[u]);  k := C[u,v];  v := A[k,v];  u := k;
    dec (L);  if L > 0 then write (' ') else writeln
  end
end.
