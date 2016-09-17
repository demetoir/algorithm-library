n=int(raw_input())

l=[]
Sl=[]
for i in range(n):
    l+=[map(int,raw_input().split())]

#print l
for i in range(n):
    for j in range(n):
        val=l[i][j]
        Sl+=[(val,i,j)]
Sl.sort()
#print Sl
memo=[[1]*n for i in range(n)]
d=[(0,1),(1,0),(0,-1),(-1,0)]
#print
ans =0
for i in range(n*n):
    val,x,y=Sl[i]   
    ans=max(ans,memo[x][y])
    for dx,dy in d:
        a,b=x+dx,y+dy
        if a<0 or a>=n :continue
        if b<0 or b>=n:continue
        next=l[a][b]
        if next>val:
            memo[a][b]= max(memo[a][b],memo[x][y]+1)

print ans
#for i in memo:print i            




