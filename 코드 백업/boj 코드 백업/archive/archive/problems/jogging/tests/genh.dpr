{$apptype console}
uses
	Sysutils;

var
	i, j : integer;
	m, n : integer;

begin
	if paramcount <> 2 then
		halt;
	m := strtoint(paramstr(1));
	n := strtoint(paramstr(2));

	writeln(m * n);
	writeln('0 0 ', n * 100 + 77, ' ', m * 100 + 56, ' 10 1');
	for i := 1 to n do
		for j := 1 to m do
			writeln(i * 100, ' ', j * 100 + i, ' ', i * 100 + 78, ' ', j * 100 + i, ' 0.1 0.1');
end.
