n= input()
l=[]
for c in raw_input():
    l+=[int(c)]
G=[]
for i in range(n):
   s=raw_input()
   G+=[s]
check=[]
#print G
color=[0,0]

def dfs(x,c,val):
    global check
    global color
    
    if check[x]>0:
        return 
    #print x
    check[x]= 1
    
    color[c]+=1
    c = c ^ 1
    
    for i in range(n):        
        if l[i]!=val and G[x][i]=="Y":
            dfs(i,c,val)
    return

def find(val):
    global color
    global check
    
    check=[0]*n
    
    
    c=0
    ret=0
    for i in range(n):
        color=[0,0]
        if l[i]==val:
            c+=1
            check[i]=1
        if check[i]==0:            
            dfs(i,0,val)
            ret+=max(color) 
            #print 
 
    #print c,ret
    return c+ ret

#print "#2 3"
a=find(1)
#print a
#print "#2 3"
#print
 
#print "#1 3"
b=find(2)
#print b
#print "#1 3"
#print

#print "#1 2" 
c=find(3)
#print c
#print "#1 2" 
#print 

print max(a,b,c)    
    
    
    
    
    
    
    
    
    
    
    
    
    