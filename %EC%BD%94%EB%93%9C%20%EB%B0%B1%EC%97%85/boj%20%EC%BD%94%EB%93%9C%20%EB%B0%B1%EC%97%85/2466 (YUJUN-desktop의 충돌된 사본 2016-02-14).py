import sys
import Queue

T=[0]
H=[0]
n=input()
ps=[0]

for i in range(n):
    a,b=map(int,sys.stdin.readline().split())
    T+=[a]
    H+=[b]    
    ps+=[ps[i]+a]


INF=10**9      
maxT=max(T)

def f(x):
    
    memo=[10**9 ]*(n+1)
    memo[0]=0
    memo[1]=H[1]


    deq=Queue.deque()
    deq+=[(H[1],1)]
    size=1
    for i in range(2,n+1):

        index=i
        while size>0:
            
            top= deq[size-1][0]
            if top>=H[i]:break
            index=deq[size-1][1]
            deq.pop()
            size-=1
            
        if size==0:
            deq+=[(H[i],index)]
            size+=1
        else:    
            val = deq[size-1][0]
            if val>H[i]:
                deq+=[(H[i],index)]
                size+=1
        
        while  size>0:

            cur=deq[0][1]
            if ps[i]-ps[cur-1]>x:
                val,cur=deq.popleft()
                size-=1
                if size==0:
                    deq.appendleft((val,cur+1))
                    size+=1
                else:
                    bot=deq[0][1]
                    if cur+1<bot:
                        deq.appendleft((val,cur+1))
                        size+=1
            else:
                break

        for k in range(size):
            val,cur=deq[k]

            memo[i]=min(memo[i],memo[cur-1]+val)
   
    return memo[n]    

def test():
    ans=987654321000
    LOW=maxT
    HIGH=INF
    
    while LOW<=HIGH:
        x = (HIGH+LOW)//2
        val=f(x)
        
        ans=min(ans, max(x,val))
        if x<val:
            LOW=x+1
        elif x>val:
            HIGH=x-1    
        else:
            break
    print ans  

test()   

    
    
     





