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
var jury, cont, count:longint;
begin
  count:=0;
  while not ans.seekeof do
    begin
      if ouf.seekeof then quit (_Wa, '���������� ����� 䠩�� ���⭨��');
      ans.sp;
      jury:=ans.getlong;
      cont:=ouf.getlong;
      inc (count);
      if jury<>cont then quit (_wa, '�訡�� � �᫥ #'+i2s (count)+' (������ � 䠩�� ��� '+
        ans.spp +') �ॡ������� '+i2s (jury)+', � ����祭� '+i2s (cont));
    end;
  if not ouf.seekeof then quit (_wa, '����� ���ଠ�� � �⢥� ���⭨��');
  quit (_ok, '');
end.