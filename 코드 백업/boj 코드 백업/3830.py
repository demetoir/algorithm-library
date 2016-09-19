n=100
parent=[0]*(n+1)
rank=[0]*(n+1)
weight=[0]*(n+1)



def find(x):
    p=parent[x]
    if p==x:
        return x
    root=find(p)
    weight[x]+=weight[p]
    parent[x]=root
    return root

def union(a,b,w):
    Aroot=find(a)
    Broot=find(b)
    if rank[Aroot]<rank[Broot]:
        weight[Aroot]= weight[b] + w - weight[a]
        parent[Aroot]=Broot
    elif rank[Aroot]>=rank[Broot]:
        weight[Broot]= weight[a] - w - weight[b]
        parent[Broot]=Aroot
        if rank[Aroot]==rank[Broot]:
            rank[Aroot]+=1
    
n,m=map(int,raw_input().split())  
for i in range(m):
    l=raw_input().split()
    kind=l[0]
    if kind=="?":
        a,b=l[1],l[2]
        if find(a)==find(b):
            print weight[a]-weight[b]
        else:
            print "UNKNOWN"
    else:
        a,b,w=l[1],l[2],l[3]
        union(a,b,w)

    
    
    
    
    
    
    
    
    