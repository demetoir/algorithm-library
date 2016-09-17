n,m,t,k=map(int,raw_input().split())
l=[]
ans=0
A,B=0,0

Yset={}
for a in range(t):
    x,y=map(int,raw_input().split())
    l+=[(x,y)]
    Yset[y]=0
    
def updateval(a,b,c,d):
    global l
    global A,B,ans
    val=0
    for x,y in l:
        if a<=x<=b and c<=y<=d:
            val+=1
    #print "#",a,d,val
    if ans<val:
        ans=val
        A,B=a,d
        #print "###",a,d,val
   
Ylist=sorted(list(Yset))
while len(Ylist)>0:
    if Ylist[0]>=k:break
    Ylist.pop(0)
#print Ylist
updateval(0,k,0,k)
 
for Y in Ylist:
    updateval(0, k, Y-k, Y)
    for x,y in l:
        if Y-k <= y <= Y and k <= x:
            updateval(x-k, x,Y-k,Y)
            
print A,B 
print ans
    
    

