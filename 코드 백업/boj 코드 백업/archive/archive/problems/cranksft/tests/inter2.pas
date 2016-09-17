{$I trans.inc}
unit inter2;
interface
function intersect (x11, y11, x12, y12, x21, y21, x22, y22:integer;
                    var xr, yr:extended):integer;
implementation
const eps=1e-12;

function zero (d:extended):boolean;
begin
  zero:=abs (d)<eps;
end;


function less (a, b:extended):boolean;
begin
  less:=b-a>eps
end;


function det (x1, y1, x2, y2:integer):int64;
begin
  det:=int64 (x1)*y2-int64 (y1)*x2;
end;


function intersect (x11, y11, x12, y12, x21, y21, x22, y22:integer;
                    var xr, yr:extended):integer;
var r1x, r1y, d1x, d1y, r2x, r2y, d2x, d2y:integer;
    d:int64;
    t1, t2:extended;
begin
  r1x:=x11; r1y:=y11;
  r2x:=x21; r2y:=y21;
  d1x:=x12-x11; d1y:=y12-y11;
  if (d1x=0) and (d1y=0) then runerror (239);
  d2x:=x22-x21; d2y:=y22-y21;
  if (d2x=0) and (d2y=0) then runerror (239);
  d:=det (d1x, d1y, d2x, d2y);
  if d=0 then begin
    if det (r2x-r1x, r2y-r1y, d1x, d1y)=0 then begin
      if d1x=0 then begin
        t1:=(r2y-r1y)/d1y; t2:=(r2y+d2y-r1y)/d1y;
      end else begin
        t1:=(r2x-r1x)/d1x; t2:=(r2x+d2x-r1x)/d1x;
      end;
      if (less (t1, 0) or less (t2, 0)) or
         (less (1, t1) or less (1, t2)) then intersect:=0
      else if zero (t2) or zero (t1)
      then begin
        intersect:=2;
        xr:=r1x;
        yr:=r1y;
      end else if zero (t2-1) or zero (t1-1) then begin
        intersect:=2;
        xr:=r1x+d1x;
        yr:=r1y+d1y;
      end else intersect:=3;
    end else intersect:=0;
  end else begin
    t1:=-(det (r1x, r1y, d2x, d2y)-det (r2x, r2y, d2x, d2y))/d;
    t2:=-(det (r1x, r1y, d1x, d1y)-det (r2x, r2y, d1x, d1y))/d;
    if less (t1, 0) or less (t2, 0) or less (1, t1) or less (1, t2) then
      intersect:=0
    else begin
      intersect:=1;
      xr:=r1x+t1*d1x;
      yr:=r1y+t1*d1y;
    end;
  end;
end;
end.