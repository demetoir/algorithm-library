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
{ Универсальная программа тестирования для простых случаев.
  Сравнивает строчки файлов, обрезая конечные пробелы и табуляции.
  Допускаются пустые, в том числе состоящие из пробелов и табуляций,
  строки в конце каждого файла. 
  При несовпадении выдается номер строки.
  11.02.98. Шафиров Максим.
}

(* modified 08 november 2001 with accordance to new changes in testlib *)

uses testlib;

var ansWord, oufWord : String;
    i, badpos, tmp:integer;


begin
 repeat
   ouf.SavePosition;
   if ans.eof then break;
   ansWord := StripRightSpaces (ans.ReadString);
   oufWord := StripRightSpaces (ouf.ReadString);
   if (ansWord<>oufWord) then
     begin
       tmp:=min (length (answord), length (oufword));
       badpos:=tmp+1;
       for i:=1 to tmp do
         if oufword[i]<>answord[i] then begin badpos:=i;break;end;
       QUIT(_WA,'Несовпадение в позиции (' + ouf.GetSavedLineCountStr+
                ', '+IntToString (badpos)+').'+#13#10+
                'Написано  :"'+oufWord+'"'#13#10+
                'В эталоне :"'+ansWord+'"');
     end;
   if ouf.eof then
     if not ans.seekeof then
       ouf.UnExpectedEOF;
   (*if ans. eof then break;
   if ouf. eof then
   begin
      repeat
         ansWord := Rtrim(ans. ReadString);
         if ansWord <> '' then QUIT(_WA, 'В эталонном файле больше информации');
      until not ans. eof;
      QUIT(_OK,'');
   end;*)

 until false;

 QUIT(_OK,'');
end.

