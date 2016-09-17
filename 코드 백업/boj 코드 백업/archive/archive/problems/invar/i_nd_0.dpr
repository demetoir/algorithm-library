program macro;
const MaxN=999; MaxD=999; MultiTest=true;
var n, d, x, y, S : integer;
begin
  assign (input, 'invar.in');  reset (input);
  assign (output, 'invar0.out');  rewrite (output);
  repeat
    read (d, n);
    if (d <= 0) or (n <= 0) or (d > MaxD) or (n > MaxN) then runerror (239);
    S := 0;
    for x := 0 to d do
      for y := 0 to d - x do
        if (x - y) mod n = 0 then inc (S);
    writeln (S)
  until seekeof or not MultiTest
end.
