side=1cm;
scale=5;

beginfig(1)

pickup pencircle scaled 1pt;

defaultfont:="cmtt10";
label("2003", (0, 0)) scaled scale;
defaultfont:="cmtt8";
picture p;

defaultfont:="cmr8";
label(btex Bus~ticket etex, (0, 0)) 
    scaled (scale / 2.2) 
    shifted (0, side * 1.8 * scale / 2.5)
    ;

defaultfont:="cmtt8";
label(btex {\bf St.~Petersburg} etex, (0, 0)) 
    scaled (scale / 3.5) 
    shifted (0, side * 1.2 * scale / 2.5);

label(btex {\bf ---} etex, (0, 0)) 
    scaled (scale / 3.5) 
    shifted (0, side * 0.95 * scale / 2.5);

label(btex {\bf Prague} etex, (0, 0)) 
    scaled (scale / 3.5) 
    shifted (0, side * 0.7 * scale / 2.5);

draw (
    (-side, -side/2)--
    (-side,  side * 2)--
    ( side,  side * 2)--
    ( side, -side/2)--
    cycle
) scaled (scale / 2.5);

fill (
    (side * 0.47, side * 0.43)..
    (side * 0.33, side * 0.43)..
    (side * 0.33, side * 0.57)..
    (side * 0.47, side * 0.57).. 
    cycle 
) shifted (-side / 2, -side / 2) scaled scale withcolor 0.8 * white;

fill (
    (side * 0.67, side * 0.43)..
    (side * 0.53, side * 0.43)..
    (side * 0.53, side * 0.57)..
    (side * 0.67, side * 0.57).. 
    cycle 
) shifted (-side / 2, -side / 2) scaled scale withcolor 0.8 * white;

draw (
    (side * 0.47, side * 0.43)..
    (side * 0.33, side * 0.43)..
    (side * 0.33, side * 0.57)..
    (side * 0.47, side * 0.57)..
    cycle
) shifted (-side / 2, -side / 2) scaled scale withcolor 0.5 * white;

draw (
    (side * 0.67, side * 0.43)..
    (side * 0.53, side * 0.43)..
    (side * 0.53, side * 0.57)..
    (side * 0.67, side * 0.57).. 
    cycle 
) shifted (-side / 2, -side / 2) scaled scale withcolor 0.5 * white;

endfig;
end
