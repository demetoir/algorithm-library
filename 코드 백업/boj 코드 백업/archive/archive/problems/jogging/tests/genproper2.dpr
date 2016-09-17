uses
	Sysutils;

const
	dx1 = 149;
	dy1 = 100;
	d2 = 99;
	dd = 150;
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
	writeln(dd, ' ', -dy1/3:0:3, ' ', -dd, ' ', -dy1/3:0:3, ' 50 1');
	for i := 1 to n1 do begin
		a := pi / (n1 + 1) * i;
		b := pi / (n1 + 1) * (i + 1);
		writeln(dx1 * cos(a):0:3, ' ', dy1 * sin(a):0:3, ' ', dx1 * cos(b):0:3, ' ', dy1 * sin(b):0:3, ' 0 0');
	end;
	for i := 10 to n2 + 10 do begin
		a := pi / (n2 + 20) * i;
		b := pi / (n2 + 20) * (i + 1);
		writeln(d2 * cos(a):0:3, ' ', d2 * sin(a):0:3, ' ', d2 * cos(b):0:3, ' ', d2 * sin(b):0:3, ' 0 0');
	end;
end.
