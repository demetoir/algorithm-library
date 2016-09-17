n=int(raw_input())
shom=[]

def makeshom(n):
    global shom
    if n>1000000:return
    shom+=[n]
    makeshom(n*10+4)
    makeshom(n*10+7)
makeshom(4)
makeshom(7)
#print len(shom) 

memo=[-1]*1000001
memo[0]=0
shom.sort()

import Queue

Q=Queue.deque()

Q+=[0]
while len(Q)>0:
    cur =Q.popleft()
    #print cur
    for s in shom:
        next=cur+s
        
        if next>n:break
        if memo[next]==-1 or memo[next]>memo[cur]+1:
            memo[next]=memo[cur]+1
            Q+=[next]
            
#print memo[n]
ans=[]
if memo[n]==-1:
    print -1
    exit()
    
while n>0:
    for s in shom:
        next=n-s
        if next<0:break
        if memo[n]-1==memo[next]:
            ans+=[s]
            n-=s
            break
print " ".join(map(str,ans))












