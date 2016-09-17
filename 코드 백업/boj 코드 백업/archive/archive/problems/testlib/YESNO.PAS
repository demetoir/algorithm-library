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
uses testlib, symbols;
var jury, cont:string;
begin
  jury:=StripSpaces (UpStr (ans.readstring));
  cont:=StripSpaces (UpStr (ouf.readstring));
  if (cont<>'NO') and (cont<>'YES') then quit (_PE, 'YES or NO required');
  if jury<>cont then quit (_WA, 'Jury: '+jury+', Contestant: '+cont);
  quit (_OK, '');
end.