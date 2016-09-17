import bisect
import sys
import Queue
token=Queue.deque()
for line in sys.stdin:
   token+=map(int ,line.split()) 
n=token.popleft()
l=[]
for i in range(n):
    l+=[token.popleft()]
#l=map(int ,raw_input().split())

vector=[l[0]]
for i in range(1,n):
    x=l[i]
    index= bisect.bisect_left(vector,x)   
    #print index
    if index<len(vector):
        vector[index]=x
    else:
        vector+=[x]
    #print vector
#print vector
print len(vector)
 
         