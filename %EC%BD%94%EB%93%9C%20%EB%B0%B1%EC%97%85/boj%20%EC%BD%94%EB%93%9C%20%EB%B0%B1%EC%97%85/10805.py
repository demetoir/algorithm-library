a,b,c,d=map(int,raw_input().split())

memo=[[[[-1 for w in range(51)] for i in range(51)] for j in range(51)]for k in range(51)]
memo[0][0][0][0]=0

for i in range(1,50+1):
    memo[i][i][0][0]=1
    
   
def f(h1,w1,h2,w2):
    cur=h1,w1,h2,w2
    
    if memo[h1][w1][h2][w2]>-1:
        return memo[h1][w1][h2][w2]
    
    if (h2,w2)==(0,0):
        val=123456789
        b,s=h1,w1
        for i in range(1,h1):
            val=min(val,f(i,s,0,0)+f(h1-i,s,0,0))
        for i in range(1,w1):
            val= min(val,f(b,i,0,0)+f(b,w1-i,0,0))
        
        
        memo[h1][w1][0][0]=val
        memo[w1][h1][0][0]=val
        #print cur, ":",val
        return val
    val = f(h2,w1-w2,0,0)+f(h1-h2,w1,0,0)
    a=f(h1,w1-w2,0,0)+f(h1-h2,w2,0,0)
    if a<val:val=a
    
    for i in range(1,h2):
        a=f(i,w1-w2,0,0)+f(h1-i,w1,h2-i,w2)
        if a<val:val=a
    for i in range(h2+1,h1):
        a=f(i,w1,h2,w2)+f(h1-i,w1,0,0)
        if a<val:val=a
    for i in range(1,w1-w2):        
        a=f(h1,i,0,0)+f(h1,w1-i,h2,w2)
        if a<val:val=a
    for i in range(w1-w2+1,w1):
        a=f(h1,i,h2,i-w1+w2)+f(h1-h2,w1-i,0,0)
        if a<val:val=a
    #print cur, ":",val    
    memo[h1][w1][h2][w2]=val
    
    return val


print f(a,b,c,d)        
        
        
        
        
        
        
        
        
        
        