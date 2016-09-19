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
begin
  StrictEof;
  DisablePE;
  repeat
    if ans.eoln then begin ans.RequireNewLine (Accept_EOF);
                           ouf.RequireNewLine (ans.eof) end;
    if ans.eof then break;
    if ouf.eof then ouf.UnExpectedEOF;
    if ans.cur<>ouf.cur then
      QUIT (_WA, 'Несовпадение в позиции '+ouf.GetPosPair+': вместо '+
                 SymbolToString (ouf.cur)+' ожидалось '+
                 SymbolToString (ans.cur));
    ans.nextchar; ouf.nextchar;
  until false;
  QUIT (_OK, '');
end.