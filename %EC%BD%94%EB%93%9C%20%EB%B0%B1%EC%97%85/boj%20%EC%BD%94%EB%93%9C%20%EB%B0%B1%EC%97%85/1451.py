n,m=map(int,raw_input().split())

l=[]
for i in range(n):
    t=[]
    for c in raw_input():
        t+=[int(c)]
    l+=[t]
#for i in l:print i
#print 
ps=[[0]*(m+1) for i in range(n+1)]
for i in range(1,n+1):
    for j in range(1,m+1):
        val=0
        for a in range(i):
            for b in range(j):
                #print i,j,a,b
                val+=l[a][b]
        ps[i][j]=val  

for i in ps:print i

ans=0
for i in range(m):
    for j in range(i+1,m):
        for k in range(j+1,m):
            a=ps[n-1][i]
            b=ps[n-1][j]-a
            c=ps[n-1][m-1]-a-b
            #print a,b,c,a*b*c
            ans=max(ans,a*b*c)
#print "#1"

for i in range(n):
    for j in range(i+1,n):
        for k in range(j+1,n):   
            a=ps[i][m-1]
            b=ps[j][m-1]-a
            c=ps[k][m-1]-a-b
            #print a,b,c,a*b*c
            ans=max(ans,a*b*c)
 
#print  "#2"
 
            
for i in range(n):
    for j in range(i+1,n):
        for k in range(1,m-1):
            a=ps[m-1][i]
            print k,n-1, k, i
            b=ps[k][n-1]-ps[k][i]
            c=ps[m-1][j]-a-b
            ans=max(ans,a*b*c)
            #print a,b,c,a*b*c
            a=ps[k][i]
            b=ps[m-1][i]-a
            c=ps[m-1][j]-a-b
            ans=max(ans,a*b*c)
            #print a,b,c,a*b*c
#print "#3"
for i in range(m):
    for j in range(i+1,m):
        for k in range(1,n-1):
            a=ps[i][k]
            b=ps[i][n-1]-a 
            c=ps[j][n-1]-a-b
            #print a,b,c,a*b*c 
            ans=max(ans,a*b*c)
            a=ps[i][n-1]
            b=ps[m-1][k]-ps[i][k]
            c=ps[j][n-1]-a-b
            #print a,b,c,a*b*c 
            ans=max(ans,a*b*c)
print ans            
                    
            
            
        


