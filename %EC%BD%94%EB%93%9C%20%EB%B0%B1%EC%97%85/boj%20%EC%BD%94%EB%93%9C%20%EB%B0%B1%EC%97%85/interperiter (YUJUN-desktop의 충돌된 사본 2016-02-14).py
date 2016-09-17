n,m=map(int,raw_input().split())
l=[0]

for i in range(n):
    a=input()
    l+=[a]
    
l.sort()
n+=1
for i in range(n):
    if l[i]==0:
        start=i       
    

L=[[[-1 for k in range(n+1)] for i in range(n+1)] for j in range(n+1)]
R=[[[-1 for k in range(n+1)] for i in range(n+1)] for j in range(n+1)]
inf=987654321

for i in range(n+1):
    for j in range(n+1):
        L[i][j][0]=0
        R[i][j][0]=0
        

def Lf(i,j,k):
    
    if i>j or i<0 or i>=n or j<0 or j>=n or k<0:               
        return inf
    
    if L[i][j][k]!=-1:  
        return L[i][j][k]

    a=Lf(i-1,j,k-1)
    if a<inf:
        a+=(l[i]-l[i-1])*k
    
    b=Rf(i,j+1,k-1)
    if b<inf:
        b+=(l[j+1]-l[i])*k
      
 
    L[i][j][k]=min(a,b)   
    return L[i][j][k]

def Rf(i,j,k):
    if i>j or i<0 or i>=n or j<0 or j>=n or k<0:            
        return inf
    
    if R[i][j][k]!=-1:        
        return R[i][j][k]

    a=Lf(i-1,j,k-1)
    if a<inf:
        a+=(l[j]-l[i-1])*k            
    
    b=Rf(i,j+1,k-1)
    if b<inf:
        b+=(l[j+1]-l[j])*k

    R[i][j][k]=min(a,b)
    return R[i][j][k]

ans=0

for k in range(n):            
    a=Lf(start,start,k)

    ans=max(ans,k*m-a)   
print ans     







