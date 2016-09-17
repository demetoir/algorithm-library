uses
	Sysutils;

var
	n : integer;
	i : integer;

begin
	if paramcount <> 1 then
		halt;
	n := strtoint(paramstr(1));
	writeln(n);
	writeln('-990 0.4 996 0.3 5 1');
	for i := 1 to n do
		writeln('-999 ', random(1000)/1000:0:3, ' 999 ', random(1000)/1000:0:3, ' ', random(100)/100:0:3, ' ', random(100)/100:0:3);
end.
