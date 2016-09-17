{ Copyright(c) SPb-IFMO CTD Developers, 2000 }

{ $Id: ncmp.dpr,v 1.1 2001/11/14 15:21:55 sta Exp $ }

{ Written by Andrew Stankevich }

(*
   NUMBERS COMPARE
   Compares sequences of numbers in files for equality
     in length and contents
*)

program ncmp;

uses
  testlib, sysutils;

var
  j, p: longint;

begin
  j := ans.readlongint;
  p := ouf.readlongint;

  if j <> p then
    quit(_wa, 'expected: "' + inttostr(j) + '", found: "' + inttostr(p) + '"');
  quit(_ok, '');
end.
