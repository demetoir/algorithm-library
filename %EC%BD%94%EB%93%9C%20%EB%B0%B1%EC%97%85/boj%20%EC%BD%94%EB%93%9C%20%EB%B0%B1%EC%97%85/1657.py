
n,m=map(int,raw_input().split())
score=[[10,8,7,5,1],[8,6,4,3,1],[7,4,3,2,1],[5,3,2,2,1],[1,1,1,1,0]]
def getscore(x1,y1,x2,y2):
    return score[ord(dubu[y1][x1])-65][ord(dubu[y2][x2])-65]

dubu=[]
for i in range(m):
    s=raw_input()
    l=[]
    for c in s:
        l+=[c]
    dubu+=[l]

for i in dubu:
    print i
memo=[[[0]*(2**n) for i in range(15)] for i in range(15)]
memo[0][0][2]=getscore(0,0,1,0)
memo[0][0][1]=getscore(0,0,0,1)
for y in range(m):
    for x in range(n):
        if x==0 and y==0:continue
        a,b=(x+1)%n,y + (x+1)//n
        for bit in range(2**n):

            val=memo[x][y][bit]
            if (x+1<n) and (bit&1<<x ==0) and (bit&1<<(x+1) ==0):
                oldval=memo[a][b][bit + 1<<(x+1)]
                memo[a][b][bit + 1<<(x+1)]=max(oldval, val+getscore(x,y,x+1,y))

            if (y+1<m) and (bit & 1<<x == 0):
                oldval=memo[a][b][bit + 1<<x]
                memo[a][b][bit + 1<<x]= max(oldval, val+getscore(x,y,x,y+1))

            oldval=memo[a][b][bit &(2**n -1 (-1<<x))]
            memo[a][b][bit &(2**n -1 -1<<x)] =max(oldval,val)

print max(memo[m-1][n-1])