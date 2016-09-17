import sys

n=int(raw_input())
color=[0]*(n+1)
colorsum=[0]*(n+1)

anslist=[0]*(n+1)
sortedlist=[]
sizeset={}
for i in range(n):
    c,s=map(int,sys.stdin.readline().split())
    color[i]=c
    sortedlist+=[(s,i)]
    sizeset[s]=0
sortedlist.sort()
sizeset=sorted(list(sizeset))
total=0
sizelist=[-1]*(3000)
for i in range(n-1,-1,-1):
    s,index=sortedlist[i]
    sizelist[s]=i
    
for size in sizeset:
    temp=[]
    start=sizelist[size]
    if start==-1:continue
    #print size,start
    for i in range(start,n):
        s,index=sortedlist[i]
        c=color[index]
        if s>size:
            break
        if s==size:            
            temp+=[i]
            anslist[index] = total - colorsum[c]
        
    for i in temp:
        s,index=sortedlist[i]
        c=color[index]
        total+=s
        colorsum[c]+=s
    
for i in range(n):
    print anslist[i]    
    
    
    