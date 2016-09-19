uses
	Sysutils;

const
	d = 100;
	dd = 99;
	pi = 3.1415926;

var
	n : integer;
	i : integer;
	a, b : real;

begin
	if paramcount <> 1 then
		halt;
	n := strtoint(paramstr(1));
	writeln(n);
	writeln(dd, ' ', 0, ' ', -dd, ' ', 0, ' 50 1');
	for i := 1 to n do begin
		a := pi / (n + 2) * i;
		b := pi / (n + 2) * (i + 1);
		writeln(d * cos(a):0:3, ' ', d * sin(a):0:3, ' ', d * cos(b):0:3, ' ', d * sin(b):0:3, ' 0 0');
	end;
end.
