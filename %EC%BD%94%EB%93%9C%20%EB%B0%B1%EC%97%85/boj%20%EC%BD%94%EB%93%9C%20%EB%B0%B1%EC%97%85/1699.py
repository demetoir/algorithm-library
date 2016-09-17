
n=input()
import Queue
Q=Queue.Queue()
memo=[-1]*123456
for i in range(350):
    if i*i<=100000:
        memo[i*i]=1
        Q.put(i*i)
while not Q.empty():
    cur=Q.get()
    #print cur
    for i in range(1,350):
        next = cur + i*i
        if next>100000:break
        if memo[next]==-1 :            
            memo[next]=memo[cur]+1
            Q.put(next)
        if  memo[cur]+1<memo[next] :
            #print memo[next]  
            memo[next]=memo[cur]+1
            Q.put(next) 
#print memo            
print memo[n]            
        
        
        
        