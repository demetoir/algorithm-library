

book=[(0,0)]
T=[]
H=[]
n=input()
for i in range(n):
    a,b=map(int,raw_input().split())
    T+=[a]
    H+=[b]

psum=[0]
for i in range(n):
    psum+=[psum[-1]+T[i]]

print psum
memo=[987654321]*(n+1)
memo[0]=0

l=16

for i in range(1,n+1):
    val=memo[i]
    for j in range(i):
        if psum[i]-psum[j]>l:continue

        h=max(H[j:i])
        #print i,j,memo[j]+h
        #print i,j,h
        val=min(memo[j]+h,val)

    print i,val
    memo[i]=val





