{$apptype console}

uses SysUtils;
var
	i, n : integer;
	x1, x2, y1, y2 : real;

function randcoord : real;
begin
	randcoord := random(20000000) / 1000 - 10000;
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
		if random(2) = 0 then begin
			x1 := randcoord;
			y1 := randcoord;
			x2 := x1;
			y2 := randcoord;			
		end else begin
			x1 := randcoord;
			y1 := randcoord;
			x2 := randcoord;
			y2 := y1;
		end;
		writeln(x1:0:3, ' ', y1:0:3, ' ', x2:0:3, ' ', y2:0:3, ' ', randt:0:3, ' ', randt:0:3);
	end;
end.
