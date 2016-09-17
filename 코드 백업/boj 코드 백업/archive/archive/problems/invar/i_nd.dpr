program macro;
const MaxN=999; MaxD=999; MultiTest=true;
var n, d, i, u, v, S : integer;
begin
  assign (input, 'invar.in');  reset (input);
  assign (output, 'invar.out');  rewrite (output);
  repeat
    read (d, n);
    if (d <= 0) or (n <= 0) or (d > MaxD) or (n > MaxN) then runerror (239);
    u := 0;  v := d div n;  S := 0;
    for i := 0 to d do begin
      if (u - 1) * n = -i then dec (u);
      while v * n > d - 2 * i do dec (v);
      if u <= v then inc (S, v - u + 1);
    end;
    writeln (S)
  until seekeof or not MultiTest
end.
