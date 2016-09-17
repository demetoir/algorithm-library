n,m=map(int,raw_input().split())
left=[]
right=[]
ans=0
for i in range(n):
    a=input()
    if a>0:right+=[a]
    elif a<0:left+=[a]
    else:ans+=m
    
left.sort() 
right.sort()
left.reverse()
maxl=500
Rmemo=[[[0,m*m] for j in range(maxl)]for i in range(maxl)]
Lmemo=[[[0,m*m] for j in range(maxl)]for i in range(maxl)]
maxval=0
#print Rmemo

if len(right)>0:
    Rmemo[1][0]=[right[0],right[0]]
if len(left)>0:
    Lmemo[1][0]=[-left[0],-left[0]]

for k in range(1,n):
    #R
    #print "K:",k
    #print "R"
    for index in range(len(right)):
        #print index
        if index > k:break
        atime,atotal= Rmemo[k][index]
        #print atime     
        if index + 1 < len(right):
            time, total= Rmemo[k+1][index+1]        
            ntime = atime + abs(right[index+1]-right[index])
            ntotal = atotal + ntime
            
            if ntotal < total:
                Rmemo[k+1][index+1] = [ntime,ntotal]
                maxval=max(maxval, m*(k+1) -ntotal)
                #print k+1,index+1,ntime,m*(k+1) -ntime
        
        if k-index-1 < len(left):        
            time,total = Lmemo[k+1][k-index-1]
            ntime = atime + abs(left[k-index-1]-right[index])
            ntotal = atotal + ntime
            
            if ntotal < total:
                Lmemo[k+1][k-index-1] = [ntime,ntotal]
                maxval=max(maxval, m*(k+1) -ntotal)
                #print k+1,k-index-1,ntime, m*(k+1) -ntime
            
    #print "L"    
    #L
    for index in range(len(left)):
        if index > k:break
        atime, atotal= Lmemo[k][index]
        
        if index + 1 < len(left):
            time,total = Lmemo[k+1][index+1]        
            ntime = atime + abs(left[index+1]-left[index])
            ntotal = atotal + ntime 
            if ntotal < total:
                Lmemo[k+1][index+1] = [ntime,ntotal]
                maxval=max(maxval, m*(k+1) -ntotal)
                #print k+1,index+1,ntime,m*(k+1) -ntime
        
        if k-index-1 < len(right):        
            time, total = Rmemo[k+1][k-index-1]
            ntime = atime + abs(right[k-index-1]-left[index])
            ntotal = atotal + ntime
            if ntotal < total:
                Rmemo[k+1][k-index-1] = [ntime,ntotal]
                maxval=max(maxval, m*(k+1) -ntotal)
                #print k+1,k-index-1,ntime,m*(k+1) -ntime        
        
        

'''
for i in Rmemo:
    print i
print 
for i in Lmemo:
    print i       
'''
l,r =len(left)-1,len(right)-1

print ans + maxval
print maxval
               
               
               
               
   
