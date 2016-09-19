{$ifdef VER70}
{$A+,B-,D+,E-,F-,G+,I+,L+,N+,O-,P-,Q+,R+,S+,T-,V-,X+,Y+}
{$M 65520,0,655360}
{$else}
{$A+,B-,C+,D+,E-,F-,G+,H+,I+,J+,K-,L+,M-,N+,O+,P-,Q+,R+,S-,T-,U-,V+,W-,X+,Y+,Z1}
{$MINSTACKSIZE $00004000}
{$MAXSTACKSIZE $00100000}
{$IMAGEBASE $00400000}
{$APPTYPE CONSOLE}
{$endif}
program macro;
uses testlib;
var jury, cont, count:integer;
begin
  count:=0;
  while not ans.seekeof do
    begin
      if ouf.seekeof then quit (_Wa, 'Неожиданный конец файла участника');
      ans.sp;
      jury:=ans.getint;
      cont:=ouf.getint;
      inc (count);
      if jury<>cont then quit (_wa, 'Ошибка в числе #'+i2s (count)+' (позиция в файле жюри '+
        ans.spp +') Требовалось '+i2s (jury)+', а получено '+i2s (cont));
    end;
  if not ouf.seekeof then quit (_wa, 'Лишняя информация в ответе участника');
  quit (_ok, '');
end.