
def make(x):
    if x in char:
        return
    char[x]=[False]*128
    #print x,D[x]
    #print type(D[x])
    if type(D[x]) is str:
        for c in D[x]:
           char[x][ord(c)]=True
           #print x,c,ord(c)
    else:
        a,b=D[x]
        #print a,b
        make(a)
        make(b)
        for i in range(128):
            if char[a][i] or char[b][i]:
                char[x][i]=True
def f(x):
    #print "<",x
    global pi
    s=D[x]
    if type(s) is str:
        for c in s:
            if c==P[pi]:
                #print x,c,pi
                pi+=1
                
            if pi==len(P):
                #print x,">"
                return True

    else:
        a,b=s
        #print a,b
        c=P[pi]
        if char[a][ord(c)]:
            val=f(a)
            if val:
                #print x,">"
                return True
        c=P[pi]
        if char[b][ord(c)]:
            val=f(b)
            if val:
                #print x,">" 
                return True
    #print x,">"    
    return False
for case in range(input()): 
    n=input()
    D={}
    char={}
    for i in range(n):
        s=raw_input().split()
        a=s[0]
        #print s
        if len(s)==5:
            D[a]=(s[2],s[4])
        else:
            D[a]=s[2]
        #print a,D[a]
    T=raw_input()
    P=raw_input()
    pi=0
    for x in D:
        make(x)
        
    
    #print char["F"][97]
     
    if f(T):print "YES"
    else:print "NO"            
                
            
            
            
            
            
            
            
            
            