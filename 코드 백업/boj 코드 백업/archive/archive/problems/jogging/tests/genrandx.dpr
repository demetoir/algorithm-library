{$apptype console}

uses SysUtils;
var
	i, j, k, n : integer;
	x1, x2, y1, y2 : real;

	dx : array[1..4] of real = (1, 1, 1, -1);
	dy : array[1..4] of real = (0, 1, 1,  1);

function randcoord : real;
begin
	randcoord := random(10000000) / 1000 - 5000;
end;

function randt : real;
begin
	randt := random(10000) / 1000;
end;

function randv : real;
begin
	randv := 1 + random(99000) / 1000;
end;

begin
	if paramcount < 2 then
		halt;

	n := strtoint(paramstr(1));
	randseed := strtoint(paramstr(2));

	writeln(n);
	writeln(randcoord:0:3, ' ', randcoord:0:3, ' ', randcoord:0:3, ' ', randcoord:0:3, ' ', randv:0:3, ' ', randv:0:3);
	for i := 1 to n do begin
		x1 := randcoord;
		y1 := randcoord;
		j := random(4) + 1;
		k := random(5000);
		x2 := x1 + dx[j] * k;
		y2 := y1 + dy[j] * k;
		writeln(x1:0:3, ' ', y1:0:3, ' ', x2:0:3, ' ', y2:0:3, ' ', randt:0:3, ' ', randt:0:3);
	end;
end.
