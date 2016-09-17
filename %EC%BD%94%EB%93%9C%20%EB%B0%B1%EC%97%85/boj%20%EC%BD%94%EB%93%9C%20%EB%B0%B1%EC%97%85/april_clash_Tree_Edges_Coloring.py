import Queue


T = int(raw_input())
n= 0
color = 0
G = 0
## memo1[a][b]
## a번째 에지 일때 color b를 선택했을때 최소
memo1 = [[-1]*n for i in range(n)]

root = -1
leafnumber = -1
newG = []
dfschecked = [False]*n
dp1check = [False] *n

memo2 = [[-1]]

##### declare var
def dp2(cur , colorIndex):

    level = len(G[cur])
    memo2 = [ [0]* n for i in range(level) ]
    INF = 12345678
    #초기화
    for i in range(level):
        memo2[level][colorIndex] = 12345678
    for i in range(n-1):
        memo2[0][i] = memo1[G[cur][level]]

    for L in range (1,level):
        for i








def dp1(cur):
    global dp1check,memo1

    if dp1check[cur]:
        return

    dp1check[cur] = True


    for ColorIndex in range(n-1):

        pass
    return


def dfs(cur):
    global newG
    if dfschecked[cur]:
        return False

    dfschecked[cur] = True
    for next in G[cur]:
        if dfs(next):
            newG[cur]+=[next]
    return True


def makenewG():
    global leafnumber
    leafnumber = -1

    for i in range(n):
        if len(G[i]) == 1:
            leafnumber = i
            break
    print leafnumber
    a= G[leafnumber][0]
    G[a].remove(leafnumber)
    G[leafnumber] = []
    print G
for testcase in range(T):
    n = int (raw_input())
    color = [0]*(n+1)
    G = [[]for i in range(n)]
    color = map(int ,raw_input().split())
    for i in range(n-1):
        a,b =map(int ,raw_input().split())
        a,b = a-1,b-1
        G[a]+=[b]
        G[b]+=[a]

    makenewG()
    memo1 = [[-1]*n for i in range(n)]
    newG = [[]for i in range(n)]
    dfschecked = [False] * n
    print  G
    root = (leafnumber+1)%(n-1)

    dfs(root)
    print newG



    dp1check = [False] * n
    memo1 = [[-1] * n for i in range(n)]
    dp1(root)


























































