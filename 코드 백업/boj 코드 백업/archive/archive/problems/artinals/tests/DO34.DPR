var maxdef:integer;

procedure recdef (l:integer);
begin
  if l<=maxdef then write (l) else begin
    recdef (l-1); write ('+{'); recdef (l-1); write ('}');
  end;
end;


var i:integer;


begin
  maxdef:=512;
  for i:=1 to 99 do begin
    write (512+i*5, ':='); recdef (512+i*5); writeln; maxdef:=512+i*5;
  end;
  write ('!'); recdef (1012); writeln;
end.