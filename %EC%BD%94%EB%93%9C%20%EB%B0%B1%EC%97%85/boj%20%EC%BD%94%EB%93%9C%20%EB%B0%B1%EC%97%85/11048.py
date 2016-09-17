n,m=map(int,raw_input().split())
ll=[]

for i in range(n):
    ll+=[map(int,raw_input().split())]
memo=[[0]*m for i in range(n)]
memo[0][0]=ll[0][0]
for i in range(1,m):
    memo[0][i]=memo[0][i-1]+ll[0][i]
for i in range(1,n):
    memo[i][0]=memo[i-1][0]+ll[i][0]
#for i in memo:print i   
for i in range(1,n):
    for j in range(1,m):
        memo[i][j]=max(memo[i-1][j],memo[i][j-1],memo[i-1][j-1])+ll[i][j]
    
print memo[n-1][m-1]














