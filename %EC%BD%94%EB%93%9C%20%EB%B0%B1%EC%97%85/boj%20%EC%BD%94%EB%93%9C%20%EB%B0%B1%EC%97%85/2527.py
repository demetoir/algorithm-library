for T in range(4):    
    x,y=0,0
    Al,Ab,Ar,At,Bl,Bb,Br,Bt=map(int,raw_input().split())    
    for i in range(1,50000+1):
        if Al<=i<=Ar and Bl<=i<=Br:x+=1
        if Ab<=i<=At and Bb<=i<=Bt:y+=1
    ans=""
    if x==0 or  y==0:ans="d"
    elif x==1 and y==1:ans="c"
    elif x>1 and y>1:ans="a"
    else:ans="b"
    print ans
