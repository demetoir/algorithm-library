{$I trans.inc}
unit dogen;
interface
uses dorand;
const MaxN=100;
      MaxH=100;
const MaxM=5000;
type pnode=^tnode;
     top=(_num, _var, _unint, _unun, _int, _un, _sub, _xor, _ent, _entsngl, _newent);
     tnode=record
       l, r:pnode;
       op:top;
       name:string;
     end;
var n:integer;
    m:integer;
function displaytree (t:pnode):string;
function randomtreefull (maxd, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7:integer):pnode;
function randomtree (maxd, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7:integer):pnode;
function displaytree2 (t:pnode; lastent, zapya:boolean):string;
function randomtree2full (maxd, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, pa:integer):pnode;
function randomtree2 (maxd, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, pa:integer):pnode;
implementation
const opnames:array [_unint.._xor] of string [2]=('+', '*', '+', '*', '-', '^');

function randomtreefull (maxd, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7:integer):pnode;
var t:pnode;
    tmp:integer;
    i:integer;
begin
  new (t);
  with t^ do begin
    if maxd=0 then begin
      tmp:=random (p0+p1);
      if tmp<p0 then begin l:=nil; r:=nil; op:=_num; str (lr (0, MaxNum), name) end else
      if tmp<p0+p1 then begin l:=nil; r:=nil; op:=_var; name:=''; 
        for i:=1 to lr (minname, maxname) do name:=name+randomchar (['A'..'Z', 'a'..'z']);
      end;
    end else begin
      if maxd<=fd then tmp:=random (p0+p1+p2+p3+p4+p5+p6+p7) else
                       tmp:=p0+p1+random (p2+p3+p4+p5+p6+p7);
      if tmp<p0 then begin l:=nil; r:=nil; op:=_num; str (lr (0, MaxNum), name) end else
      if tmp<p0+p1 then begin l:=nil; r:=nil; op:=_var; name:=''; 
        for i:=1 to lr (minname, maxname) do name:=name+randomchar (['A'..'Z', 'a'..'z']);
      end else
      if tmp<p0+p1+p2+p3 then begin
        l:=randomtreefull (maxd-1, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7); r:=nil; 
        if tmp<p0+p1+p2 then op:=_unint else op:=_unun;
      end else begin
        l:=randomtreefull (maxd-1, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7);
        r:=randomtreefull (maxd-1, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7);
        if tmp<p0+p1+p2+p3+p4 then op:=_int else
        if tmp<p0+p1+p2+p3+p4+p5 then op:=_un else
        if tmp<p0+p1+p2+p3+p4+p5+p6 then op:=_sub else
        op:=_xor;
      end;
    end;
  end;
  randomtreefull:=t;
end;


function randomtree (maxd, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7:integer):pnode;
var t:pnode;
    tmp:integer;
    i:integer;
begin
  new (t);
  with t^ do begin
    if maxd=0 then begin
      tmp:=random (p0+p1);
      if tmp<p0 then begin l:=nil; r:=nil; op:=_num; str (lr (0, MaxNum), name) end else
      if tmp<p0+p1 then begin l:=nil; r:=nil; op:=_var; name:=''; 
        for i:=1 to lr (minname, maxname) do name:=name+randomchar (['A'..'Z', 'a'..'z']);
      end;
    end else begin
      if maxd<=fd then tmp:=random (p0+p1+p2+p3+p4+p5+p6+p7) else
                       tmp:=p0+p1+random (p2+p3+p4+p5+p6+p7);
      if tmp<p0 then begin l:=nil; r:=nil; op:=_num; str (lr (0, MaxNum), name) end else
      if tmp<p0+p1 then begin l:=nil; r:=nil; op:=_var; name:=''; 
        for i:=1 to lr (minname, maxname) do name:=name+randomchar (['A'..'Z', 'a'..'z']);
      end else
      if tmp<p0+p1+p2+p3 then begin
        l:=randomtree (maxd-1, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7); r:=nil; 
        if tmp<p0+p1+p2 then op:=_unint else op:=_unun;
      end else begin
        l:=randomtree (maxd-1, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7);
        r:=randomtree (maxd-1, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7);
        if tmp<p0+p1+p2+p3+p4 then op:=_int else
        if tmp<p0+p1+p2+p3+p4+p5 then op:=_un else
        if tmp<p0+p1+p2+p3+p4+p5+p6 then op:=_sub else
        op:=_xor;
      end;
    end;
  end;
  randomtree:=t;
end;


function displaytree (t:pnode):string;
var tmp:string;
begin
  tmp:='';
  case t^.op of
    _var, _num:tmp:=t^.name;
    _unun, _unint:begin
           tmp:=tmp+opnames[t.op];
           if t^.l^.op>t^.op then tmp:=tmp+'(';
           tmp:=tmp+displaytree (t^.l);
           if t^.l^.op>t^.op then tmp:=tmp+')';
         end;
    else begin
      if t^.l^.op>t^.op then tmp:=tmp+'(';
      tmp:=tmp+displaytree (t^.l);
      if t^.l^.op>t^.op then tmp:=tmp+')';
      tmp:=tmp+opnames [t^.op];
      if t^.r^.op>t^.op then tmp:=tmp+'(';
      tmp:=tmp+displaytree (t^.r);
      if t^.r^.op>t^.op then tmp:=tmp+')';
    end;
  end;
  displaytree:=tmp;
end;

function randomtree2full (maxd, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, pa:integer):pnode;
var t:pnode;
    tmp:integer;
    i:integer;
begin
  new (t);
  with t^ do begin
    if maxd=0 then begin
      tmp:=random (p0+p1);
      if tmp<p0 then begin l:=nil; r:=nil; op:=_num; str (lr (0, MaxNum), name) end else
      if tmp<p0+p1 then begin l:=nil; r:=nil; op:=_var; name:=''; 
        for i:=1 to lr (minname, maxname) do name:=name+randomchar (['A'..'Z', 'a'..'z']);
      end;
    end else begin
      if maxd<=fd then tmp:=random (p0+p1+p2+p3+p4+p5+p6+p7+p8+p9+pa) else
                       tmp:=p0+p1+random (p2+p3+p4+p5+p6+p7+p8+p9+pa);
      if tmp<p0 then begin l:=nil; r:=nil; op:=_num; str (lr (0, MaxNum), name) end else
      if tmp<p0+p1 then begin l:=nil; r:=nil; op:=_var; name:=''; 
        for i:=1 to lr (minname, maxname) do name:=name+randomchar (['A'..'Z', 'a'..'z']);
      end else
      if tmp<p0+p1+p2+p3+p4 then begin
        l:=randomtree2full (maxd-1, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, pa); r:=nil; 
        if tmp<p0+p1+p2 then op:=_unint else 
        if tmp<p0+p1+p2+p3 then op:=_unun else
        op:=_entsngl;
      end else begin
        l:=randomtree2full (maxd-1, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, pa);
        r:=randomtree2full (maxd-1, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, pa);
        if tmp<p0+p1+p2+p3+p4+p5 then op:=_int else
        if tmp<p0+p1+p2+p3+p4+p5+p6 then op:=_un else
        if tmp<p0+p1+p2+p3+p4+p5+p6+p7 then op:=_sub else
        if tmp<p0+p1+p2+p3+p4+p5+p6+p7+p8 then op:=_xor else
        if tmp<p0+p1+p2+p3+p4+p5+p6+p7+p8+p9 then op:=_ent else
        op:=_newent;
      end;
    end;
  end;
  randomtree2full:=t;
end;


function randomtree2 (maxd, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, pa:integer):pnode;
var t:pnode;
    tmp:integer;
    i:integer;
begin
  new (t);
  with t^ do begin
    if maxd=0 then begin
      tmp:=random (p0+p1);
      if tmp<p0 then begin l:=nil; r:=nil; op:=_num; str (lr (0, MaxNum), name) end else
      if tmp<p0+p1 then begin l:=nil; r:=nil; op:=_var; name:=''; 
        for i:=1 to lr (minname, maxname) do name:=name+randomchar (['A'..'Z', 'a'..'z']);
      end;
    end else begin
      if maxd<=fd then tmp:=random (p0+p1+p2+p3+p4+p5+p6+p7+p8+p9+pa) else
                       tmp:=p0+p1+random (p2+p3+p4+p5+p6+p7+p8+p9+pa);
      if tmp<p0 then begin l:=nil; r:=nil; op:=_num; str (lr (0, MaxNum), name) end else
      if tmp<p0+p1 then begin l:=nil; r:=nil; op:=_var; name:=''; 
        for i:=1 to lr (minname, maxname) do name:=name+randomchar (['A'..'Z', 'a'..'z']);
      end else
      if tmp<p0+p1+p2+p3 then begin
        l:=randomtree2 (maxd-1, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, pa); r:=nil; 
        if tmp<p0+p1+p2 then op:=_unint else 
        if tmp<p0+p1+p2+p3 then op:=_unun else
        op:=_entsngl;
      end else begin
        l:=randomtree2 (maxd-1, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, pa);
        r:=randomtree2 (maxd-1, maxv, minname, maxname, maxnum, fd, p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, pa);
        if tmp<p0+p1+p2+p3+p4+p5 then op:=_int else
        if tmp<p0+p1+p2+p3+p4+p5+p6 then op:=_un else
        if tmp<p0+p1+p2+p3+p4+p5+p6+p7 then op:=_sub else
        if tmp<p0+p1+p2+p3+p4+p5+p6+p7+p8 then op:=_xor else
        if tmp<p0+p1+p2+p3+p4+p5+p6+p7+p8+p9 then op:=_ent else
        op:=_newent;
      end;
    end;
  end;
  randomtree2:=t;
end;


function displaytree2 (t:pnode; lastent, zapya:boolean):string;
var tmp:string;
begin
  tmp:='';
  case t^.op of
    _var, _num:tmp:=t^.name;
    _unun, _unint:begin
           tmp:=tmp+opnames[t.op];
           if t^.l^.op>t^.op then tmp:=tmp+'(';
           tmp:=tmp+displaytree2 (t^.l, false, false);
           if t^.l^.op>t^.op then tmp:=tmp+')';
         end;
    _int, _un, _sub, _xor: begin
      if t^.l^.op>t^.op then tmp:=tmp+'(';
      tmp:=tmp+displaytree2 (t^.l, false, false);
      if t^.l^.op>t^.op then tmp:=tmp+')';
      tmp:=tmp+opnames [t^.op];
      if t^.r^.op>t^.op then tmp:=tmp+'(';
      tmp:=tmp+displaytree2 (t^.r, false, false);
      if t^.r^.op>t^.op then tmp:=tmp+')';
    end;
    _ent:begin
      if not lastent then tmp:=tmp+'{' else if zapya then tmp:=tmp+',';
      tmp:=tmp+displaytree2 (t^.l, true, false);
      tmp:=tmp+',';
      tmp:=tmp+displaytree2 (t^.r, true, false);
      if not lastent then tmp:=tmp+'}';
    end;
    _entsngl:begin
      if not lastent then tmp:=tmp+'{' else if zapya then tmp:=tmp+',';
      tmp:=tmp+displaytree2 (t^.l, true, false);
      if not lastent then tmp:=tmp+'}'
    end;
    _newent:begin
      tmp:=tmp+'{';
      tmp:=tmp+displaytree2 (t^.l, true, false);
      tmp:=tmp+',';
      tmp:=tmp+displaytree2 (t^.r, true, false);
      tmp:=tmp+'}';
    end
    else runerror (239);
  end;
  displaytree2:=tmp;
end;

end.