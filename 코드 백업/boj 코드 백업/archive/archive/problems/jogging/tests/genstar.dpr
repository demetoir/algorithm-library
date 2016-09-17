uses
	Sysutils;

const
	d = 100;
	dd = 120;
	pi = 3.1415926;

var
	n : integer;
	i : integer;
	a : real;

begin
	if paramcount <> 1 then
		halt;
	n := strtoint(paramstr(1));
	writeln(n);
	writeln(dd, ' ', dd, ' ', -dd, ' ', 0, ' 50 1');
	for i := 1 to n do begin
		a := pi / (n + 2) * i;
		writeln(random(10)/10:0:3, ' ', random(10)/10:0:3, ' ', d * cos(a):0:3, ' ', d * sin(a):0:3, ' 0.2 0.4');
	end;
end.
