uses
	Sysutils;

const
	d1 = 100;
	d2 = 50;
	dd = 49;
	pi = 3.1415926;

var
	n1, n2 : integer;
	i : integer;
	a, b : real;

begin
	if paramcount <> 2 then
		halt;
	n1 := strtoint(paramstr(1));
	n2 := strtoint(paramstr(2));
	writeln(n1 + n2);
	writeln(dd, ' ', 0, ' ', -dd, ' ', 0, ' 50 1');
	for i := 1 to n1 do begin
		a := pi / (n1 + 2) * i;
		b := pi / (n1 + 2) * (i + 1);
		writeln(d1 * cos(a):0:3, ' ', d1 * sin(a):0:3, ' ', d1 * cos(b):0:3, ' ', d1 * sin(b):0:3, ' 0 0');
	end;
	for i := 1 to n2 do begin
		a := pi / (n2 + 2) * i;
		b := pi / (n2 + 2) * (i + 1);
		writeln(d2 * cos(a):0:3, ' ', d2 * sin(a):0:3, ' ', d1 * cos(b):0:3, ' ', d2 * sin(b):0:3, ' 0 0');
	end;
end.
